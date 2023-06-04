#ifndef BITSPOP_H_
#define BITSPOP_H_

#include "BitsOrganism.h"

class BitsPop{

    std::vector<BitsOrganism *> pop;
    int popsize;

    public:

        BitsPop(int n, int genomesize) {
            popsize = n;
            for (int i = 0; i < n; i++) {
                BitsOrganism* org = new BitsOrganism(genomesize);
                pop.push_back(org);
            }
        }

        void update(const std::vector<BitsOrganism*> & newpop) {
            pop = newpop;
        }

        std::vector<BitsOrganism*> getPop() {
            return pop;
        }

        BitsOrganism* getMax() {
            auto it = std::max_element(pop.begin(), pop.end());
            return *it;
        }

        std::vector<BitsOrganism*> roulette_select(){
            int sum = 0;
            int index;
            int stop;

            for (auto i : pop) sum += i->getScore();

            std::vector<BitsOrganism*> winners;

            while (winners.size() < pop.size()){
                stop = sum > 0 ? rand() % sum: 0;
                index = 0;

                while (stop > 0 && index<pop.size() - 1) {
                    stop -= pop[index]->getScore();
                    index++;
                }

                winners.push_back(pop[index]);
            }  
            return winners;
        }
};

#endif /* BITSPOP_H_ */