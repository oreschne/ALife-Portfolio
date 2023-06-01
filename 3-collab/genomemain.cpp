#include <iostream>
#include "abstractgenome.h"

int main() {
    AbstractGenome<char> genome(10);
    genome.fill('A');
    std::vector<char> vec = {'G', 'A', 'T', 'T', 'A', 'C' , 'A' , 'G', 'A' , 'T'};
    genome.set(vec);

    for(auto i : genome.get()){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}