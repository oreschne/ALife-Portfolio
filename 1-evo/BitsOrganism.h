#ifndef BITSORGANISM_H_
#define BITSORGANISM_H_

#include "BitsGenome.h"

class BitsOrganism {
    BitsGenome genome;
    int score;

    public:

    BitsOrganism(int n) {
        genome.resize(n);
        genome.init();
        score = genome.ones();
    }

    ~BitsOrganism();

    void update(){
        score = genome.ones();
    }

    int getScore() {
        return genome.ones();
    }

    void point_mutate() {
        genome.point_mutate();
    }

    void block_mutate(int k) {
        genome.block_mutate(k);
    }

    bool operator<(const BitsOrganism & other) {
        return score < other.score;
    }

    std::vector<bool> getGenome() {
        return genome.get();
    }
};

#endif /* BITSORGANISM_H_ */