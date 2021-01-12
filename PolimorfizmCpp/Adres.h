#pragma once
#include <iostream>
#include <string>

class Address{
    protected:
        std::string *street;
        std::string *house;
        std::string *postCode;
        std::string *city;

    public:
        Address(): street(nullptr), house(nullptr), postCode(nullptr), city(nullptr){}
        Address(const Address &adr){

            if(adr.street != nullptr){
                this->street = new std::string;
                *this->street = adr.getStreet();
            }
            else this->street = nullptr;

            if(adr.house != nullptr){
                this->house = new std::string;
                *this->house = adr.getHouse();
            }
            else this->house = nullptr;

            if(adr.postCode != nullptr){
                this->postCode = new std::string;
                *this->postCode = adr.getCode();
            }
            else this->postCode = nullptr;

            if(adr.city != nullptr){
                this->city = new std::string;
                *this->city = adr.getCity();
            }
            else this->city = nullptr;
        }
        Address(Address && adr){
            street = adr.street;
            house = adr.house;
            postCode = adr.postCode;
            city = adr.city;

            adr.street = nullptr;
            adr.house = nullptr;
            adr.postCode = nullptr;
            adr.city = nullptr;
        }

       ~Address(){
            if(street != nullptr) delete street;
            if(house != nullptr) delete house;
            if(postCode != nullptr) delete postCode;
            if(city != nullptr) delete city;
        }

        bool setStreet(std::string street){
        for(auto it =street.begin(); it != street.end(); it++){
                if(!std::isalpha(*it) && !std::isspace(*it) ) return false;
            }
            if(this->street == nullptr) this->street = new std::string;
            *this->street = street;
            return true;
        }

        std::string getStreet() const{
            return *this->street;
        }

        bool setHouse(std::string house){
            auto k = house.begin();
            for(auto it = house.begin(); it != house.end(); it++){
                if( !std::isdigit(*it) || *k == '0') return false;
            }
            if(this->house == nullptr) this->house = new std::string;
            *this->house = house;
            return true;
        }

        std::string getHouse() const{
            return *this->house;
        }

        bool setCode(std::string code){
             if(code.size() != 6) return false;
             auto k = code.begin();
             auto k1 = code.begin() + 2;
             for(auto it = code.begin(); it != code.end(); it++)
             {  
                if( *k1 != '-') return false;
                if( (!std::isdigit(*it) && !(*it == *k1) ) || *k == '0') return false;
             }
             if(this->postCode == nullptr) this->postCode = new std::string;
             *this->postCode = code;
             return true;
        }

        std::string getCode() const {
            return *this->postCode;
        }

        bool setCity(std::string city){
            for(auto it = city.begin(); it != city.end(); it++){
                if((!std::isalpha(*it) && *it != ' ') && *it != '-') return false;
            }
            if(this->city == nullptr) this->city = new std::string;
            *this->city = city;
            return true;
        }

        std::string getCity() const {
            return *this->city;
        }
};