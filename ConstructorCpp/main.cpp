#include <iostream>
#include "JednorekiBandyta.h"
#include "Stopper.h"


void foo1(SlotMachine sm){
    SlotMachine m3(sm);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
    m3.setCost(11);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
}

void foo2(SlotMachine sm){
    std::cout << sm.getCost() << std::endl;
    SlotMachine m3(std::move(sm));
    m3.setCost(11);
    std::cout << m3.getCost() << std::endl;
  
}

void bar1(const SlotMachine & sm){
    SlotMachine m3(sm);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
    m3.setCost(11);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
}

void bar2(const SlotMachine & sm){
    std::cout << sm.getCost() << std::endl;
    SlotMachine m3(std::move(sm));
    m3.setCost(11);
    std::cout << m3.getCost() << std::endl;
}

void baz1(SlotMachine & sm){
    SlotMachine m3(sm);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
    m3.setCost(11);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
}

void baz2(SlotMachine & sm){
    std::cout << sm.getCost() << std::endl;
    SlotMachine m3(std::move(sm));
    m3.setCost(11);
    std::cout << m3.getCost() << std::endl;
}

void qux1(SlotMachine && sm){
    SlotMachine m3(sm);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
    m3.setCost(11);
    std::cout << sm.getCost() << std::endl;
    std::cout << m3.getCost() << std::endl;
}

void qux2(SlotMachine && sm){
    std::cout << sm.getCost() << std::endl;
    SlotMachine m3(std::move(sm));
    m3.setCost(11);
    std::cout << m3.getCost() << std::endl;
}

int main(){
    SlotMachine machine;
    machine.setCost(10);
    SlotMachine m1(machine);
    std::cout << machine.getCost() << std::endl;
    std::cout << m1.getCost() << std::endl;
    std::cout<<std::endl;
    machine.setCost(12);
    std::cout << machine.getCost() << std::endl;
    std::cout << m1.getCost() << std::endl;
    m1.setCost(11);
    std::cout << machine.getCost() << std::endl;
    std::cout << m1.getCost() << std::endl;

    std::cout << std::endl <<" foo1" << std::endl;
    foo1(machine);
    // called 2 destructors

    std::cout << std::endl <<" foo2" << std::endl;
    foo2(machine);
    //cast delete on copy constructor to disble  this constructor then u can use move constructor - solution not working

    std::cout << std::endl <<" bar1" << std::endl;
    bar1(machine);
    // called 1 destructor - call only const type functions

    std::cout << std::endl <<" bar2" << std::endl;
    bar2(machine);
    // called 1 destructors - call only const type functions

    std::cout << std::endl <<" baz1" << std::endl;
    baz1(machine);
    // called 1 destructor

    std::cout << std::endl <<" baz2" << std::endl;
    baz2(machine);
    // called 1 destructor

   /* std::cout << std::endl <<" qux1" << std::endl;
    qux1(machine);*/
    // cannot bind r-value to l-lavue 

    /*std::cout << std::endl <<" qux2" << std::endl;
    qux2(machine);*/
    // cannot bind r-value to l-lavue 
     
                 //machine.log("Inside SlotMachine");
    
    // log method cannot be called. If specifier is not given then default specifier is used. Default spacifier
    // inherite like that:  class SlotMachine: private Logger. If logger is private all it content is private 
    // so there is no option to call private function from SlotMachine class. the same result can be achieved
    // when class Logger is made like that:  class Logger final{ //implementation* };

    // If function log is called within SlotMachine class it gives result for all functions.
    // Inherited log function is a private function of SlotMachine class

    //Just after adding constructor with bool debug  it was set as new constructor, but SlotMachine class
    // gave error that there is no default Logger constructor, the solution is as given:
    // add Logger(false) or Logger(true) to SlotMachine constructors initialization list
    // false or true is consider as default value


    // If both classes Stopper and Logger have methods with the same name there can be conflict which method
    // should be called
    // If both classes Stopper and Logger would have the same base class or for example Logger would be
    // a Base class for Stopper it would duplicate/multimicate memory usage

    // Java do not support multiple inheritance, but Java uses multiple interfaces 
    // user "implements" interfaces and define of override its functionality within class
    return 0;
}