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
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {1,1},
    {1,0},
    {0,1},
    {1,0},
    {0,1},
    {0,1},
    {1,0},
    {1,0},
    {0,1},
    {1,0},
    {0,1},
    {0,1},
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
    {1,0,1,0,1},
    {0,0,0,1,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,0,1,0,0},
    {0,1,0,0,0},
    {0,1,0,0,1},
    {0,1,1,0,0},
    {0,0,1,0,0},
    {0,0,0,0,1},
    {0,0,1,0,0},
    {0,0,0,0,0},
    {1,0,0,1,0},
    {1,1,0,0,0},
    {0,0,1,0,0},
    {0,1,0,0,0},
    {1,0,1,0,0},
    {0,0,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,1,1,0,0},
    {0,0,0,0,0},
    {0,1,0,0,1},
    {0,0,0,0,1}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_NODES][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {18,124}, /* centre 0 */
                  
    /* Centres de formation */
    {120,42}, /* ecole formation SPECIALITE_MENUISERIE */
    {52,149}, /* ecole formation SPECIALITE_ELECTRICITE */
    {187,19}, /* ecole formation SPECIALITE_MECANIQUE */
    {83,102}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {12,20}, /* ecole formation SPECIALITE_CUISINE */
                  
    /* Apprenants */
    {145,40}, /* apprenant 0 */
    {136,115}, /* apprenant 1 */
    {140,13}, /* apprenant 2 */
    {144,97}, /* apprenant 3 */
    {131,161}, /* apprenant 4 */
    {124,18}, /* apprenant 5 */
    {162,56}, /* apprenant 6 */
    {7,118}, /* apprenant 7 */
    {171,15}, /* apprenant 8 */
    {95,88}, /* apprenant 9 */
    {57,152}, /* apprenant 10 */
    {165,133}, /* apprenant 11 */
    {53,39}, /* apprenant 12 */
    {159,25}, /* apprenant 13 */
    {154,80}, /* apprenant 14 */
    {50,137}, /* apprenant 15 */
    {170,10}, /* apprenant 16 */
    {10,154}, /* apprenant 17 */
    {79,9}, /* apprenant 18 */
    {105,160}, /* apprenant 19 */
    {100,3}, /* apprenant 20 */
    {191,143}, /* apprenant 21 */
    {89,48}, /* apprenant 22 */
    {83,167}, /* apprenant 23 */
    {148,163}, /* apprenant 24 */
    {46,8}, /* apprenant 25 */
    {46,118}, /* apprenant 26 */
    {170,64}, /* apprenant 27 */
    {199,0}, /* apprenant 28 */
    {52,150}, /* apprenant 29 */
    {27,67}, /* apprenant 30 */
    {66,156}, /* apprenant 31 */
    {146,184}, /* apprenant 32 */
    {76,196}, /* apprenant 33 */
    {29,30}, /* apprenant 34 */
    {172,67}, /* apprenant 35 */
    {150,27}, /* apprenant 36 */
    {158,56}, /* apprenant 37 */
    {75,73}, /* apprenant 38 */
    {119,171}, /* apprenant 39 */
    {85,150}, /* apprenant 40 */
    {56,98}, /* apprenant 41 */
    {82,191}, /* apprenant 42 */
    {110,27}, /* apprenant 43 */
    {130,10}, /* apprenant 44 */
    {51,135}, /* apprenant 45 */
    {95,21}, /* apprenant 46 */
    {171,172}, /* apprenant 47 */
    {154,93}, /* apprenant 48 */
    {156,30}, /* apprenant 49 */
    {144,50}, /* apprenant 50 */
    {119,86}, /* apprenant 51 */
    {174,139}, /* apprenant 52 */
    {126,123}, /* apprenant 53 */
    {27,145}, /* apprenant 54 */
    {27,158}, /* apprenant 55 */
    {11,106}, /* apprenant 56 */
    {111,165}, /* apprenant 57 */
    {191,111}, /* apprenant 58 */
    {81,167}, /* apprenant 59 */
    {134,158}, /* apprenant 60 */
    {46,87}, /* apprenant 61 */
    {96,7}, /* apprenant 62 */
    {147,28}, /* apprenant 63 */
    {117,49}, /* apprenant 64 */
    {126,173}, /* apprenant 65 */
    {141,2}, /* apprenant 66 */
    {196,4}, /* apprenant 67 */
    {3,120}, /* apprenant 68 */
    {152,66}, /* apprenant 69 */
    {37,26}, /* apprenant 70 */
    {40,24}, /* apprenant 71 */
    {90,165}, /* apprenant 72 */
    {8,86}, /* apprenant 73 */
    {7,85}, /* apprenant 74 */
    {17,28}, /* apprenant 75 */
    {133,88}, /* apprenant 76 */
    {147,178}, /* apprenant 77 */
    {4,192}, /* apprenant 78 */
    {168,71}/* apprenant 79 */
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
   {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,8,10},
   {1,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,14,17},
   {2,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,13,19},
   {3,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,8,10},
   {4,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,8,11},
   {5,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,8,11},
   {6,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,8,12},
   {7,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,8,11},
   {8,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {9,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,14,17},
   {10,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,13,18},
   {11,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,10,12},
   {12,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,15,18},
   {13,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,14,19},
   {14,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,14,18},
   {15,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,8,12},
   {16,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,15,19},
   {17,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,10,12},
   {18,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,10,12},
   {19,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,15,17},
   {20,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,14,18},
   {21,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,14,17},
   {22,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {23,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,16,19},
   {24,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,15,17},
   {25,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,14,17},
   {26,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,15,18},
   {27,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,15,17},
   {28,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,12},
   {29,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,10,12},
   {30,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,8,12},
   {31,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,15,17},
   {32,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,16,18},
   {33,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,9,11},
   {34,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,15,18},
   {35,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,8,11},
   {36,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,8,10},
   {37,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MARDI,14,18},
   {38,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,13,18},
   {39,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,10,12},
   {40,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,13,18},
   {41,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,15,17},
   {42,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,15,18},
   {43,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,8,10},
   {44,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,13,19},
   {45,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,9,11},
   {46,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,13,17},
   {47,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,14,17},
   {48,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,8,10},
   {49,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,8,12},
   {50,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,16,19},
   {51,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,16,18},
   {52,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {53,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,13,17},
   {54,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,9,11},
   {55,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,14,17},
   {56,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,10,12},
   {57,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,15,18},
   {58,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,9,12},
   {59,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {60,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,13,15},
   {61,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {62,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,13,16},
   {63,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {64,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {65,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,14,17},
   {66,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,14,18},
   {67,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,15,18},
   {68,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {69,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {70,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,16,18},
   {71,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,14,16},
   {72,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,JEUDI,15,19},
   {73,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,16,18},
   {74,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,16,19},
   {75,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,9,12},
   {76,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,9,11},
   {77,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {78,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,8,10},
   {79,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,16,19}
};
                  
int main() {
                  
    printf("NBR_INTERFACES=%d\n",NBR_INTERFACES) ;
    printf("NBR_APPRENANTS=%d\n",NBR_APPRENANTS) ;
    printf("NBR_FORMATIONS=%d\n",NBR_FORMATIONS) ;
    printf("NBR_NODES=%d\n",NBR_NODES) ;
                  
    return 0 ;
}
                  
