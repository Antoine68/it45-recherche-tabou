//
// Define guards
#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
#include "Donnee.hpp"
#include "Formation.hpp"

class Interface
{
    public:
        Interface(int id, int competances[2], int specialites[NBR_SPECIALITES]);
        virtual ~Interface();
        int getId();
        bool aCompetance(int competance);
        bool aSpecialite(int specialite);
        bool aToutesCompetances();
        bool estOccuppe(int jour, int heureDebut, int heureFin);
        void ajouterOccupation(int jour, int heureDebut, int heureFin);
        void supprimerOccupation(int jour, int heureDebut, int heureFin);
        int getNombreHeuresParJour(int jour);
        bool estDerniereDeLaJournee(int jour, int heureFin);
        bool estPremiereDeLaJournee(int jour, int heureDebut);
        int getNombreHeuresTotales();
        void viderOccupations();
        bool aPauseMidi(int jour);
        

    protected:

    private:
       int m_id;
       int m_competances[2];
       int m_specialites[NBR_SPECIALITES];
       std::map<int, std::vector<int>> m_occupations;
};

#endif // INTERFACE_H
