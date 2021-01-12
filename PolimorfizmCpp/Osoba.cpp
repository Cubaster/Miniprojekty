#include "Osoba.h"

int main(){
    Person p1;

    p1.setName("Tom", "Byte");

    std::cout << p1.getName() << std::endl;

    if(p1.setDateOfBirth(2020,10,23)){                   
        std::cout << p1.getDate() << std::endl;         //format YYYY-MM-DD
    }
    else{
        std::cout << " Invalid date " << std::endl;
    }

    if(p1.setAddress("Binary", "13", "54-351", "New Code"))
        std::cout << "Address set" << std::endl;

    p1.introduce();

    Person p2(p1);

    p2.setName("Tomas", "Bytes");
    if(p2.setDateOfBirth(2000,7,11));
    if(p2.setAddress("Binarys", "131", "54-352", "New Codes"));

    p2.introduce();
}