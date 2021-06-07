//
// Define guards
#ifndef RECHERCHETABOU_H
#define RECHERCHETABOU_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 
#include "Formation.hpp"
#include "Interface.hpp"
#include "Centre.hpp"
#include "Donnee.hpp"
#include "Random.hpp"


class RechercheTabou
{
    public:
        RechercheTabou(std::vector<Formation>& formations, std::vector<Interface>& interfaces, std::vector<Centre>& centres, 
                       int dureeTabou, int longueurTabou, int nbIterationAvantDiversification, int dureeRecherche);
        virtual ~RechercheTabou();
        void rechercher();


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
       float m_distances[NBR_CENTRES_FORMATION+1][NBR_CENTRES_FORMATION+1];
       float m_facteurCorrelation;

       int m_meilleureSolution[NBR_FORMATIONS] = {-1};
       int m_solutionActuelle[NBR_FORMATIONS] = {-1};
       float m_meilleureFitness;
       float m_fitnessActuelle;

       int m_listeTabou[NBR_FORMATION][NBR_FORMATION] = {0};

       Formation* getFormationById(int id);
       int getFormationIndexById(int id);
       Interface* getInterfaceById(int id);
       int getInterfaceIndexById(int id);
       Centre* getCentreById(int id);
       int getCentreIndexById(int id);
       void calculerDistances();
       float getDistanceEntreCentres(int id1, int id2);
       Centre* getFormationCentre(int idFormation);
       bool deplacementEstTabou(int id1, int id2);
       float calculerMoyenne(float* donnees, int taille);
       float calculerEcartType(float* donnees, int taille);
       
       
       void firstFit();
       bool voisinage(int& index1, int& index2);
       bool estTabou(int index1, int index2);
       void miseAJourListeTabou(int index1, int index2);
       void inverser(int index1, int index2);
       bool estInversible(int index1, int index2);

       //solution
       void evaluerSolutionActuelle();
       void nouvelleMeilleureSolution();
       void afficherMeilleurSolution();
       


};

#endif // RECHERCHETABOU_H
