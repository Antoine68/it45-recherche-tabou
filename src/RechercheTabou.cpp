#include "../include/RechercheTabou.hpp"


RechercheTabou::RechercheTabou(std::vector<Formation>& formations, std::vector<Interface>& interfaces, std::vector<Centre>& centres, 
                       int dureeTabou, int nbIterationAvantDiversification)
{
    
    this->m_formations = formations;
    //on trie les formations pour qu'elles soient dans l'ordre croissant des jours et des heures
    std::sort(this->m_formations.begin(), this->m_formations.end());
    this->m_interfaces = interfaces;
    this->m_centres = centres;
    this->m_dureeTabou = dureeTabou;
    this->m_nbIterationAvantDiversification = nbIterationAvantDiversification;
    this->m_meilleureFitness = 999999999.0;
    this->calculerDistances();
    
    

}

RechercheTabou::~RechercheTabou()
{

}

/**
 * Recherche tabou
 * 
 */
void RechercheTabou::rechercher() {
   //on cherche une solution initiale
   this->firstFit();
   std::cout << "premiere solution :" <<  std::endl;
   this->afficherMeilleurSolution();
   int nbIterationsSansAmelioration = 0;
   int meilleureId1, meilleureId2;
   float fitnessAvant = 9999999.;
   float fitnessApres = 0.;
   bool descente = false;
   bool first = true;
   this->m_iterationActuelle = 0;
   this->m_boucler = true;
   int nbIterationDiversiteActuellle = 0;
   int nbIterationMeilleure = 0;
   std::cout << "-------Début recherche tabou-------" <<  std::endl;
   while (this->m_boucler)
   {
      
       while(!this->voisinage(meilleureId1, meilleureId2)) {
           //std::cout << "pas de voisinage à " << this->m_iterationActuelle << std::endl;
           this->firstFit();
           nbIterationsSansAmelioration = 0;
           nbIterationMeilleure = (nbIterationMeilleure > nbIterationDiversiteActuellle) ? nbIterationMeilleure : nbIterationDiversiteActuellle;
           nbIterationDiversiteActuellle = 0;
       }
       //std::cout << "choisi" << meilleureId1<< " " << meilleureId2 << std::endl;
       this->inverser(meilleureId1, meilleureId2);
       this->evaluerSolutionActuelle();

       fitnessApres = this->m_fitnessActuelle;
       
       nbIterationsSansAmelioration++;
       nbIterationDiversiteActuellle++;

       if(this->m_meilleureFitness > this->m_fitnessActuelle) {
           this->nouvelleMeilleureSolution();
           nbIterationsSansAmelioration = 0;
           //std::cout << "-> iter: " << this->m_iterationActuelle << ": " << this->m_meilleureFitness << std::endl;
       } else  {
            // Critères de détection d'un minimum local. 2 cas:
            //  1. si la nouvelle solution est + mauvaise que l'ancienne
            //         et que on est en train d'effectuer une descente
            //  2. si la nouvelle solution est identique à l'ancienne
            //         et que c'est la première fois que cela se produit
           if(((fitnessAvant < fitnessApres) && descente) || ((fitnessAvant == fitnessApres)&&(first))) {
                std::cout << "minimum local-> iter: " << this->m_iterationActuelle-1 << ": " << fitnessAvant << std::endl;
           }
           if (fitnessAvant<=fitnessApres)  // la solution courente se dégrade
	            descente = false;
	        else
	            descente = true;   // la solution courante s'améliore : descente
            if ((fitnessAvant!=fitnessApres)&&(!first)) //
                first = true;
       }
       fitnessAvant = fitnessApres;
       //std::cout << "iter: " << this->m_iterationActuelle << "  " << this->m_fitnessActuelle <<"  " << this->m_meilleureFitness << std::endl;


       //on diversifie quand :
       // - on a atteint le même nombre d'itération pour cette diversification
       //   que pour la meilleure + le nombre d'itération choisit en paramètre.
       //cela permet de plus explorer une diversification car au début on est certain d'avoir une mauvaise fitness
       if (nbIterationsSansAmelioration >= this->m_nbIterationAvantDiversification && nbIterationDiversiteActuellle >= nbIterationMeilleure)
       {
           //std::cout << "diversification à " << this->m_iterationActuelle << std::endl;
           nbIterationsSansAmelioration = 0;
           nbIterationMeilleure = (nbIterationMeilleure > nbIterationDiversiteActuellle - this->m_nbIterationAvantDiversification) ? 
                                            nbIterationMeilleure : (nbIterationDiversiteActuellle - this->m_nbIterationAvantDiversification);
           nbIterationDiversiteActuellle = 0;
           this->firstFit();
       }
       this->m_iterationActuelle++;
        

   }
   std::cout << "-------Fin recherche tabou-------" << std::endl;
   std::cout << "meilleure solution trouve:" << std::endl;
   this->afficherMeilleurSolution();
}

void RechercheTabou::arreterRecherche() {
    this->m_boucler = false;
}

/**
 * Cherche les deux meilleures attributions à inverser dans la solution actuelle.
 * @return true si une permutation à été trouvé, false sinon.
 */
bool RechercheTabou::voisinage(int& id1, int& id2) {
    //choix premier index aléatoire
    //int indexRandom = Random::aleatoire(NBR_FORMATIONS);
    float meilleureFitness = 999999.0;
    float fitness;
    int meilleurVoisin1 = -1;
    int meilleurVoisin2 = -1;
    //pour chaque attribution
    for (int i = 0; i < NBR_FORMATION; i++)
    {
        for (int j = 0; j < NBR_FORMATION; j++)
        {
            //si elles sont inversibles
            if(j != i && this->estInversible(i, j)) {
                //on regarde si l'inversion est meilleures que les précédentes
                this->inverser(i, j);
                fitness = this->m_fitnessActuelle;
                this->evaluerSolutionActuelle();
                //si oui on la marque comme meilleure inversion
                if(this->m_fitnessActuelle < meilleureFitness) {
                    meilleureFitness = fitness;
                    meilleurVoisin2 = j;
                    meilleurVoisin1 = i;
                }
                //on remet la solution actuelle comme elle était avant
                this->inverser(i, j);
                this->m_fitnessActuelle = fitness;
            }
        }
    }
    if(meilleurVoisin1 != -1 && meilleurVoisin1 != -1) {
        id1 = meilleurVoisin1;
        id2 = meilleurVoisin2;
        return true;
    }
    return false;
}

/**
 * Vérifie si les deux attributions peuvent être inversés.
 * @return true si les deux attributions sont inversibles, false sinon.
 */
bool RechercheTabou::estInversible(int id1, int id2) {

    //si la permutation est dans la liste tabou
    if(this->estTabou(id1, id2)) return false;

    Formation* formation1 = this->getFormationById(id1);
    Interface* interface1 = this->getInterfaceById(this->m_solutionActuelle[id1]);
    Formation* formation2 = this->getFormationById(id2);
    Interface* interface2 = this->getInterfaceById(this->m_solutionActuelle[id2]);
    //std::cout << formation1->getId() << " " << interface1->getId() << "/" << formation2->getId() << " " << interface2->getId();
    //si les interfaces n'ont pas les bonnes competances pour permutter
    if(!interface1->aCompetance(formation2->getCompetance()) || !interface2->aCompetance(formation1->getCompetance())) {
        //std::cout << "faux" << std::endl;
        return false;
    }
    //std::cout << std::endl;

    int duree1 = formation1->getHeureFin() - formation1->getHeureDebut();
    int duree2 = formation2->getHeureFin() - formation2->getHeureDebut();

    int nouvellesHeuresJourInterface1 = interface1->getNombreHeuresParJour(formation2->getJour()) + duree2;
    int nouvellesHeuresJourInterface2 = interface2->getNombreHeuresParJour(formation1->getJour()) + duree1;

    int nouvellesHeuresParSemaineInterface1 = 
            interface1->getNombreHeuresTotales() - interface1->getNombreHeuresParJour(formation2->getJour()) + nouvellesHeuresJourInterface1 - duree1;
    int nouvellesHeuresParSemaineInterface2 = 
            interface2->getNombreHeuresTotales() - interface2->getNombreHeuresParJour(formation1->getJour()) + nouvellesHeuresJourInterface2 - duree2;

    bool enMemeTemps = false;

    //si les deux formations sont le même jour
    if(formation1->getJour() == formation2->getJour()) {
        nouvellesHeuresJourInterface1 -= duree1;
        nouvellesHeuresJourInterface2 -= duree2; 
        int i= formation1->getHeureDebut();
        //on regarde si les formations se chevauchent
        while (i <= formation1->getHeureFin() && !enMemeTemps)
        {
            if(i <= formation2->getHeureFin() && i >= formation2->getHeureDebut()) enMemeTemps = true;
            i++;
        }

    }

    //si les interfaces sont déjà occupé par une formation autre que celle que l'ont veut inverser
    if(!enMemeTemps && 
        (interface1->estOccuppe(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin())
        || interface2->estOccuppe(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin()))) {
                
            return false;
    }

    // si les heures de travail ne sont pas dépassées
    if(nouvellesHeuresJourInterface1 > 8 || nouvellesHeuresParSemaineInterface1 > 35
           || nouvellesHeuresJourInterface2 > 8 || nouvellesHeuresParSemaineInterface2 > 35) {

            return false;
    }

    return true;
}

/**
 * Inverse deux attributions d'une solution et met à jour les heures de chaque interface
 *
 */
void RechercheTabou::inverser(int id1, int id2) {

    Formation* formation1 = this->getFormationById(id1);
    Interface* interface1 = this->getInterfaceById(this->m_solutionActuelle[id1]);
    Formation* formation2 = this->getFormationById(id2);
    Interface* interface2 = this->getInterfaceById(this->m_solutionActuelle[id2]);

    //on supprime les heures de l'ancienne formation
    interface1->supprimerOccupation(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin());
    //on ajoute les heures de la nouvelle formation
    interface1->ajouterOccupation(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin());
    //on supprime les heures de l'ancienne formation
    interface2->supprimerOccupation(formation2->getJour(), formation2->getHeureDebut(), formation2->getHeureFin());
    //on ajoute les heures de la nouvelle formation
    interface2->ajouterOccupation(formation1->getJour(), formation1->getHeureDebut(), formation1->getHeureFin());

    //on inverse les affections dans la solution actuelle
    int temp = this->m_solutionActuelle[id1];
    this->m_solutionActuelle[id1] = this->m_solutionActuelle[id2];
    this->m_solutionActuelle[id2] = temp;

    //on met à jour la liste tabou
    this->miseAJourListeTabou(id1, id2);

}

bool RechercheTabou::estTabou(int id1, int id2) {
    return (
        this->m_listeTabou[id1][id2] > this->m_iterationActuelle ||
        this->m_listeTabou[id2][id1] > this->m_iterationActuelle
    );
}

void RechercheTabou::miseAJourListeTabou(int id1, int id2) {
    this->m_listeTabou[id1][id2] = this->m_iterationActuelle + this->m_dureeTabou;
    this->m_listeTabou[id2][id1] = this->m_iterationActuelle + this->m_dureeTabou;
}


/**
 * Algorithme glouton first-fit
 * 
 * Pour chaque formation on attribut la première interface
 * qui remplit toutes les contraintes obligatoires.
 * 
 * Puis on mélange le tableau des interfaces pour ne pas
 * toujours parcourrir le tableau dans le même ordre.
 * 
 * Problématique : les interfaces ayant les deux compétances
 * -> car elles peuvent être choisis pour une compétance alors qu'il
 * n'y a pas assez d'interfaces pour l'autre compétance.
 * -> possibilité de solution non valide.
 * Il y a donc une vérification de la validité de la solution
 * à la fin.
 * 
 */
void RechercheTabou::firstFit() {

    bool trouve = false; //interface trouvee
    int j = 0;
    
    Formation* formation; //pointeur sur la formation actuelle
    Interface* interface; //pointeur sur l'interface actuelle

    int duree = 0; //duree de la formation

    int id = -1;//id interface trouvee

    for (size_t i = 0; i < this->m_interfaces.size(); i++)
    {
        this->m_interfaces[i].viderOccupations();
    }
    

    for(int i = 0; i < NBR_FORMATION; i++) {
        j = 0;
        trouve = false;
        formation = &this->m_formations[i];
        duree = formation->getHeureFin() - formation->getHeureDebut(); //duree de la formation
        id = -1;
        while(j<NBR_INTERFACES && !trouve) { // tant qu'on trouve pas l'interface qui convient
            interface = &this->m_interfaces[j]; 
            if (interface->aCompetance(formation->getCompetance()) // l'interface a la bonne compétance
                && (interface->getNombreHeuresParJour(formation->getJour()) + duree) <= 8 //l'interface a moins de 8h le jour de la formation
                && (interface->getNombreHeuresTotales() + duree) <= 35 // l'interface à moins de 35h au total
                && !interface->estOccuppe(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()) //l'interface n'est pas occupée
            ) {
                
                trouve = true; // interface trouvee
                id = interface->getId();
            }
            j++;
        }
        
        this->m_solutionActuelle[formation->getId()] = id;
        if(id != -1) {
            //on ajoute les heures à l'interface
            interface->ajouterOccupation(formation->getJour(), formation->getHeureDebut(), formation->getHeureFin()); 
        }
        Random::melangerAleatoirementInterfaces(this->m_interfaces); //on mélange aléatoirement le vector des interfaces

        
    }
    //si la solution troouvée est valide on l'évalue
    if (this->firstFitEstValide())
    {
        this->evaluerSolutionActuelle();
        if(this->m_meilleureFitness > this->m_fitnessActuelle) this->nouvelleMeilleureSolution();
        return;
    }
    //sinon on refait un first fit
    this->firstFit();
    
    
}


/**
 * Vérifie si la solution actuelle est valide
 * après le passage dans le first fit
 * 
 */
bool RechercheTabou::firstFitEstValide() {
    for (int i = 0; i < NBR_FORMATIONS; i++)
    {
        //si l'id est égale à -1 cela signifie qu'aucune formation n'a été trouvé
        //et donc que la solution n'est pas valide
        if(this->m_solutionActuelle[i] == -1) return false;
    }
    return true;
}

/**
 * Calcul des distances
 * 
 */
void RechercheTabou::calculerDistances() {
    Centre* centre1;
    Centre* centre2;
    float distanceTotal = 0.0;
    for (int i = 0; i < NBR_CENTRES_FORMATION+1; i++)
    {
        for (int j = 0; j < NBR_CENTRES_FORMATION+1; j++) {
            if (i == j) {
                this->m_distances[i][j] = 0;
            } else {
                centre1 = this->getCentreById(i);
                centre2 = this->getCentreById(j);
                this->m_distances[i][j] = 
                    sqrtf(powf((centre2->getCoordonneeX() - centre1->getCoordonneeX()),2) 
                            + powf((centre2->getCoordonneeY() - centre1->getCoordonneeY()),2));
               
            }
            distanceTotal += this->m_distances[i][j];
            //std::cout << i << " " << j << ": " << this->m_distances[i][j] << std::endl;
        }
    }
    //diviser par 2 car on a ij et ji
    this->m_facteurCorrelation = (distanceTotal/2.0) / NBR_FORMATIONS;
    
}

/**
 * Affiche la meilleure solution dans le terminal 
 * 
 */
void RechercheTabou::afficherMeilleurSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        std::cout << "formation  " << i << "-> interface " << this->m_meilleureSolution[i] << std::endl;
    }
    std::cout << "facteur de corrélation = " << this->m_facteurCorrelation << std::endl;
    std::cout << "nombre de specialités respectées =  " << (NBR_FORMATIONS - this->m_penaliteSpecialiteMeilleureSolution);
    std::cout << " soit " << (100*(NBR_FORMATIONS - this->m_penaliteSpecialiteMeilleureSolution))/NBR_FORMATIONS << "%" <<std::endl;
    std::cout << "nombre de pauses 12h-14h non respectées =  " << this->m_penalitePauseMeilleureSolution << std::endl;
    std::cout << "moyenne des déplacments = " << this->m_moyenneDeplacementMeilleureSolution << std::endl;
    std::cout << "écart type des déplacments = " << this->m_ecartTypeDeplacmentMeilleureSolution << std::endl;
    std::cout << "fitness =  " << this->m_meilleureFitness << std::endl;
}

/**
 * Evaluation de la solution actuelle
 * 
 */
void RechercheTabou::evaluerSolutionActuelle() {
    float distancesInterface[NBR_INTERFACES] = {0.0};
    int dernierCentre[NBR_INTERFACES][7] = {0};
    int penaliteSpecialite = 0;
    int penalitePause = 0;
    Formation* formation;
    Interface* interface;
    for (int i = 0; i < NBR_FORMATION; i++)
    {
        
        formation = &this->m_formations[i];
        interface = this->getInterfaceById(this->m_solutionActuelle[formation->getId()]);
        // on ajoute la distance entre le dernier centre et l'actuel
        distancesInterface[interface->getId()] += getDistanceEntreCentres(dernierCentre[interface->getId()][formation->getJour()], formation->getCentre());
        //std::cout << "interface" << interface->getId() << ": j"<< formation->getJour() << " de " << dernierCentre[interface->getId()][formation->getJour()] << " à " << formation->getCentre() << " -> +" << getDistanceEntreCentres(dernierCentre[interface->getId()][formation->getJour()], formation->getCentre()) << std::endl;
        //mise à jour du dernier centre visité
        dernierCentre[interface->getId()][formation->getJour()] = formation->getCentre();
        //si c'est la dernière formation pour l'interface
        
        if(interface->estDerniereDeLaJournee(formation->getJour(), formation->getHeureFin())) {
            //on ajoute la distance entre le dernier centre et le centre SESSAD
            distancesInterface[interface->getId()] += getDistanceEntreCentres(formation->getCentre(), 0);
            //std::cout << "interface" << interface->getId() << ": j"<< formation->getJour() << " de " << dernierCentre[interface->getId()][formation->getJour()] << " à " << 0 << " -> +" << getDistanceEntreCentres(dernierCentre[interface->getId()][formation->getJour()], 0) << std::endl;
            dernierCentre[interface->getId()][formation->getJour()] = 0;
        }
        //si l'interface n'a pas la bonne spécialité
        if(!interface->aSpecialite(formation->getSpecialite())) {
            //incrémentation de la pénalité
            penaliteSpecialite++;
        }
    }
     //calcul penalite pause d'une heure à midi (entre 12h et 14h)
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < NBR_INTERFACES; j++)
        {
            interface = &this->m_interfaces[j];
            if (!interface->aPauseMidi(i))
            {
                penalitePause++;
            }
            
        }
    }
    
    float moyenneDeplacement = this->calculerMoyenne(distancesInterface, NBR_INTERFACES);
    float ecartTypeDeplacement = this->calculerEcartType(distancesInterface, NBR_INTERFACES);    
    this->m_penalitePauseSolutionActuelle = penalitePause;
    this->m_penaliteSpecialiteSolutionActuelle = penaliteSpecialite;
    this->m_moyenneDeplacementSolutionActuelle = moyenneDeplacement;
    this->m_ecartTypeDeplacmentSolutionActuelle = ecartTypeDeplacement;
    //objectif
    this->m_fitnessActuelle =  0.5 * (moyenneDeplacement + ecartTypeDeplacement) + 0.5 * this->m_facteurCorrelation * penaliteSpecialite;
}

/**
 * Calcul de la moyenne
 * 
 */
float RechercheTabou::calculerMoyenne(float* donnees, int taille)
{
    int somme = 0, moyenne;

    int i;

    for(i = 0; i < taille; i++){
        somme += donnees[i];
    }

    moyenne = somme/taille;
    return moyenne;
}

/**
 * Calcul de l'écart-type 
 * 
 */
float RechercheTabou::calculerEcartType(float* donnees, int taille)
{
    int moyenne, ecartType = 0.0;

    moyenne = calculerMoyenne(donnees, taille);

    for(int i = 0; i < taille; i++){
        ecartType += powf(donnees[i] - moyenne, 2);
    }

    return sqrt(ecartType / taille);
}


/**
 * La solution actuelle devient la meilleure solution
 * 
 */
void RechercheTabou::nouvelleMeilleureSolution() {
    for(int i=0; i< NBR_FORMATION; i++) {
        this->m_meilleureSolution[i] = this->m_solutionActuelle[i];
    }
    this->m_ecartTypeDeplacmentMeilleureSolution = this->m_ecartTypeDeplacmentSolutionActuelle;
    this->m_moyenneDeplacementMeilleureSolution = this->m_moyenneDeplacementSolutionActuelle;
    this->m_penalitePauseMeilleureSolution = this->m_penalitePauseSolutionActuelle;
    this->m_penaliteSpecialiteMeilleureSolution = this->m_penaliteSpecialiteSolutionActuelle;
    this->m_meilleureFitness = this->m_fitnessActuelle;
}

float RechercheTabou::getDistanceEntreCentres(int id1, int id2) {
    return this->m_distances[id1][id2];
}

Formation* RechercheTabou::getFormationById(int id) 
{
    for (size_t i = 0; i < this->m_formations.size(); i++)
    {
        if (this->m_formations[i].getId() == id) return &this->m_formations[i];
    }
    return nullptr;    
}


Interface* RechercheTabou::getInterfaceById(int id) 
{
    for (size_t i = 0; i < this->m_interfaces.size(); i++)
    {
        if (this->m_interfaces[i].getId() == id) return &this->m_interfaces[i];
    }
    return nullptr;
}

Centre* RechercheTabou::getCentreById(int id) 
{
    for (size_t i = 0; i < this->m_centres.size(); i++)
    {
        if (this->m_centres[i].getId() == id) return &this->m_centres[i];
    }
    return nullptr;
}


