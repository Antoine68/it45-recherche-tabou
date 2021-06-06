#include "../include/Solution.hpp"


Solution::Solution()
{

}

Solution::~Solution()
{

}

void Solution::affecter(int idFormation, int idInterface) {
    this->m_affectations[idFormation] = idInterface;
}

void Solution::afficher() {
    for(int i=0; i< NBR_FORMATION; i++) {
        std::cout << "formation  " << i << "-> interface " << this->m_affectations[i] << std::endl;
    }
}