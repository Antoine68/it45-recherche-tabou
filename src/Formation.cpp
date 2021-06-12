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

bool Formation::operator<(const Formation& formation) const {
    if(this->m_jour != formation.m_jour) {
        return this->m_jour < formation.m_jour;
    }
    if(this->m_heureDebut != formation.m_heureDebut) {
        return this->m_heureDebut < formation.m_heureDebut;
    }
    if(this->m_heureFin != formation.m_heureFin) {
        return this->m_heureFin < formation.m_heureFin;
    }
    return false;
}


