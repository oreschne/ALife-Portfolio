#ifndef BITSGENOME_H_
#define BITSGENOME_H_
#include <iostream>

#include "AbstractGenome.h"
#include <algorithm>

class BitsGenome : public AbstractGenome<bool> {
    
    int n = genome.size();

    public:

    void init(){
        n = genome.size();
        for (int i = 0; i < n; i++){
            genome[i] = rand() % 2;
        }
    }

    void point_mutate() {
        int locus = n == 0 ? 0 : rand() % n;
        genome[locus] = rand() % 2;
    }

    void block_mutate(int k) {
        int start = rand() % (n-k);
        int dest = rand() % (n-k);
        std::vector<bool>::const_iterator first = genome.begin() + start;
        std::vector<bool>::const_iterator last = genome.begin() + start + k;
        std::vector<bool> temp(first, last);
        std::copy(temp.begin(), temp.end(), genome.begin() + dest);
    }

    int ones(){
        return std::count(genome.begin(), genome.begin() + n, 1);
    }

    void display() {
        for (auto i : genome) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

#endif /* BITSGENOME_H_ */