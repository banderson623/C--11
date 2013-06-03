#include "experimentor.h"

class DecltypeTest : public ExperimentorInterface {
public:
    DecltypeTest(){};
    virtual ~DecltypeTest(){}
    
    virtual std::string getNameOfTest(){ return "decltype testing";}
    
    virtual bool test();

   /* Simple test for decltype, 
    * right from http://www.codeproject.com/Articles/570638/Ten-Cplusplus11-Features-Every-Cplusplus-Developer
    */
    template <typename T1, typename T2>
    auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
    {
       return t1+t2;
    }

};


bool DecltypeTest::test(){
    auto withFloat = compose(2, 3.14); // v's type is double
    std::cout << "Composed (adding) 2 with 3.14: " << withFloat << std::endl;

    /** Had to force! std::string */
    auto withStrings = compose(std::string("a"), std::string("c")); // now we are using strings
    std::cout << "Composed (adding) 'a' with 'c': " << withStrings << std::endl;
    return true;
}


int main (int /* argc */, char** const /* argv[]*/)
{
    std::cout << "-------------------------------------------" << std::endl;
    DecltypeTest test = DecltypeTest();
    test.run();
    return 0;
}
