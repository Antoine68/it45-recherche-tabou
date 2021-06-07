#include "../include/Donnee.hpp"
/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {1,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {0,1},
    {1,1},
    {1,1},
    {0,1},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {1,1},
    {1,0},
    {1,0},
    {0,1}
};
/* spécialités des interfaces */
/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,0,1,0,1},
    {1,1,0,1,1},
    {0,0,0,0,0},
    {0,0,1,0,1},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {1,0,1,0,0},
    {1,0,0,0,0},
    {0,1,0,1,0},
    {0,0,0,1,0},
    {0,0,0,0,0},
    {0,0,1,1,0},
    {0,0,0,1,1},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,0,1,0},
    {0,1,1,1,0},
    {0,1,0,0,0},
    {0,0,0,0,1},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,1,1,0,0},
    {1,0,0,0,0},
    {0,1,0,0,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_NODES][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {115,113}, /* centre 0 */
                  
    /* Centres de formation */
    {1,20}, /* ecole formation SPECIALITE_MENUISERIE */
    {178,128}, /* ecole formation SPECIALITE_ELECTRICITE */
    {118,97}, /* ecole formation SPECIALITE_MECANIQUE */
    {28,155}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {30,66}, /* ecole formation SPECIALITE_CUISINE */
                  
    /* Apprenants */
    {99,125}, /* apprenant 0 */
    {11,74}, /* apprenant 1 */
    {116,98}, /* apprenant 2 */
    {169,124}, /* apprenant 3 */
    {111,83}, /* apprenant 4 */
    {147,133}, /* apprenant 5 */
    {145,108}, /* apprenant 6 */
    {119,88}, /* apprenant 7 */
    {33,101}, /* apprenant 8 */
    {156,111}, /* apprenant 9 */
    {184,147}, /* apprenant 10 */
    {150,51}, /* apprenant 11 */
    {115,170}, /* apprenant 12 */
    {147,75}, /* apprenant 13 */
    {90,108}, /* apprenant 14 */
    {135,147}, /* apprenant 15 */
    {145,147}, /* apprenant 16 */
    {118,115}, /* apprenant 17 */
    {126,10}, /* apprenant 18 */
    {22,198}, /* apprenant 19 */
    {92,10}, /* apprenant 20 */
    {68,82}, /* apprenant 21 */
    {143,10}, /* apprenant 22 */
    {81,134}, /* apprenant 23 */
    {140,178}, /* apprenant 24 */
    {188,56}, /* apprenant 25 */
    {7,43}, /* apprenant 26 */
    {135,27}, /* apprenant 27 */
    {42,142}, /* apprenant 28 */
    {129,5}, /* apprenant 29 */
    {0,162}, /* apprenant 30 */
    {195,194}, /* apprenant 31 */
    {124,88}, /* apprenant 32 */
    {42,124}, /* apprenant 33 */
    {192,83}, /* apprenant 34 */
    {22,119}, /* apprenant 35 */
    {163,56}, /* apprenant 36 */
    {87,24}, /* apprenant 37 */
    {189,101}, /* apprenant 38 */
    {136,150}, /* apprenant 39 */
    {197,17}, /* apprenant 40 */
    {199,149}, /* apprenant 41 */
    {169,189}, /* apprenant 42 */
    {87,3}, /* apprenant 43 */
    {156,113}, /* apprenant 44 */
    {117,88}, /* apprenant 45 */
    {116,153}, /* apprenant 46 */
    {12,156}, /* apprenant 47 */
    {98,143}, /* apprenant 48 */
    {151,76}, /* apprenant 49 */
    {43,133}, /* apprenant 50 */
    {189,48}, /* apprenant 51 */
    {29,38}, /* apprenant 52 */
    {8,38}, /* apprenant 53 */
    {37,47}, /* apprenant 54 */
    {134,63}, /* apprenant 55 */
    {192,110}, /* apprenant 56 */
    {43,174}, /* apprenant 57 */
    {4,154}, /* apprenant 58 */
    {8,129}, /* apprenant 59 */
    {103,110}, /* apprenant 60 */
    {162,134}, /* apprenant 61 */
    {51,31}, /* apprenant 62 */
    {24,3}, /* apprenant 63 */
    {119,191}, /* apprenant 64 */
    {29,95}, /* apprenant 65 */
    {79,61}, /* apprenant 66 */
    {102,165}, /* apprenant 67 */
    {119,114}, /* apprenant 68 */
    {123,71}, /* apprenant 69 */
    {28,195}, /* apprenant 70 */
    {151,103}, /* apprenant 71 */
    {184,74}, /* apprenant 72 */
    {185,79}, /* apprenant 73 */
    {51,5}, /* apprenant 74 */
    {154,17}, /* apprenant 75 */
    {146,196}, /* apprenant 76 */
    {103,191}, /* apprenant 77 */
    {149,101}, /* apprenant 78 */
    {107,5}/* apprenant 79 */
};
                  
/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_FORMATION][6]={
   {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,14,17},
   {1,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,10,12},
   {2,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,16,18},
   {3,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {4,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,15,18},
   {5,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,10,12},
   {6,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,16,19},
   {7,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,16,18},
   {8,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,13,18},
   {9,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,14,19},
   {10,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,9,12},
   {11,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,14,17},
   {12,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,10,12},
   {13,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,10,12},
   {14,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,8,12},
   {15,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,10,12},
   {16,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,15,19},
   {17,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,13,18},
   {18,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,8,10},
   {19,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,8,11},
   {20,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,15,18},
   {21,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,14,19},
   {22,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,14,19},
   {23,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,10,12},
   {24,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,13,16},
   {25,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,9,11},
   {26,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {27,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,8,11},
   {28,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,15,18},
   {29,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,15,17},
   {30,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,15,19},
   {31,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,9,12},
   {32,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,8,12},
   {33,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,16,18},
   {34,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,16,19},
   {35,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,9,11},
   {36,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,15,19},
   {37,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,9,11},
   {38,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,16,18},
   {39,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,16,19},
   {40,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,13,19},
   {41,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,8,12},
   {42,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,17},
   {43,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,8,10},
   {44,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,15,19},
   {45,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,14,17},
   {46,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,9,12},
   {47,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,8,12},
   {48,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,9,12},
   {49,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,15,19},
   {50,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,9,11},
   {51,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,10,12},
   {52,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,10,12},
   {53,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,8,10},
   {54,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,10,12},
   {55,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,16,18},
   {56,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,9,11},
   {57,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,8,11},
   {58,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,13,16},
   {59,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {60,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,12},
   {61,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {62,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,14,19},
   {63,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,15,17},
   {64,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,13,17},
   {65,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,13,16},
   {66,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,9,11},
   {67,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,14,17},
   {68,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,8,11},
   {69,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,9,12},
   {70,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,8,12},
   {71,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,10},
   {72,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,13,16},
   {73,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,15,19},
   {74,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {75,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,14,18},
   {76,SPECIALITE_CUISINE,COMPETENCE_SIGNES,LUNDI,13,15},
   {77,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,15,18},
   {78,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {79,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,8,12}
};
                  
