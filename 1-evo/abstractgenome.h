#include <vector>

template<class A>
class AbstractGenome {
    protected:
        std::vector<A> genome;

    public: 
        AbstractGenome (int n){
            genome.resize(n);
        } 

    ~AbstractGenome(){};
    void fill(A x) {
        std::fill(genome.begin(), genome.end(), x);
    }
    std::vector<A> get(){
        return genome; 
    }
}
