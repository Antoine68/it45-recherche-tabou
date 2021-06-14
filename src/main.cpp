#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <thread>
#include "../include/Donnee.hpp"
#include "../include/Random.hpp"
#include "../include/RechercheTabou.hpp"
#include "../include/Formation.hpp"
#include "../include/Interface.hpp"
#include "../include/Centre.hpp"


#ifdef _WIN32 
#include <Windows.h>
#elif  _WIN64
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void chronometre(int secondes, RechercheTabou* tabou) {

    cout << endl << "-------début chronometre " << secondes << "s-------" << endl;

    #ifdef _WIN32
    Sleep(secondes*1000);
    #elif _WIN64 
    Sleep(secondes*1000);
    #else
    sleep(secondes);
    #endif

    tabou->arreterRecherche();

    return;

}


int main(int argc, char **argv)

{

    Random::randomize();

    int temps;
    if (argc < 2)
    {
        cout << "saisir le temps de calcul en secondes :" << endl;
        scanf("%d", &temps);
    } else {
        temps = atoi(argv[1]);
    }
    
    
    std::vector<Formation> formations;
    std::vector<Interface> interfaces;
    std::vector<Centre> centres;
    
    //création des interfaces
    for (size_t i = 0; i < NBR_INTERFACES; i++)
    {
        interfaces.push_back(*(new Interface(i,competences_interfaces[i], specialite_interfaces[i])));
    }

    //création des centres
    //le centre avec l'id 0 sera le centre SESSAD
    for (size_t j = 0; j < NBR_SPECIALITES+1; j++)
    {
        centres.push_back(*(new Centre(j, coord[j], j-1)));
    }

    //création des formations
    //on fait id du centre + 1 pour ne pas les attribuer au centre SESSAD
    for (size_t k = 0; k< NBR_FORMATION; k++) {
        int* f = formation[k];
        formations.push_back(*(new Formation(f[0], f[1], f[2], f[3], f[4], f[5], f[1]+1)));
    }

    //parametre durée tabou
    int dureeTabou = NBR_FORMATIONS/5;

    //paramètre iteration avant diversification
    int iterationAvantDiversification =  250 + (500/temps);

    //création recherche tabou
    RechercheTabou tabou(formations, interfaces, centres, dureeTabou, iterationAvantDiversification);

    //création et démarrage du thread chrono qui va arreter la recherche quand le 
    //temps imparti s'est écoulé
    std::thread chrono(chronometre, temps, &tabou);
    chrono.detach();

    //on démarre la recherche
    tabou.rechercher();


    return 0;
}
