#include "../include/Random.hpp"

void Random::randomize()
{
    srand(time(NULL));
};


long Random::aleatoire(long borne)
{
    return(rand()%borne);
};

