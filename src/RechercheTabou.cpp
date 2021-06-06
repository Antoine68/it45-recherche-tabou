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
    this->m_solutionActuelle = new Solution();

    this->calculerDistances();
    this->firstFit();

}

RechercheTabou::~RechercheTabou()
{

}

Solution* RechercheTabou::rechercher() {
    return this->m_meilleureSolution;
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
 * -> car elles peuvent être prise pour une compétance alors qu'il
 * n'y a pas assez d'interface pour l'autre compétance
 * -> possibilité de solution non valide
 */
void RechercheTabou::firstFit() {

    bool trouve = false; //interface trouvee
    int j = 0;

    std::vector<Interface> interfaces = this->m_interfaces; //copie du vecteur des interfaces
    
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
            interface = &interfaces[j];
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
        this->m_solutionActuelle->affecter(formation->getId(), id);
        if(id != -1) {
            interface->ajouterOccupation(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin());
        }
        Random::melangerAleatoirementInterfaces(interfaces);

        //si l'id est égale à -1 cela signifie qu'aucune formation n'a été trouvé
        //et donc que la solution n'est pas valide
    }
    this->m_solutionActuelle->afficher();
    
}


void RechercheTabou::calculerDistances() {
    Centre* centre1;
    Centre* centre2;
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
        }
    }
    
    
}

bool RechercheTabou::deplacementEstTabou(int id1, int id2) 
{
    return false;
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



