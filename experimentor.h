#include <iostream>

class ExperimentorInterface {
public:
    ExperimentorInterface(){}
    virtual ~ExperimentorInterface(){}
    virtual bool test() = 0;
    virtual std::string getNameOfTest() = 0;
    
    virtual bool run();
        
    
};


bool ExperimentorInterface::run(){
    std::cout << "Testing: " << getNameOfTest() << std::endl;
    test();
}



