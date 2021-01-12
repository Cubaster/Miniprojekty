#include "Adres.h"

int main(){
    Address a;

    if(a.setStreet("Binary")){
        std::cout << a.getStreet() <<" ";
    }
    else std::cout << " Invalid street name" << std::endl;

    if(a.setHouse("18")){
        std::cout << a.getHouse() << std::endl;
    }
    else std::cout << " Invalid house number" << std::endl;

    if(a.setCode("54-351")){
        std::cout << a.getCode() << " ";
    }
    else std::cout << " Invalid post code" << std::endl;

    if(a.setCity("New Code")){
        std::cout << a.getCity() << std::endl;
    }
    else std::cout << " Invalid city name" << std::endl;

    Address b(a);

    if(b.setStreet("Binarys")){
        std::cout << a.getStreet() <<" ";
        std::cout << std::endl;
        std::cout << b.getStreet() <<" ";
        std::cout << std::endl;
    }
    else std::cout << " Invalid street name" << std::endl;

    if(b.setHouse("181")){
        std::cout << a.getHouse() << std::endl;
        std::cout << b.getHouse() << std::endl;
    }
    else std::cout << " Invalid house number" << std::endl;

    if(b.setCode("54-352")){
        std::cout << a.getCode() << " ";
        std::cout << std::endl;
        std::cout << b.getCode() << " ";
        std::cout << std::endl;
    }
    else std::cout << " Invalid post code" << std::endl;

    if(b.setCity("New Codes")){
        std::cout << a.getCity() << std::endl;
        std::cout << b.getCity() << std::endl;
    }
    else std::cout << " Invalid city name" << std::endl;

}