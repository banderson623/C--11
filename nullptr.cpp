#include "experimentor.h"

class Nullptr : public ExperimentorInterface {
public:
    Nullptr(){};
    virtual ~Nullptr(){}
    
    virtual std::string getNameOfTest(){ return "decltype testing";}
    
    virtual bool test();
};


bool Nullptr::test(){
    // A null pointer is now be a type. Previously a pointer that was not assigned
    // to an address was equal to 0. 
    // Reducing confusion, gaining clarity. nice!
    
    int* aPointerToAnInteger = 0;
    std::cout << "A new pointer that is not initialized: " << aPointerToAnInteger << std::endl;
        
    int* aPointerForAnInteger = nullptr;
    std::cout << "A new pointer that is initialized to nullptr: " << aPointerForAnInteger << std::endl;
    
    // Implicit casting happens so that
    if(aPointerForAnInteger == aPointerToAnInteger){
        std::cout << "nullptr is equal to 0" << std::endl;
    }
    
    // but 
    bool nullptrToBoolean = aPointerForAnInteger;
    // only this is legal with a nullptr;
    
    // The following is illegal!
    //  bool hasValue = aPointerToAnInteger;
    
    // More information in:
    //http://stackoverflow.com/questions/1282295/what-exactly-is-nullptr
    
    if(!aPointerForAnInteger){
        std::cout<< "can be used directly in an if statement " << std::endl;
    }
    
    return true;
}


int main (int /* argc */, char** const /* argv[]*/)
{
    std::cout << "-------------------------------------------" << std::endl;
    Nullptr test = Nullptr();
    test.run();
    return 0;
}
