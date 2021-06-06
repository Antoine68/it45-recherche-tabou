#include "../include/Formation.hpp"


Formation::Formation(int id, int specialite, int competance,  int jour, int heureDebut, int heureFin, int centre)
{
    this->m_id = id;
    this->m_competance = competance;
    this->m_specialite = specialite;
    this->m_jour = jour;
    this->m_heureDebut = heureDebut;
    this->m_heureFin = heureFin;
    this->m_centre = centre;
    
}

Formation::~Formation()
{

}

int Formation::getId() {
    return this->m_id;
}

int Formation::getCompetance() {
    return this->m_competance;
}

int Formation::getSpecialite() {
    return this->m_specialite;
}

int Formation::getJour() {
    return this->m_jour;
}

int Formation::getHeureDebut() {
    return this->m_heureDebut;
}

int Formation::getHeureFin() {
    return this->m_heureFin;
}

int Formation::getCentre() {
    return this->m_centre;
}


