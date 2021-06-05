//
// Define guards
#ifndef RECHERCHETABOU_H
#define RECHERCHETABOU_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Formation.hpp"
#include "Interface.hpp"
#include "Solution.hpp"
#include "Centre.hpp"


class RechercheTabou
{
    public:
        RechercheTabou(std::vector<Formation>& formations, std::vector<Interface>& interfaces, std::vector<Centre>& centres, 
                       int dureeTabou, int longueurTabou, int nbIterationAvantDiversification, int dureeRecherche);
        virtual ~RechercheTabou();
        Solution& rechercher();


    protected:

    private:
       std::vector<Formation> m_formations;
       std::vector<Interface> m_interfaces;
       std::vector<Centre> m_centres;
       
       int m_dureeTabou;
       int m_dureeRecherche;
       int m_longueurTabou;
       int m_nbIterationAvantDiversification;
       int m_iterationActuelle;
       Solution* m_solutionActuelle;
       Solution* m_meilleureSolution;
       int** distances;

       Formation* getFormationById(int id);
       int getFormationIndexById(int id);
       Interface* getInterfaceById(int id);
       int getInterfaceIndexById(int id);
       void calculerDistances();
       int getDistanceEntreCentres(int id1, int id2);
       Centre* getFormationCentre(int idFormation);
       bool deplacementEstTabou(int id1, int id2);
       
       void voisinage();

};

#endif // RECHERCHETABOU_H
