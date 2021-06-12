#include "../include/Interface.hpp"


Interface::Interface(int id, int competances[2], int specialites[NBR_SPECIALITES])
{
    this->m_id = id;
    for(int i=0; i<2; i++) {
        this->m_competances[i] = competances[i];
    }
    for(int i=0; i<NBR_SPECIALITES; i++) {
        this->m_specialites[i] = specialites[i];
    }
    for (int i = 0; i < 7; i++)
    {
        this->m_occupations[i] = std::vector<int>();
    }

}

Interface::~Interface()
{

}

void Interface::viderOccupations() {
    for (int i = 0; i <= 7; i++)
    {
        this->m_occupations[i].clear();
    }
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

bool Interface::aToutesCompetances() {
    for (int i = 0; i < 2; i++)
    {
        if(this->m_competances[i] == 0) return false;
    }
    return true;    
}

bool Interface::estOccuppe(int jour, int heureDebut, int heureFin) {
    //std::cout << heureDebut << "-" << heureFin << ":";
    for (int i = heureDebut; i <= heureFin; i++)
    {
        //std::cout << i << " ";
        if(std::find(this->m_occupations[jour].begin(), this->m_occupations[jour].end(), i) != this->m_occupations[jour].end()) return true;
    }
    //std::cout << std::endl;
    return false;
}

void Interface::ajouterOccupation(int jour, int heureDebut, int heureFin) {
    for (int i = heureDebut; i < heureFin; i++)
    {
        this->m_occupations[jour].push_back(i);
    }
}

void Interface::supprimerOccupation(int jour, int heureDebut, int heureFin) {
    for (int i = heureDebut; i < heureFin; i++)
    {
        this->m_occupations[jour].erase(std::remove(this->m_occupations[jour].begin(), this->m_occupations[jour].end(), i), this->m_occupations[jour].end());   
    }
}

int Interface::getNombreHeuresParJour(int jour) {
    return this->m_occupations[jour].size();
}

int Interface::getNombreHeuresTotales() {
    int total = 0;
    for (int i = 0; i < 7; i++)
    {
        total += this->getNombreHeuresParJour(i);
    }
    return total;
    
}

bool Interface::estDerniereDeLaJournee(int jour, int heureFin) {
    int derniereHeure = 0;
    for (size_t i = 0; i < this->m_occupations[jour].size(); i++)
    {
        if(derniereHeure < this->m_occupations[jour][i]) derniereHeure = this->m_occupations[jour][i];
    }
    return derniereHeure == heureFin-1;
}


bool Interface::aPauseMidi(int jour) {
    for (int i = 12; i < 15; i++)
    {
        if (!this->estOccuppe(jour, i, i)) return true;        
    }
    std::cout << "la" << std::endl;
    return false;
}