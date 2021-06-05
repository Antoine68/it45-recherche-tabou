#include "../include/Centre.hpp"


Centre::Centre(int id, float coordonnees[2], int specialite)
{
    this->m_id = id;
    memcpy(&coordonnees, this->m_coordonnees, 2);
    this->m_specialite = specialite;
    
}

Centre::~Centre()
{

}

int Centre::getId() {
    return this->m_id;
}

float* Centre::getCoordonnees() {
    return this->m_coordonnees;
}

int Centre::getSpecialite() {
    return this->m_specialite;
}


