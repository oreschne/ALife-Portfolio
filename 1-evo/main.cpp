#include "BitsPop.h"
#include "BitsOrganism.h"

int main() {

   int popsize = 100;
   int genomesize = 1000;
   int n_generations = 100;

   BitsPop population(popsize, genomesize);

   for (int i = 0; i < n_generations; i++){
        std::vector<BitsOrganism*> newpop;
        newpop = population.roulette_select();
        newpop = population.getPop();

        double avg = 0.0; 
        for (auto i : newpop) avg += i->getScore();

        std::cout << "Gen " << i << " " << "Avg " << avg << std::endl;
        
        for (auto org : population.getPop()) {
            org->point_mutate();
        }
      
        population.update(newpop);
        
    }; 
};

