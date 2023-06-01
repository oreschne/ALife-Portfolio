#include <string> 
#include <vector> 
#include <algorithm>

class Organism
{
    public:
    int age; 
    std::string name; 
    bool isAlive;

    Organism(int a, std::string n)
    {
        age = a;
        name = n;
        isAlive = true;
    } 

    bool operator==(const Organism& o)
    {
        return this->name == o.name;
    }
};

class Population
{
    public:
    std::vector<Organism*> popvec;

    Population(std::vector<Organism*> v)
    {
        popvec = v;
        std::sort(v.begin(),v.end());

    }

};

int main()
{
    std::vector<Organism*> vec = std::vector<Organism*>();
    for(int i =0; i<20; i++)
    {
        Organism o = Organism(std::rand()%100, "Bob");
        vec.push_back(&o);
    }
    Population pop = Population(vec);
};