#include <algorithm>
#include <vector>
#include <set>
#include "samochod.h"

int main(){
    float km;
    std::string modified_model;
    Car s1(123, "audi");
    Car s2(0, "bmw");
    Car s3(200, "");
    Car s4(38, "fiat");

    if(s1){
        std::cout << "s1 bool" << std::endl;       //print (overload bool) conditions met
    }
    if(!s1){
        std::cout <<"s1 not" << std::endl;        //print (overload !) conditions met
    }

    if(s2){
        std::cout << "s2 bool" << std::endl;       // do not print (overload bool) capacity = 0
    }

    if(!s2){
        std::cout << "s2 not" << std::endl;        // do not print (overload !) capacity = 0
    }

    if(s3){
        std::cout << "s3 bool" << std::endl;       // do not print (overload bool) model = ""
    }

    if(!s3){
        std::cout << "s3 not" << std::endl;        // do not print (overload !) model = ""
    }

    std::cout << "cout: " << s1 << std::endl;       // testing cout overload 

    std::cout << "vector" << std::endl;

    std::vector <Car> v;                //testing < overload  order: s3(""), s1("a"), s2("b"), s4("f")
    v.push_back(s1);
    v.push_back(s4);
    v.push_back(s2);
    v.push_back(s3);
    std::sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it;

    std::cout << std::endl;
    std::cout << "set" << std::endl;

    /*
    Alternative from Stack (C++ 11)
    
    auto cmp = [](const Car &car1, const Car &car2)
    { return car1.get_tank_capacity() < car2.get_tank_capacity(); };
    std::set<Car, decltype(cmp)> s(cmp);
    */

    std::set<Car, cmp> s;              // testing comparision overload () order: s2(0), s4(38), s1(123), s3(200)
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    s.insert(s4);
    for(auto it = s.begin(); it != s.end(); it++)
        std::cout << *it;

    std::cout << std::endl;
    std::cout << "new operators" <<std::endl;

    km = s1.get_kilometers();
    std::cout << "old distance: " << km << std::endl;
    ++s1;                                           // overload "++" - add 10 to current kilometers
    km = s1.get_kilometers();
    std::cout << "new distance: " << km << std::endl;
    s2.move(25);        // s2.kilometers 5 + 25 = 30 
    s3.move(20);        // s3.kilometers 5 + 20 = 25
    s1 = (s1,s2,s3);       // overload "," s2.kilometers = s3.kilometers then s1.kilometers = s2.kilometers 
    km = s1.get_kilometers();
    std::cout << "comma distance: " << km << std::endl;

    modified_model = s4.get_model();
    std::cout << "old model: " << modified_model << std::endl;
    s4 |= s1;                                                      //overload "|=" - concatenate strings
    modified_model = s4.get_model();
    std::cout << "new model: " << modified_model << std::endl;

    return 0;
}