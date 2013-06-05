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
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Testing: " << getNameOfTest() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    return test();
}



