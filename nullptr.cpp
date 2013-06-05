#include "experimentor.h"

class Nullptr : public ExperimentorInterface {
public:
    Nullptr(){};
    virtual ~Nullptr(){}
    
    virtual std::string getNameOfTest(){ return "nullptr testing";}
    virtual bool test();
    
    void iLovePointers(int notReallyAPointer);
    void iLovePointers(const int* reallyAPointer);
};

/* two overloaded functions, to test out what happens when we have a null pointer */
void Nullptr::iLovePointers(int notReallyAPointer) {
    std::cout << "Called with the int consuming overloaded function (" << std::endl;
    std::cout << notReallyAPointer;
    std::cout << ")" << std::endl;   
}
void Nullptr::iLovePointers(const int* reallyAPointer) {
    std::cout << "Called with the const int* consuming overloaded function (";
    std::cout << reallyAPointer;
    std::cout << ")" << std::endl;    
}


bool Nullptr::test(){
    // A null pointer is now be a type. Previously a pointer that was not assigned
    // to an address was equal to 0. 
    // Reducing confusion, gaining clarity. nice!
    
    int* aPointerToAnInteger = 0;
    std::cout << "A new pointer that is not initialized: " << aPointerToAnInteger << std::endl;
        
    int* aNullptr = nullptr;
    std::cout << "A new pointer that is initialized to nullptr: " << aNullptr << std::endl;
    
    // Implicit casting happens so that
    if(aNullptr == aPointerToAnInteger){
        std::cout << "nullptr is equal to 0" << std::endl;
    }
    
    // but 
    bool nullptrToBoolean = aNullptr;
    // only this is legal with a nullptr;
    
    std::cout << "Calling with a pointer set to 0" << std::endl;
    iLovePointers(aPointerToAnInteger);

    std::cout << "Calling with a pointer set to nullptr" << std::endl;
    iLovePointers(aNullptr);

    // This will die :(
    // std::cout << "Calling with NULL" << std::endl;
    // iLovePointers(NULL);
    
    // The following is illegal!
    //  bool hasValue = aPointerToAnInteger;
    
    // More information in:
    //http://stackoverflow.com/questions/1282295/what-exactly-is-nullptr
    
    // Great explanantion
    // http://stackoverflow.com/questions/13816385/what-are-the-advantages-of-using-nullptr
    
    
    if(!aNullptr){
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
