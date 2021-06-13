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

/**
 * Supprimer toutes les occupations de l'interface 
 * 
 */
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

/**
 * 
 * @return true si l'interface a les deux compétances (codage et signe)
 */
bool Interface::aToutesCompetances() {
    for (int i = 0; i < 2; i++)
    {
        if(this->m_competances[i] == 0) return false;
    }
    return true;    
}

/**
 * Verifie si l'interface est occupé au moment passé en paramètre
 * @return true si elle est occupé, false sinon
 */
bool Interface::estOccupe(int jour, int heureDebut, int heureFin) {
    //std::cout << heureDebut << "-" << heureFin << ":";
    for (int i = heureDebut; i <= heureFin; i++)
    {
        //std::cout << i << " ";
        if(std::find(this->m_occupations[jour].begin(), this->m_occupations[jour].end(), i) != this->m_occupations[jour].end()) return true;
    }
    //std::cout << std::endl;
    return false;
}

/**
 * Ajoute l'intervalle d'heure entre heureDebut (inclus)
 * et heureFin (exclus) à l'occupation du jour passé en paramètre
 * 
 */
void Interface::ajouterOccupation(int jour, int heureDebut, int heureFin) {
    for (int i = heureDebut; i < heureFin; i++)
    {
        this->m_occupations[jour].push_back(i);
    }
}

/**
 * Supprime l'intervalle d'heure entre heureDebut (inclus)
 * et heureFin (exclus) à l'occupation du jour passé en paramètre
 * 
 */
void Interface::supprimerOccupation(int jour, int heureDebut, int heureFin) {
    for (int i = heureDebut; i < heureFin; i++)
    {
        this->m_occupations[jour].erase(std::remove(this->m_occupations[jour].begin(), this->m_occupations[jour].end(), i), this->m_occupations[jour].end());   
    }
}

/**
 * 
 * @return le nombre d'heures du jour passé en paramètre
 */
int Interface::getNombreHeuresParJour(int jour) {
    return this->m_occupations[jour].size();
}

/**
 * 
 * @return le nombre d'heures de la semaine de l'interface
 */
int Interface::getNombreHeuresTotales() {
    int total = 0;
    for (int i = 0; i < 7; i++)
    {
        total += this->getNombreHeuresParJour(i);
    }
    return total;
    
}

/**
 * Verifie si l'heure de fin passée en paramètre est la dernière de 
 * la journée passé en paramètre
 * @return true si c'est la dernière, false sinon
 */
bool Interface::estDerniereDeLaJournee(int jour, int heureFin) {
    int derniereHeure = 0;
    for (size_t i = 0; i < this->m_occupations[jour].size(); i++)
    {
        if(derniereHeure < this->m_occupations[jour][i]) derniereHeure = this->m_occupations[jour][i];
    }
    return derniereHeure == heureFin-1;
}

/**
 * Verifie si l'interface à une pause entre 12h et 14h
 * @return true s'il a une pause, false sinon
 */
bool Interface::aPauseMidi(int jour) {
    for (int i = 12; i < 15; i++)
    {
        if (!this->estOccupe(jour, i, i)) return true;        
    }
    std::cout << "la" << std::endl;
    return false;
}