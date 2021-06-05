#include "../include/Interface.hpp"


Interface::Interface(int id, int competances[2], int specialites[NBR_SPECIALITES])
{
    this->m_id = id;
    for(int i=0; i<2; i++) {
        this->m_competances[i] = competances[i];
    }
    for(int i=0; i<NBR_SPECIALITES; i++) {
        this->m_competances[i] = specialites[i];
    }

}

Interface::~Interface()
{

}

int Interface::getId() {
    return this->m_id;
}

bool Interface::aCompetance(int competance) {
    return this->m_competances[competance] == 1;
}

bool Interface::aSpecialite(int specialite) {
    return this->m_specialites[specialite] == 1;
}
