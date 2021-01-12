#include "FabrykaStudentow.h"

Student* StudentFactory::create(){
    std::string name, surname, street, house, code, city;
    int year, month, day;
    Student* s = new Student();
    std::cout << "Enter student name" << std::endl;
    std::cin >> name;
    std::cout << "Enter student lastname" << std::endl;
    std::cin >> surname;
    std::cout << "Enter student year of birth" << std::endl;
    std::cin >> year;
    std::cout << "Enter student month of birth(1-12)" << std::endl;
    std::cin >> month;
    std::cout << "Enter student day of birth(1-31)" << std::endl;
    std::cin >> day;
    std::cout << "Enter student street name" << std::endl;
    std::cin >> street;
    std::cout << "Enter student house number" << std::endl;
    std::cin >> house;
    std::cout << "Enter student post code (DD-DDD)" << std::endl;
    std::cin >> code;
    std::cout << "Enter student city name" << std::endl;
    std::cin >> city;
    
    s->setName(name, surname);
    if(!s->setDateOfBirth(year, month, day)) std::cout << "Date not set!" << std::endl;
    if(!s->setAddress(street, house, code, city)) std::cout << "Address not set!" << std::endl;

    return s;
}
