//
// Define guards
#ifndef FORMATION_H
#define FORMATION_H

#include <stdio.h>
#include <iostream>
#include <fstream>


class Formation
{
    public:
        Formation();
        virtual ~Formation();

    protected:

    private:
        int id;
        int competance[2];
        
       
};

#endif // FORMATION_H
