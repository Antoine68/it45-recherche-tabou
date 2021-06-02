#ifndef DONNEE_H
#define DONNEE_H


#include <stdio.h>
                  
#define NBR_INTERFACES        24
#define NBR_APPRENANTS        80
#define NBR_FORMATIONS        80
#define NBR_CENTRES_FORMATION 5
#define NBR_SPECIALITES       5
#define NBR_NODES 	      NBR_CENTRES_FORMATION+NBR_INTERFACES+NBR_APPRENANTS
                  
/* code des compétence en langage des signes et en codage LPC */
#define COMPETENCE_SIGNES     0
#define COMPETENCE_CODAGE     1
                  
/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {1,0},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0},
    {1,0},
    {1,0},
    {0,1},
    {1,1},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {0,1},
    {1,0},
    {1,0},
    {1,0},
    {1,1},
    {1,0},
    {1,0}
};
                  
/* spécialités des interfaces */
#define SPECIALITE_SANS       -1 /* Enseigné dans le centre le plus proche */
#define SPECIALITE_MENUISERIE 0
#define SPECIALITE_ELECTRICITE 1
#define SPECIALITE_MECANIQUE 2
#define SPECIALITE_INFORMATIQUE 3
#define SPECIALITE_CUISINE 4
                  
/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,0,0,0,0},
    {0,1,0,0,0},
    {0,1,1,0,0},
    {0,0,0,0,0},
    {1,0,1,0,0},
    {0,0,1,1,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {1,1,0,0,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,0,1,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,1,0,0,1},
    {1,0,0,1,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_NODES][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {38,49}, /* centre 0 */
                  
    /* Centres de formation */
    {69,171}, /* ecole formation SPECIALITE_MENUISERIE */
    {39,61}, /* ecole formation SPECIALITE_ELECTRICITE */
    {188,80}, /* ecole formation SPECIALITE_MECANIQUE */
    {33,127}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {25,64}, /* ecole formation SPECIALITE_CUISINE */
                  
    /* Apprenants */
    {62,49}, /* apprenant 0 */
    {153,190}, /* apprenant 1 */
    {172,115}, /* apprenant 2 */
    {136,190}, /* apprenant 3 */
    {145,29}, /* apprenant 4 */
    {11,184}, /* apprenant 5 */
    {100,118}, /* apprenant 6 */
    {91,19}, /* apprenant 7 */
    {154,122}, /* apprenant 8 */
    {86,9}, /* apprenant 9 */
    {188,173}, /* apprenant 10 */
    {115,57}, /* apprenant 11 */
    {2,126}, /* apprenant 12 */
    {9,156}, /* apprenant 13 */
    {139,110}, /* apprenant 14 */
    {31,58}, /* apprenant 15 */
    {196,141}, /* apprenant 16 */
    {45,154}, /* apprenant 17 */
    {156,157}, /* apprenant 18 */
    {15,7}, /* apprenant 19 */
    {119,21}, /* apprenant 20 */
    {148,19}, /* apprenant 21 */
    {38,168}, /* apprenant 22 */
    {124,174}, /* apprenant 23 */
    {36,171}, /* apprenant 24 */
    {41,0}, /* apprenant 25 */
    {0,32}, /* apprenant 26 */
    {113,195}, /* apprenant 27 */
    {47,50}, /* apprenant 28 */
    {62,188}, /* apprenant 29 */
    {81,20}, /* apprenant 30 */
    {104,170}, /* apprenant 31 */
    {75,192}, /* apprenant 32 */
    {169,25}, /* apprenant 33 */
    {44,144}, /* apprenant 34 */
    {146,38}, /* apprenant 35 */
    {17,5}, /* apprenant 36 */
    {153,169}, /* apprenant 37 */
    {130,184}, /* apprenant 38 */
    {103,131}, /* apprenant 39 */
    {50,75}, /* apprenant 40 */
    {153,66}, /* apprenant 41 */
    {60,146}, /* apprenant 42 */
    {26,45}, /* apprenant 43 */
    {104,119}, /* apprenant 44 */
    {13,183}, /* apprenant 45 */
    {163,124}, /* apprenant 46 */
    {153,45}, /* apprenant 47 */
    {5,15}, /* apprenant 48 */
    {81,140}, /* apprenant 49 */
    {113,10}, /* apprenant 50 */
    {163,45}, /* apprenant 51 */
    {11,165}, /* apprenant 52 */
    {93,11}, /* apprenant 53 */
    {57,141}, /* apprenant 54 */
    {160,63}, /* apprenant 55 */
    {120,112}, /* apprenant 56 */
    {33,128}, /* apprenant 57 */
    {113,19}, /* apprenant 58 */
    {99,110}, /* apprenant 59 */
    {189,159}, /* apprenant 60 */
    {115,150}, /* apprenant 61 */
    {127,93}, /* apprenant 62 */
    {28,106}, /* apprenant 63 */
    {137,24}, /* apprenant 64 */
    {89,38}, /* apprenant 65 */
    {162,41}, /* apprenant 66 */
    {160,74}, /* apprenant 67 */
    {175,172}, /* apprenant 68 */
    {106,199}, /* apprenant 69 */
    {111,46}, /* apprenant 70 */
    {57,120}, /* apprenant 71 */
    {40,161}, /* apprenant 72 */
    {34,133}, /* apprenant 73 */
    {6,188}, /* apprenant 74 */
    {22,141}, /* apprenant 75 */
    {56,144}, /* apprenant 76 */
    {189,157}, /* apprenant 77 */
    {110,163}, /* apprenant 78 */
    {101,69}/* apprenant 79 */
};
                  
#define NBR_FORMATION          80
                  
#define LUNDI                  1
#define MARDI                  2
#define MERCREDI               3
#define JEUDI                  4
#define VENDREDI               5
#define SAMEDI                 6
                  
/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_FORMATION][6]={
   {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,9,12},
   {1,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,9,12},
   {2,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,9,11},
   {3,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,15,17},
   {4,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,10,12},
   {5,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,9,12},
   {6,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,9,11},
   {7,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,16,18},
   {8,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,8,12},
   {9,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,16,18},
   {10,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,8,12},
   {11,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,13,19},
   {12,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,16,19},
   {13,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,14,17},
   {14,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,16,18},
   {15,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,9,11},
   {16,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {17,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,9,11},
   {18,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,14,17},
   {19,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,8,10},
   {20,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,16,18},
   {21,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,15,19},
   {22,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,9,11},
   {23,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,9,12},
   {24,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,9,11},
   {25,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,8,12},
   {26,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,13,18},
   {27,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,13,17},
   {28,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,9,11},
   {29,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,9,11},
   {30,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,9,12},
   {31,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,10,12},
   {32,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,8,10},
   {33,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,8,11},
   {34,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,13,18},
   {35,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,8,12},
   {36,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,16,18},
   {37,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,13,18},
   {38,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,13,16},
   {39,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,8,10},
   {40,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,16,19},
   {41,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,9,12},
   {42,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {43,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,9,11},
   {44,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,14,16},
   {45,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,9,12},
   {46,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,16,18},
   {47,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,14,17},
   {48,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,9,11},
   {49,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {50,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,16,18},
   {51,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,13,17},
   {52,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {53,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,16,19},
   {54,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,16,19},
   {55,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,8,10},
   {56,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {57,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,17},
   {58,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,13,18},
   {59,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,13,17},
   {60,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,13,19},
   {61,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,8,10},
   {62,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,11},
   {63,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,14,17},
   {64,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,9,12},
   {65,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,14,17},
   {66,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,13,19},
   {67,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,8,11},
   {68,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,10,12},
   {69,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,15,18},
   {70,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,10,12},
   {71,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,9,12},
   {72,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,16,19},
   {73,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,15,19},
   {74,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,10,12},
   {75,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,8,11},
   {76,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,9,12},
   {77,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,9,12},
   {78,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {79,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,9,12}
};
                  
#endif //DONNEES
