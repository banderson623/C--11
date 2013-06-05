#include "experimentor.h"
#include <vector>
#include <map>

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
    
    
    typedef std::vector<std::string> Sentence;
    Sentence havingFun;
    havingFun.push_back("Hello");
    havingFun.push_back("cruel");
    havingFun.push_back("world");
        
    for(const auto& word : havingFun){
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    //It even works with maps
    typedef std::map<int,Sentence> Paragraph;
    Paragraph shortStory;
    shortStory[1] = havingFun;
    
    for(const auto& key : shortStory){
        std::cout << key.first << ": ";
        for(const auto& sentence : key.second){
            std::cout << sentence << " ";
        }
        std::cout << std::endl;
    }
    
    return true;
}


int main (int /* argc */, char** const /* argv[]*/)
{
    ForEach test = ForEach();
    test.run();
    return 0;
}
