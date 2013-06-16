#include "experimentor.h"


class B {
public:

    // Also you get a very nice warning from clang about not having a
    // virtual destructor...
    //      warning: 'B' has virtual functions but non-virtual destructor [-Wnon-virtual-dtor]
    //      class B {
    virtual ~B(){}

    virtual void f(short) {
       std::cout << "B::f" << std::endl;
    }
    
    virtual void o() {
        std::cout << "B::o" << std::endl;
    }
};

class C : public B {
public:
    virtual ~C(){}
    
    // this will cause an error because it is expecting to override
    // the virtual function in B... but since the arguments don't match
    // it creates a new method. The identifier "override" raises a
    // compilation error if the function isn't actually overriding 
    // something...
    // virtual void f(int) override {
    //    std::cout << "D::f" << std::endl;
    // }
    
    virtual void f(short) override {
        std::cout << "C::f" << std::endl;
    }
    
    // This is the last time it can be overriden...
    virtual void o() override final {
        std::cout << "C::o" << std::endl;
    }
};

class D : public C {
public:
    virtual ~D(){}

    
    // This is the last time it can be overriden...
    //      error: declaration of 'o' overrides a 'final' function
    // virtual void o() override {
    //     std::cout << "D::o" << std::endl;
    // }
};


class Overrider : public ExperimentorInterface {
public:
    Overrider(){};
    virtual ~Overrider(){}
    
    virtual std::string getNameOfTest(){ return "Overrider testing";}
    virtual bool test();
    
};


bool Overrider::test(){
    std::cout << "Testing B::f" << std::endl;
    B b;
    b.f(2);
    
    std::cout << "Testing C::f" << std::endl;
    C c;
    c.f(1);
    
    std::cout << "Testing D::o" << std::endl;
    D d;
    d.o();
    return true;
}


int main (int /* argc */, char** const /* argv[]*/)
{
    std::cout << "-------------------------------------------" << std::endl;
    Overrider test = Overrider();
    test.run();
    return 0;
}
