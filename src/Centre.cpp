#include "../include/Centre.hpp"


Centre::Centre(int id, float coordonnees[2], int specialite)
{
   
    this->m_id = id;
    this->m_specialite = specialite;
    for(int i=0; i<2; i++) {
        this->m_coordonnees[i] = coordonnees[i];
    }
    
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

float Centre::getCoordonneeX() {
    return this->m_coordonnees[0];
}

float Centre::getCoordonneeY() {
    return this->m_coordonnees[1];
}

