#include "../include/RechercheTabou.hpp"


RechercheTabou::RechercheTabou(std::vector<Formation>& formations, std::vector<Interface>& interfaces, std::vector<Centre>& centres, 
                       int dureeTabou, int nbIterationAvantDiversification, int dureeRecherche)
{
    this->m_formations = formations;
    this->m_interfaces = interfaces;
    this->m_centres = centres;
    this->m_dureeTabou = dureeTabou;
    this->m_nbIterationAvantDiversification = nbIterationAvantDiversification;
    this->m_dureeRecherche = dureeRecherche;
    this->m_meilleureFitness = 999999999.0;
    this->calculerDistances();
    
    

}

RechercheTabou::~RechercheTabou()
{

}

/**
 * Recherche tabou
 * 
 */
void RechercheTabou::rechercher() {
   //on cherche une solution initiale
   this->firstFit();
   std::cout << "premiere solution :" << std::endl;
   this->afficherMeilleurSolution();
   std::cout << "----" << std::endl;
   //bool descente = false;
   int nbIterationsSansAmelioration = 0;
   float fitnessAvant, fitnessApres = 0.0;
   int meilleureI, meilleureJ;
   this->m_iterationActuelle = 0;
   while (this->m_iterationActuelle < 280)
   {
      
       while(!this->voisinage(meilleureI, meilleureJ)) {
           this->firstFit();
       }
       
       this->inverser(meilleureI, meilleureJ);
       this->evaluerSolutionActuelle();
       if(this->m_meilleureFitness > this->m_fitnessActuelle) this->nouvelleMeilleureSolution();
       

       fitnessAvant = fitnessApres;
       fitnessApres = this->m_fitnessActuelle;
       //std::cout << "avant " << fitnessAvant << "après " << fitnessApres << std::endl;
       //diversification
       if (fitnessApres >= fitnessAvant)
       {
            nbIterationsSansAmelioration++;
       } else {
            nbIterationsSansAmelioration = 0;
       }
       if (nbIterationsSansAmelioration == this->m_nbIterationAvantDiversification)
       {
           this->firstFit();
       }
       this->m_iterationActuelle++;
        

   }
   std::cout << "meilleure solution trouve:" << std::endl;
   this->afficherMeilleurSolution();
}

/**
 * Cherche les deux meilleures attributions à inverser dans la solution actuelle.
 * @return true si une permutation à été trouvé, false sinon.
 */
bool RechercheTabou::voisinage(int& index1, int& index2) {
    //choix premier index aléatoire
    int indexRandom = Random::aleatoire(NBR_FORMATIONS);
    float meilleureFitness = 999999.0;
    float fitness;
    int meilleurVoisin = -1;
    //pour chaque attribution
    for (int j = 0; j < NBR_FORMATION; j++)
    {
        //si elles sont inversibles
        if(j != indexRandom && this->estInversible(indexRandom, j)) {
            //on regarde si l'inversion est meilleures que les précédentes
            this->inverser(indexRandom, j);
            fitness = this->m_fitnessActuelle;
            this->evaluerSolutionActuelle();
            //si oui on la marque comme meilleure inversion
            if(this->m_fitnessActuelle < meilleureFitness) {
                meilleureFitness = fitness;
                meilleurVoisin = j;
            }
            //on remet la solution actuelle comme elle était avant
            this->inverser(indexRandom, j);
            this->m_fitnessActuelle = fitness;
        }
    }
    if(meilleurVoisin != -1) {
        index1 = indexRandom;
        index2 = meilleurVoisin;
        return true;
    }
    return false;
}

/**
 * Vérifie si les deux attributions peuvent être inversés.
 * @return true si les deux attributions sont inversibles, false sinon.
 */
bool RechercheTabou::estInversible(int index1, int index2) {

    //si la permutation est dans la liste tabou
    if(this->estTabou(index1, index2)) return false;

    Formation* formation1 = &this->m_formations[index1];
    Interface* interface1 = this->getInterfaceById(this->m_solutionActuelle[formation1->getId()]);
    Formation* formation2 = &this->m_formations[index2];
    Interface* interface2 = this->getInterfaceById(this->m_solutionActuelle[formation2->getId()]);

    //si les interfaces n'ont pas les bonnes competances pour permutter
    if(!interface1->aCompetance(formation2->getCompetance()) && !interface2->aCompetance(formation1->getCompetance())) {
        return false;
    }

    int duree1 = formation1->getHeureFin() - formation1->getHeureDebut();
    int duree2 = formation2->getHeureFin() - formation2->getHeureDebut();

    int nouvellesHeuresJourInterface1 = interface1->getNombreHeuresParJour(formation2->getJour()) + duree2;
    int nouvellesHeuresJourInterface2 = interface2->getNombreHeuresParJour(formation1->getJour()) + duree1;

    int nouvellesHeuresParSemaineInterface1 = 
            interface1->getNombreHeuresTotales() - interface1->getNombreHeuresParJour(formation2->getJour()) + nouvellesHeuresJourInterface1 - duree1;
    int nouvellesHeuresParSemaineInterface2 = 
            interface2->getNombreHeuresTotales() - interface2->getNombreHeuresParJour(formation1->getJour()) + nouvellesHeuresJourInterface2 - duree2;

    bool enMemeTemps = false;

    //si les deux formations sont le même jour
    if(formation1->getJour() == formation2->getJour()) {
        nouvellesHeuresJourInterface1 -= duree1;
        nouvellesHeuresJourInterface2 -= duree2; 
        int i= formation1->getHeureDebut();
        //on regarde si les formations se chevauchent
        while (i <= formation1->getHeureFin() && !enMemeTemps)
        {
            if(i <= formation2->getHeureFin() && i >= formation2->getHeureDebut()) enMemeTemps = true;
            i++;
        }

    }

    //si les interfaces sont déjà occupé par une formation autre que celle que l'ont veut inverser
    if(!enMemeTemps && 
        (interface1->estOccuppe(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin())
        || interface2->estOccuppe(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin()))) {
                
            return false;
    }

    // si les heures de travail ne sont pas dépassées
    if(nouvellesHeuresJourInterface1 > 8 || nouvellesHeuresParSemaineInterface1 > 35
           || nouvellesHeuresJourInterface2 > 8 || nouvellesHeuresParSemaineInterface2 > 35) {

            return false;
    }

    return true;
}

/**
 * Inverse deux attributions d'une solution et met à jour les heures de chaque interface
 *
 */
void RechercheTabou::inverser(int index1, int index2) {

    Formation* formation1 = &this->m_formations[index1];
    Interface* interface1 = this->getInterfaceById(this->m_solutionActuelle[formation1->getId()]);
    Formation* formation2 = &this->m_formations[index2];
    Interface* interface2 = this->getInterfaceById(this->m_solutionActuelle[formation2->getId()]);

    //on supprime les heures de l'ancienne formation
    interface1->supprimerOccupation(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin());
    //on ajoute les heures de la nouvelle formation
    interface1->ajouterOccupation(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin());
    //on supprime les heures de l'ancienne formation
    interface2->supprimerOccupation(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin());
    //on ajoute les heures de la nouvelle formation
    interface2->ajouterOccupation(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin());

    //on inverse les affections dans la solution actuelle
    int temp = this->m_solutionActuelle[index1];
    this->m_solutionActuelle[index1] = this->m_solutionActuelle[index2];
    this->m_solutionActuelle[index2] = temp;

    //on met à jour la liste tabou
    this->miseAJourListeTabou(index1, index2);

}

bool RechercheTabou::estTabou(int index1, int index2) {
    return (
        this->m_listeTabou[index1][index2] > this->m_iterationActuelle ||
        this->m_listeTabou[index2][index1] > this->m_iterationActuelle
    );
}

void RechercheTabou::miseAJourListeTabou(int index1, int index2) {
    this->m_listeTabou[index1][index2] = this->m_iterationActuelle + this->m_dureeTabou;
    this->m_listeTabou[index2][index1] = this->m_iterationActuelle + this->m_dureeTabou;
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

    for (size_t i = 0; i < this->m_interfaces.size(); i++)
    {
        this->m_interfaces[i].viderOccupations();
    }
    

    for(int i = 0; i < NBR_FORMATION; i++) {
        j = 0;
        trouve = false;
        formation = &this->m_formations[i];
        duree = formation->getHeureFin() - formation->getHeureDebut(); //duree de la formation
        id = -1;
        while(j<NBR_INTERFACES && !trouve) { // tant qu'on trouve pas l'interface qui convient
            interface = &this->m_interfaces[j]; 
            if (interface->aCompetance(formation->getCompetance()) // l'interface a la bonne compétance
                && (interface->getNombreHeuresParJour(formation->getJour()) + duree) <= 8 //l'interface a moins de 8h le jour de la formation
                && (interface->getNombreHeuresTotales() + duree) <= 35 // l'interface à moins de 35h au total
                && !interface->estOccuppe(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()) //l'interface n'est pas occupée
            ) {

                trouve = true; // interface trouvee
                id = interface->getId();
            }
            j++;
        }
        
        this->m_solutionActuelle[formation->getId()] = id;
        if(id != -1) {
            //on ajoute les heures à l'interface
            interface->ajouterOccupation(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()); 
        }
        Random::melangerAleatoirementInterfaces(this->m_interfaces); //on mélange le vector des interfaces

        //si l'id est égale à -1 cela signifie qu'aucune formation n'a été trouvé
        //et donc que la solution n'est pas valide
    }
    this->evaluerSolutionActuelle();
    if(this->m_meilleureFitness > this->m_fitnessActuelle) this->nouvelleMeilleureSolution();
    
}


/**
 * Calcul des distances
 * 
 */
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

/**
 * Affiche la meilleure solution dans le terminal 
 * 
 */
void RechercheTabou::afficherMeilleurSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        std::cout << "formation  " << i << "-> interface " << this->m_meilleureSolution[i] << std::endl;
    }
    std::cout << "fitness =  " << this->m_meilleureFitness << std::endl;
}

/**
 * Evaluation de la solution actuelle
 * 
 */
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
        // on ajoute la distance entre le dernier centre et l'actuel
        distancesInterface[interface->getId()] += getDistanceEntreCentres(dernierCentre[interface->getId()][formation->getJour()], formation->getCentre());
        //mise à jour du dernier centre visité
        dernierCentre[interface->getId()][formation->getJour()] = formation->getCentre();
        //si c'est la dernière formation pour l'interface
        if(interface->estDerniereDeLaJournee(formation->getJour(), formation->getHeureFin())) {
            //on ajoute la distance entre le dernier centre et le centre SESSAD
            distancesInterface[interface->getId()] += getDistanceEntreCentres(formation->getCentre(), 0);
            dernierCentre[interface->getId()][formation->getJour()] = 0;
        }
        //si l'interface n'a pas la bonne spécialité
        if(!interface->aSpecialite(formation->getSpecialite())) {
            //incrémentation de la pénalité
            penalite++;
        }
    }
    float moyenneDeplacement = this->calculerMoyenne(distancesInterface, NBR_INTERFACES);
    float ecartTypeDeplacement = this->calculerEcartType(distancesInterface, NBR_INTERFACES);
    //objectif
    this->m_fitnessActuelle =  0.5 * (moyenneDeplacement + ecartTypeDeplacement) + 0.5 * this->m_facteurCorrelation * penalite;
}

/**
 * Calcul de la moyenne
 * 
 */
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

/**
 * Calcul de l'écart-type 
 * 
 */
float RechercheTabou::calculerEcartType(float* donnees, int taille)
{
    int moyenne, ecartType = 0.0;

    moyenne = calculerMoyenne(donnees, taille);

    for(int i = 0; i < taille; i++){
        ecartType += powf(donnees[i] - moyenne, 2);
    }

    return sqrt(ecartType / taille);
}


/**
 * La solution actuelle devient la meilleure solution
 * 
 */
void RechercheTabou::nouvelleMeilleureSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        this->m_meilleureSolution[i] = this->m_solutionActuelle[i];
    }
    this->m_meilleureFitness = this->m_fitnessActuelle;
}

float RechercheTabou::getDistanceEntreCentres(int id1, int id2) {
    return this->m_distances[id1][id2];
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


