#include "../include/RechercheTabou.hpp"


RechercheTabou::RechercheTabou(std::vector<Formation>& formations, std::vector<Interface>& interfaces, std::vector<Centre>& centres, 
                       int dureeTabou, int longueurTabou, int nbIterationAvantDiversification, int dureeRecherche)
{
    this->m_formations = formations;
    this->m_interfaces = interfaces;
    this->m_centres = centres;
    this->m_dureeTabou = dureeTabou;
    this->m_longueurTabou = longueurTabou;
    this->m_nbIterationAvantDiversification = nbIterationAvantDiversification;
    this->m_dureeRecherche = dureeRecherche;
    this->m_meilleureFitness = 999999999.0;
    this->calculerDistances();
    this->firstFit();

}

RechercheTabou::~RechercheTabou()
{

}

void RechercheTabou::rechercher() {
   this->afficherMeilleurSolution();
}

void RechercheTabou::voisinage() {

}

/**
 * Algorithme glouton first-fit
 * 
 * Pour chaque formation on attribut la première interface
 * qui remplit toutes les contraintes obligatoires.
 * 
 * Puis on mélange le tableau des interfaces pour ne pas
 * toujours parcourrir le tableau dans le même ordre.
 * 
 * Problématique : les interfaces ayant les deux compétances
 * -> car elles peuvent être choisis pour une compétance alors qu'il
 * n'y a pas assez d'interfaces pour l'autre compétance.
 * -> possibilité de solution non valide.
 */
void RechercheTabou::firstFit() {

    bool trouve = false; //interface trouvee
    int j = 0;
    
    Formation* formation; //pointeur sur la formation actuelle
    Interface* interface; //pointeur sur l'interface actuelle

    int duree = 0; //duree de la formation

    int id = -1;//id interface trouvee


    for(int i = 0; i < NBR_FORMATION; i++) {
        j = 0;
        trouve = false;
        formation = &this->m_formations[i];
        duree = formation->getHeureFin() - formation->getHeureDebut();
        id = -1;
        while(j<NBR_INTERFACES && !trouve) {
            interface = &this->m_interfaces[j];
            if (interface->aCompetance(formation->getCompetance()) 
                && (interface->getNombreHeuresParJour(formation->getJour()) + duree) <= 8
                && (interface->getNombreHeuresTotales() + duree) <= 35
                && !interface->estOccuppe(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()) 
            ) {

                trouve = true;
                id = interface->getId();
            }
            j++;
        }
        
        this->m_solutionActuelle[formation->getId()] = id;
        
        if(id != -1) {
            interface->ajouterOccupation(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin());
        }
        Random::melangerAleatoirementInterfaces(this->m_interfaces);

        //si l'id est égale à -1 cela signifie qu'aucune formation n'a été trouvé
        //et donc que la solution n'est pas valide
    }
    
    this->evaluerSolutionActuelle();
    if(this->m_meilleureFitness > this->m_fitnessActuelle) this->nouvelleMeilleureSolution();
}


void RechercheTabou::calculerDistances() {
    Centre* centre1;
    Centre* centre2;
    float distanceTotal = 0.0;
    for (int i = 0; i < NBR_CENTRES_FORMATION+1; i++)
    {
        for (int j = 0; j < NBR_CENTRES_FORMATION+1; j++) {
            if (i == j) {
                this->m_distances[i][j] = 0;
            } else {
                centre1 = this->getCentreById(i);
                centre2 = this->getCentreById(j);
                this->m_distances[i][j] = 
                    sqrtf(powf((centre2->getCoordonneeX() - centre1->getCoordonneeX()),2) 
                        + powf((centre2->getCoordonneeY() - centre1->getCoordonneeY()),2));
               
            }
            distanceTotal += this->m_distances[i][j];
        }
    }
    this->m_facteurCorrelation = distanceTotal/NBR_CENTRES_FORMATION;
    
}


bool RechercheTabou::deplacementEstTabou(int id1, int id2) 
{
    return false;
}



void RechercheTabou::afficherMeilleurSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        std::cout << "formation  " << i << "-> interface " << this->m_meilleureSolution[i] << std::endl;
    }
    std::cout << "fitness =  " << this->m_meilleureFitness << std::endl;
}

void RechercheTabou::evaluerSolutionActuelle() {
    float distancesInterface[NBR_INTERFACES] = {0.0};
    int dernierCentre[NBR_INTERFACES][7] = {0};
    float penalite = 0;
    Formation* formation;
    Interface* interface;
    for (int i = 0; i < NBR_FORMATION; i++)
    {
        formation = &this->m_formations[i];
        interface = this->getInterfaceById(this->m_solutionActuelle[i]);
        distancesInterface[interface->getId()] += getDistanceEntreCentres(dernierCentre[interface->getId()][formation->getJour()], formation->getCentre());
        dernierCentre[interface->getId()][formation->getJour()] = formation->getCentre();
        if(interface->estDerniereDeLaJournee(formation->getJour(), formation->getHeureFin())) {
            distancesInterface[interface->getId()] += getDistanceEntreCentres(formation->getCentre(), 0);
            dernierCentre[interface->getId()][formation->getJour()] = 0;
        }
        
        if(!interface->aSpecialite(formation->getSpecialite())) {
            penalite++;
        }
    }
    float moyenneDeplacement = this->calculerMoyenne(distancesInterface, NBR_INTERFACES);
    float ecartTypeDeplacement = this->calculerEcartType(distancesInterface, NBR_INTERFACES);
    this->m_fitnessActuelle =  0.5 * (moyenneDeplacement + ecartTypeDeplacement) + 0.5 * this->m_facteurCorrelation * penalite;
}

float RechercheTabou::calculerMoyenne(float* donnees, int taille)
{
    int somme = 0, moyenne;

    int i;

    for(i = 0; i < taille; i++){
        somme += donnees[i];
    }

    moyenne = somme/taille;
    return moyenne;
}


float RechercheTabou::calculerEcartType(float* donnees, int taille)
{
    int moyenne, ecartType = 0.0;

    moyenne = calculerMoyenne(donnees, taille);

    for(int i = 0; i < taille; i++){
        ecartType += powf(donnees[i] - moyenne, 2);
    }

    return sqrt(ecartType / taille);
}

float RechercheTabou::getDistanceEntreCentres(int id1, int id2) {
    return this->m_distances[id1][id2];
}

void RechercheTabou::nouvelleMeilleureSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        this->m_meilleureSolution[i] = this->m_solutionActuelle[i];
    }
    this->m_meilleureFitness = this->m_fitnessActuelle;
}


Formation* RechercheTabou::getFormationById(int id) 
{
    for (size_t i = 0; i < this->m_formations.size(); i++)
    {
        if (this->m_formations[i].getId() == id) return &this->m_formations[i];
    }
    return nullptr;    
}


int RechercheTabou::getFormationIndexById(int id) 
{
    
    for (size_t i = 0; i < this->m_formations.size(); i++)
    {
        if (this->m_formations[i].getId() == id) return i;
    }
    return -1;
}


Interface* RechercheTabou::getInterfaceById(int id) 
{
    for (size_t i = 0; i < this->m_interfaces.size(); i++)
    {
        if (this->m_interfaces[i].getId() == id) return &this->m_interfaces[i];
    }
    return nullptr;
}

int RechercheTabou::getInterfaceIndexById(int id) 
{
    for (size_t i = 0; i < this->m_interfaces.size(); i++)
    {
        if (this->m_interfaces[i].getId() == id) return i;
    }
    return -1;
}

Centre* RechercheTabou::getCentreById(int id) 
{
    for (size_t i = 0; i < this->m_centres.size(); i++)
    {
        if (this->m_centres[i].getId() == id) return &this->m_centres[i];
    }
    return nullptr;
}

int RechercheTabou::getCentreIndexById(int id) 
{
    for (size_t i = 0; i < this->m_centres.size(); i++)
    {
        if (this->m_centres[i].getId() == id) return i;
    }
    return -1;
}


