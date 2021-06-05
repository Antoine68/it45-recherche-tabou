#include "../include/Interface.hpp"


Interface::Interface(int id, int competances[2], int specialites[NBR_SPECIALITES])
{
    this->m_id = id;
    memcpy(&competances, this->m_competances, 2);
    memcpy(&specialites, this->m_specialites, NBR_SPECIALITES*sizeof(int));

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
