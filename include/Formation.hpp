//
// Define guards
#ifndef FORMATION_H
#define FORMATION_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Centre.hpp"


class Formation
{
    public:
        Formation(int id, int competance, int specialite, int jour, int heureDebut, int heureFin, int centre);
        virtual ~Formation();
        int getId();
        int getCompetance();
        int getJour();
        int getHeureDebut();
        int getHeureFin();
        int getSpecialite();
        int getCentre();
        
 
    protected:

    private:
        int m_id;
        int m_jour;
        int m_heureDebut;
        int m_heureFin;
        int m_competance;
        int m_specialite;
        int m_centre;
        
        
       
};

#endif // FORMATION_H
