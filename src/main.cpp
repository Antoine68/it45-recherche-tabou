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

    #ifdef _WIN32  //pour windows (pas les meme bibliotheque et fonctions a utiliser)
    Sleep(secondes*1000);
    #elif _WIN64  //pour windows (pas les meme bibliotheque et fonctions a utiliser)
    Sleep(secondes*1000);
    #else //pour le reste
    sleep(secondes);
    #endif

    cout << "-------fin temps-------" << endl;
    cout << "meilleure solution trouve:" << endl;

    tabou->afficherMeilleurSolution();

    exit(0);

}


int main(int argc, char **argv)

{

    Random::randomize();

    int temps;
    cout << "saisir le temps de calcul en secondes :" << endl;
    scanf("%d", &temps);


    std::vector<Formation> formations;
    std::vector<Interface> interfaces;
    std::vector<Centre> centres;
    
    
    for (size_t i = 0; i < NBR_INTERFACES; i++)
    {
        interfaces.push_back(*(new Interface(i,competences_interfaces[i], specialite_interfaces[i])));
    }
    for (size_t j = 0; j < NBR_SPECIALITES+1; j++)
    {
        centres.push_back(*(new Centre(j, coord[j], j-1)));
    }
    for (size_t k = 0; k< NBR_FORMATION; k++) {
        int* f = formation[k];
        formations.push_back(*(new Formation(f[0], f[1], f[2], f[3], f[4], f[5], f[1])));
    }

    int dureeTabou = 80;
    int iterationAvantDiversification = 100;

    RechercheTabou tabou(formations, interfaces, centres, dureeTabou, iterationAvantDiversification);

    std::thread chrono(chronometre, temps, &tabou);

    tabou.rechercher();

    


    return 0;
}
