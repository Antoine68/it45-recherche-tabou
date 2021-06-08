//
// Define guards
#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <random>
#include "Interface.hpp"



class Random
{
    public:
        static void randomize();
        static long aleatoire(long borne);
        static void melangerAleatoirementInterfaces(std::vector<Interface>& interfaces);

    protected:

    private:
        
       
};

#endif // RANDOM_H
