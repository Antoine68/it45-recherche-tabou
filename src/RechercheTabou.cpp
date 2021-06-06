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
    this->premiereSolution();

}

RechercheTabou::~RechercheTabou()
{

}

Solution* RechercheTabou::rechercher() {
    return this->m_meilleureSolution;
}

void RechercheTabou::voisinage() {

}


void RechercheTabou::premiereSolution() {

    bool trouve = false;
    int j = 0;

    std::vector<Interface> interfaces = this->m_interfaces;
    
    Formation* formation;
    Interface* interface;

    bool doubleCompetance = false;
    Interface* ptrDoubleCompetance;

    int duree = 0;

    for(int i = 0; i < NBR_FORMATION; i++) {

        j = 0;
        trouve = false;
        doubleCompetance = false;
        formation = &this->m_formations[i];
        duree = formation->getHeureFin() - formation->getHeureDebut();

        while(j<NBR_INTERFACES && !trouve) {
            interface = &interfaces[j];
            if (interface->aCompetance(formation->getCompetance()) 
                && (interface->getNombreHeuresParJour(formation->getJour()) + duree) <= 8
                && (interface->getNombreHeuresTotales() + duree) <= 35
                && !interface->estOccuppe(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()) 
            ) {

                if(interface->aToutesCompetances()) {
                    doubleCompetance = true;
                    ptrDoubleCompetance = interface;
                } else {
                    trouve = true;
                }
            }
            j++;
        }
        if(j == NBR_INTERFACES-1 && doubleCompetance) interface = ptrDoubleCompetance;
        this->m_solutionActuelle->affecter(formation->getId(), interface->getId());
        interface->ajouterOccupation(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin());
        Random::melangerAleatoirementInterfaces(interfaces);
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



