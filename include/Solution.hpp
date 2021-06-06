//
// Define guards
#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Donnee.hpp"


class Solution
{
    public:
        Solution();
        virtual ~Solution();
        void affecter(int idFormation, int idInterface);
        void afficher();


    protected:

    private:
        int m_affectations[NBR_FORMATIONS] = {};

       
};

#endif // SOLUTION_H
