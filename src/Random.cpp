#include "../include/Random.hpp"

void Random::randomize()
{
    srand(time(NULL));
};


long Random::aleatoire(int borne)
{
    return(rand()%borne);
};

void Random::melangerAleatoirementInterfaces(std::vector<Interface>& interfaces)
{
    std::random_shuffle(interfaces.begin(), interfaces.end(), Random::aleatoire);
}
