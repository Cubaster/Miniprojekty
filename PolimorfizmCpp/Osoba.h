#pragma once
#include "Adres.h"
#include <vector>


class Person{
    protected:
        std::string *name;
        std::string *surname;
        std::string *date_of_birth;
        Address *address;

    public:

        Person(): name(nullptr), surname(nullptr), date_of_birth(nullptr),address(nullptr){}
        Person(const Person &p){

            if(p.name != nullptr){
                this->name = new std::string;
                *this->name = p.getOnlyName();
            }
            else this->name = nullptr;

            if(p.surname != nullptr){
                this->surname = new std::string;
                *this->surname = p.getOnlySurname();
            }
            else this->surname = nullptr;

            if(p.date_of_birth != nullptr){
                this->date_of_birth = new std::string;
                *this->date_of_birth = p.getDate();
            }
            else this->date_of_birth = nullptr;

            if(p.address != nullptr){
                this->address = new Address;
                this->address->setStreet(p.address->getStreet());
                this->address->setHouse(p.address->getHouse());
                this->address->setCode(p.address->getCode());
                this->address->setCity(p.address->getCity());
            }
            else this->address = nullptr;
        }

        Person(Person && p){
            this->name = p.name;
            this->surname = p.surname;
            this->date_of_birth = p.date_of_birth;
            this->address = p.address;

            p.name = nullptr;
            p.surname = nullptr;
            p.date_of_birth = nullptr;
            p.address = nullptr;
        }

        virtual ~Person(){
            if(name != nullptr) delete name;
            if(surname != nullptr) delete surname;
            if(date_of_birth != nullptr) delete date_of_birth;
            if(address != nullptr) delete address;
            std::cout << "Person freed" << std::endl;
        }

       void setName(std::string name, std::string surname){
           if(this->name == nullptr) this->name = new std::string;
           *this->name = name;
           if(this->surname == nullptr) this->surname = new std::string;
           *this->surname = surname;
       }

       std::string getName() const{
           std::string fullname = *this->name + " " + *this->surname;
           return fullname;
       }

        std::string getOnlyName() const{
           return *this->name;
       }

        std::string getOnlySurname() const{
           return *this->surname;
       }

       bool setDateOfBirth(int year, int month, int day){
           int current_year= 2020;
           if(year <= current_year){
               if(month > 0 && month <=12){
                   if(day >0 && day <=31){
                       if(month >= 10){
                        if(day >= 10) {this->date_of_birth = new std::string;
                            *this->date_of_birth = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);}
                        else {this->date_of_birth = new std::string;
                            *this->date_of_birth = std::to_string(year) + "-" + std::to_string(month) + "-0" + std::to_string(day);}
                       }
                       else{
                        if(day >= 10) { this->date_of_birth = new std::string;
                            *this->date_of_birth = std::to_string(year) + "-0" + std::to_string(month) + "-" + std::to_string(day);}
                        else {this->date_of_birth = new std::string;
                            *this->date_of_birth = std::to_string(year) + "-0" + std::to_string(month) + "-0" + std::to_string(day);}
                       }
                       return true;
                   }
               }
           }
           return false;
       }

       std::string getDate() const{
           return *this->date_of_birth;
       }

       bool setAddress(std::string street, std::string house, std::string code, std::string city){
           if(this->address == nullptr) this->address = new Address;
           if(address->setStreet(street));
           else{
               std::cout <<" Wrong street name" <<std::endl;
               return false;
           }
           if(address->setHouse(house));
           else{
               std::cout <<" Wrong house number" <<std::endl;
               return false;
           }
           if(address->setCode(code));
           else{
               std::cout <<" Wrong post code" <<std::endl;
               return false;
           }
           if(address->setCity(city));
           else{
               std::cout <<" Wrong city name" <<std::endl;
               return false;
           }
           return true;
       }

       void getAddress(){
           std::cout << "Street: " << address->getStreet() << " ";
           std::cout << address->getHouse() << std::endl;
           std::cout << "Post code: " << address->getCode() << std::endl;
           std::cout << "City: " << address->getCity() << std::endl;
       }
       // virtual - prefix to add 
      virtual void introduce(){
           std::cout << std::endl << "Introduce: " <<std::endl;
           std::cout <<"Name Surname: " << this->getName() << std::endl;
           std::cout <<"Date of birth: " << this->getDate() << std::endl;
           this->getAddress();
       }
};
