#include "../experimentor.h"

class AutoBasic : public ExperimentorInterface {
public:
    AutoBasic(){};
    virtual ~AutoBasic(){}
    
    virtual std::string getNameOfTest(){ return "basic 'auto' type";}
    
    virtual bool test(){
        auto integer = 101;
        auto string = "Hello World";
        
        std::cout << string << std::endl;
        
        return true;
    }
};




int main (int /* argc */, char* const argv[])
{
    AutoBasic e = AutoBasic();
    e.run();
    // delete e;
    return 0;
}
