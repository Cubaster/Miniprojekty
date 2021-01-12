#include "FabrykaPracownikow.h"

Worker* WorkerFactory::create(){
    std::string name, surname, street, house, code, city;
    int year, month, day;
    bool date, address;
    Worker* w = new Worker();
    std::cout << "Enter worker name" << std::endl;
    std::cin >> name;
    std::cout << "Enter worker lastname" << std::endl;
    std::cin >> surname;
    std::cout << "Enter worker year of birth" << std::endl;
    std::cin >> year;
    std::cout << "Enter worker month of birth(1-12)" << std::endl;
    std::cin >> month;
    std::cout << "Enter worker day of birth(1-31)" << std::endl;
    std::cin >> day;
    std::cout << "Enter worker street name" << std::endl;
    std::cin >> street;
    std::cout << "Enter worker house number" << std::endl;
    std::cin >> house;
    std::cout << "Enter worker post code (DD-DDD)" << std::endl;
    std::cin >> code;
    std::cout << "Enter worker city name" << std::endl;
    std::cin >> city;

    w->setName(name, surname);
    if(!w->setDateOfBirth(year, month, day)){std::cout << "Date not set!" << std::endl;}
    if(!w->setAddress(street, house, code, city)) std::cout << "Address not set!" << std::endl;

    return w;
}