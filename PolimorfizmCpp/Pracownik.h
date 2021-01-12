#pragma once
#include "Osoba.h"

class Worker: public Person{
    private:
        std::vector<std::string> *lead_subjects;
    
    public:
        Worker(){
            this->name = nullptr;
            this->surname = nullptr;
            this->date_of_birth = nullptr;
            this->address = nullptr;
            // only lead_subjects can be initialize in initialization list
            this->lead_subjects = new std::vector<std::string>;
            this->lead_subjects->empty();
        }

        Worker(const Worker &w){
            if(w.name != nullptr){
                this->name = new std::string;
                *this->name = w.getOnlyName();
            }
            else this->name = nullptr;

            if(w.surname != nullptr){
                this->surname = new std::string;
                *this->surname = w.getOnlySurname();
            }
            else this->surname = nullptr;

            if(w.date_of_birth != nullptr){
                this->date_of_birth = new std::string;
                *this->date_of_birth = w.getDate();
            }
            else this->date_of_birth = nullptr;

            if(w.address != nullptr){
                this->address = new Address;
                this->address->setStreet(w.address->getStreet());
                this->address->setHouse(w.address->getHouse());
                this->address->setCode(w.address->getCode());
                this->address->setCity(w.address->getCity());
            }
            else this->address = nullptr;

            if(w.lead_subjects != nullptr){
                this->lead_subjects = new std::vector<std::string>;
                *this->lead_subjects = w.getSubjects();
            }
            else this->lead_subjects = nullptr;
        }

        Worker(Worker &&w){

            this->name = w.name;
            this->surname = w.surname;
            this->date_of_birth = w.date_of_birth;
            this->address = w.address;
            this->lead_subjects = w.lead_subjects;

            w.name = nullptr;
            w.surname = nullptr;
            w.date_of_birth = nullptr;
            w.address = nullptr;
            w.lead_subjects = nullptr;
        }

        ~Worker(){
            if(name != nullptr) delete name;
            if(surname != nullptr) delete surname;
            if(date_of_birth != nullptr) delete date_of_birth;
            if(address != nullptr) delete address;
            if(lead_subjects != nullptr) delete lead_subjects;
            std::cout << "Worker freed" << std::endl;
        }

        bool addSubject(std::string subject){
            for(auto it=(*lead_subjects).begin(); it != (*lead_subjects).end(); it++)
                if(*it == subject){
                    std::cout << subject << " already exists" << std::endl;
                    return false;
                }
            (*lead_subjects).push_back(subject);
            std::cout << subject << " added" << std::endl;
            return true;
        }

         bool removeSubject(std::string subject){
            for(int i = 0; i < (*lead_subjects).size(); i++)
                if((*lead_subjects)[i] == subject){
                    (*lead_subjects).erase((*lead_subjects).begin() + i); 
                    std::cout << subject << " removed" << std::endl;
                    return true;
                }
            std::cout << subject << " do not exist" << std::endl;
            return false;
        }

        void showLeadSubjects(){
            std::cout << "Led subjects: " << std::endl;
            for(auto it = (*lead_subjects).begin(); it != (*lead_subjects).end(); it++)
                std::cout << *it << std::endl;
        }

        std::vector<std::string> getSubjects() const{
            return *this->lead_subjects;
        }

        bool leadSubject(std::string subject){
            for(int i = 0; i < (*lead_subjects).size(); i++)
                if((*lead_subjects)[i] == subject){ 
                    std::cout << subject << " led by worker" << std::endl;
                    return true;
                }
            std::cout << subject << " not lead by worker" << std::endl;
            return false;
        }

        void introduce(){
           std::cout << std::endl << "Introduce: " <<std::endl;
           std::cout <<"Name Surname: " << this->getName() << std::endl;
           std::cout <<"Date of birth: " << this->getDate() << std::endl;
           this->getAddress();
           this->showLeadSubjects();
       }
        
};