#include "Stack.h"

void foo(Stack &s){
    try{
        for(int i = 0; i < s.getSize() + 1; i++){
            s.push(i);
            std::cout <<"Pushed:" << i << std::endl;
        }
    }
    catch(StackException e){
        std::cout <<e.what() << std::endl;
    }
}

void bar(Stack &s){
    try{
        for(int i = 0; i < s.getSize() + 1; i++){
            s.push(i);
            std::cout <<"Pushed:" << i << std::endl;
        }
    }
    catch(StackException &e){
        std::cout <<e.what() << std::endl;
    }
}

int main(){
    Stack s1(10);
    Stack s2(5);
    bool z = true;
    std::string command;
    int val;
    /*for(int i=0; i<10; i++){
        s1.push(i);
        std::cout <<"Pushed" <<std::endl;
    }
    try{
        s1.push(3729);
        std::cout <<"Pushed" <<std::endl;
    }
    catch(StackFullException e){
            std::cout << e.what() << e.getElement() << "! Max size is " << e.getMax() << std::endl;
    }
    s2.push(1);
    std::cout <<"Pushed" <<std::endl;
    std::cout << s2.pop()<< " popped"  << std::endl;
    try{
        std::cout << s2.pop()<< " popped" << std::endl;
    }
    catch(StackEmptyException e){
            std::cout << e.what() << " " << e.getaMsg() << std::endl;
    }*/

    std::cout << std::endl << "Foo call:" << std::endl;
    foo(s1);
     std::cout << std::endl << "Bar call:" << std::endl;
    bar(s1);

    while(z){
        command = "";
        std::cout <<" type 'push' to push element or 'pop' to pop element( anything else to exit) " <<std::endl;
        std::cin >> command;
        if(command == "push"){
            std::cout << "Give value to add" << std::endl;
            std::cin >>val;
            try{
                s2.push(val);
            }
            catch(StackFullException &e){
                std::cout << e.what() << e.getElement() << "! Max size is " << e.getMax() << std::endl;
            }
            catch( std::exception &e){
                std::cout << "Stndard exception" <<std::endl;
            }
            catch(...){
                std::cout << " exception " <<std::endl;
            }
        }
        else
            if(command == "pop"){
                try{
                    std::cout << s2.pop() << " popped" <<std::endl;
                }
                catch(StackEmptyException &e){
                    std::cout << e.what() << " " << e.getaMsg() << std::endl;
                }
                catch( std::exception &e){
                    std::cout << "Stndard exception" <<std::endl;
                }
                catch(...){
                    std::cout << " exception " <<std::endl;
                }
            }
            else z = false;
        
    }


    return 0;
}

//noexcept - specifies if function/method should throw exceptions - new version of throw()

//override - specifies that virtual function override another virtual function. @Override in Java inform that
//function/method below this declaration is intended to be overriden ( function do not have to be virtual) 

// Cpp do not require adding throws Exception to method header as it is in Java. Function push and pop
//throws define exceptions because of "noexcept" in StackException any other exceptions are terminated

//foo function create so called "slicing". Copy of Base StackException is created so we lose info about 
//called exceptions params (new object = new values) and we slice FullStackException functionality to
//StackException functionality 

//bar function if Exception called by reference so we get exact copy of Exception object as a Derived
//FullStackException that is why result is "Cannot push element" instead base "Invalid.."