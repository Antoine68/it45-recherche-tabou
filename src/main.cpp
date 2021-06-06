#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "../include/Donnee.hpp"
#include "../include/Random.hpp"
#include "../include/RechercheTabou.hpp"
#include "../include/Solution.hpp"
#include "../include/Formation.hpp"
#include "../include/Interface.hpp"
#include "../include/Centre.hpp"


using namespace std;

int main(int argc, char **argv)

{

    Random::randomize();

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
        formations.push_back(*(new Formation(f[0], f[1], f[2], f[3], f[4], f[5])));
    }
    
    RechercheTabou tabou(formations, interfaces, centres, 1, 1, 1, 1);

    Solution* meilleure = tabou.rechercher();

    


	return 0;
}
