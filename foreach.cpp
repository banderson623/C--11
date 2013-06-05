#include "experimentor.h"

class ForEach : public ExperimentorInterface {
public:
    ForEach(){};
    virtual ~ForEach(){}
    
    virtual std::string getNameOfTest(){ return "Ranged For testing";}
    virtual bool test();
    
};

bool ForEach::test(){

    //Simple arrays
    int favoriteNumbers[] = {1,2,3,4,5};
    for(const auto& currentFavorite : favoriteNumbers){
        std::cout << "My favorite number is " << currentFavorite << std::endl;
    }

    // Still can be manipulated my their reference...
    for(auto& num : favoriteNumbers){
        num += num;
    }

    for(const auto& num : favoriteNumbers){
        std::cout << "wait, now my favorite is " << num << std::endl;
    }
    
    return true;
}


int main (int /* argc */, char** const /* argv[]*/)
{
    ForEach test = ForEach();
    test.run();
    return 0;
}
