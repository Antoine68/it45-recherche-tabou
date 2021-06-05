//
// Define guards
#ifndef CENTRE_H
#define CENTRE_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>


class Centre
{
    public:
        Centre(int id, float coordonnees[2], int specialite);
        virtual ~Centre();
        int getId();
        float* getCoordonnees();
        int getSpecialite();
       

    protected:

    private:
      int m_id;
      float m_coordonnees[2];
      int m_specialite;
};

#endif // INTERFACE_H
