//
// Define guards
#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Donnee.hpp"

class Interface
{
    public:
        Interface(int id, int competances[2], int specialites[NBR_SPECIALITES]);
        virtual ~Interface();
        int getId();
        bool aCompetance(int competance);
        bool aSpecialite(int specialite);

    protected:

    private:
       int m_id;
       int m_competances[2];
       int m_specialites[NBR_SPECIALITES];
};

#endif // INTERFACE_H
