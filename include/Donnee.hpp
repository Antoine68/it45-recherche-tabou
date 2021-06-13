#ifndef DONNEE_H
#define DONNEE_H


#include <stdio.h>
                  
#define NBR_INTERFACES        48
#define NBR_APPRENANTS        160
#define NBR_FORMATIONS        160
#define NBR_CENTRES_FORMATION 5
#define NBR_SPECIALITES       5
#define NBR_NODES 	      NBR_CENTRES_FORMATION+NBR_INTERFACES+NBR_APPRENANTS
                  
/* code des compétence en langage des signes et en codage LPC */
#define COMPETENCE_SIGNES     0
#define COMPETENCE_CODAGE     1
#define SPECIALITE_SANS       -1 /* Enseigné dans le centre le plus proche */
#define SPECIALITE_MENUISERIE 0
#define SPECIALITE_ELECTRICITE 1
#define SPECIALITE_MECANIQUE 2
#define SPECIALITE_INFORMATIQUE 3
#define SPECIALITE_CUISINE 4
#define NBR_FORMATION          160
                  
#define LUNDI                  1
#define MARDI                  2
#define MERCREDI               3
#define JEUDI                  4
#define VENDREDI               5
#define SAMEDI                 6
                  
extern int competences_interfaces[NBR_INTERFACES][2];
extern int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES];
extern float coord[NBR_NODES][2];
extern int formation[NBR_FORMATION][6];
                  
                  
                  
#endif //DONNEES
