#include "experimentor.h"
#include <string>
#include <vector>

class AutoBasic : public ExperimentorInterface {
public:
    AutoBasic(){};
    virtual ~AutoBasic(){}
    
    virtual std::string getNameOfTest(){ return "'auto' type (with iterators)";}
    
    virtual bool test(){
        auto integer = 101;
        // If I used auto, it would have created a string literal (an array of characters... char*)
        auto strung = "Hello World";
        std::cout << strung << " and an integer: " << integer << std::endl;
        
        auto aRealString = std::string("Hello there!");

        // Let's make a quick word.        
        std::vector<char> word; 
        
        // // Here is how you would need to loop through in non C++11.
        // for(std::string::const_iterator aLetter =  aRealString.begin();
        //                                 aLetter != aRealString.end();
        //                               ++aLetter)
        // {
        //     word.push_back(*aLetter);
        // }
        
        // Here is a slightly less verbose way to do this.
        for(auto aLetter =  aRealString.begin(); aLetter != aRealString.end(); ++aLetter)
        {
            word.push_back(*aLetter);
        }
        
        // And here is the snazy new way!
        for(char& letter : word){
            std::cout << letter;
        }
        std::cout << std::endl; // just clean up the printing

        // And this works for strings too!!
        for(char& anotherLetter : aRealString){
            std::cout << anotherLetter;
        }
        std::cout << std::endl; // just clean up the printing

        return true;
    }
};




int main (int /* argc */, char** const /* argv[]*/)
{
    std::cout << "-------------------------------------------" << std::endl;
    AutoBasic e = AutoBasic();
    e.run();
    // delete e;
    return 0;
}
