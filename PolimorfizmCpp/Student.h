#pragma once
#include "Osoba.h"

typedef std::vector<int> Grade;

enum subjects
{
    Object_Oriented_Programming = 0,
    Physics = 1,
    English = 2,
    Probabilistics = 3,
    Robotics = 4,
    Automatics = 5
};

class Student: public Person{
    private:
        std::vector<Grade> *grade_list;
        std::vector<std::string> subjectsNames = {"Object_Oriented_Programming", "Physics", "English",
        "Probabilistics", "Robotics", "Automatics"};

    public:
        Student(){
            this->name = nullptr;
            this->surname = nullptr;
            this->date_of_birth = nullptr;
            this->address = nullptr;
            // only grade list can be initialize in initialization list
            this->grade_list = new std::vector<Grade>;
            this->grade_list->resize(6);
        }

        Student(const Student & s){

            if(s.name != nullptr){
                this->name = new std::string;
                *this->name = s.getOnlyName();
            }
            else this->name = nullptr;

            if(s.surname != nullptr){
                this->surname = new std::string;
                *this->surname = s.getOnlySurname();
            }
            else this->surname = nullptr;

            if(s.date_of_birth != nullptr){
                this->date_of_birth = new std::string;
                *this->date_of_birth = s.getDate();
            }
            else this->date_of_birth = nullptr;

            if(s.address != nullptr){
                this->address = new Address;
                this->address->setStreet(s.address->getStreet());
                this->address->setHouse(s.address->getHouse());
                this->address->setCode(s.address->getCode());
                this->address->setCity(s.address->getCity());
            }
            else this->address = nullptr;

            if(s.grade_list != nullptr){
                this->grade_list = new std::vector<Grade>;
                this->grade_list->resize(6);
                for(int i = 0; i < 6; i++){
                    (*this->grade_list)[i] = s.getGrades(i);
                }
            }
            else this->grade_list = nullptr;
        }

        bool addGrade(int grade, int subject){
            if(grade >=1 && grade <= 5 && subject >=0 && subject <=5){
                (*grade_list)[subject].push_back(grade);
                return true;
            }
            std::cout << "Grade not added" << std::endl;
            return false;
        }

        Student(Student && s){

            this->name = s.name;
            this->surname = s.surname;
            this->date_of_birth = s.date_of_birth;
            this->address = s.address;
           // this->grade_list = s.grade_list;

            s.name = nullptr;
            s.surname = nullptr;
            s.date_of_birth = nullptr;
            s.address = nullptr;
            s.grade_list = nullptr;
        }

        ~Student(){
            if(grade_list != nullptr) delete grade_list;
            if(name != nullptr) delete name;
            if(surname != nullptr) delete surname;
            if(date_of_birth != nullptr) delete date_of_birth;
            if(address != nullptr) delete address;
            std::cout <<"Student freed" <<std::endl;
        }

        Grade getGrades(int subject) const{
            return (*grade_list)[subject];
        }

        void showGrades(int subject){
            std::cout << this->subjectsNames[subject] << ": ";
            if((*grade_list)[subject].size() > 0){
                for(auto it = (*grade_list)[subject].begin(); it != (*grade_list)[subject].end(); it++ )
                    std::cout << *it << " ";
                std:: cout << std::endl;
            }
            else std::cout << "No grades" << std::endl;
        }

        void showsubjects(){
             std::cout << "Subjects list:" << std::endl;
            for(auto it = subjectsNames.begin(); it != subjectsNames.end(); it++)
                std::cout << *it << std::endl;
            std::cout << std::endl;
        }

        void showAllGrades(){
            for(int i = 0; i < (*grade_list).size(); i++){
                std::cout << this-> subjectsNames[i] << ": ";
                for(auto it = (*grade_list)[i].begin(); it != (*grade_list)[i].end(); it++ )
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
        }

        void introduce(){
           std::cout << std::endl << "Introduce: " <<std::endl;
           std::cout <<"Name Surname: " << this->getName() << std::endl;
           std::cout <<"Date of birth: " << this->getDate() << std::endl;
           this->getAddress();
           std::cout << "   Grades list:    " << std::endl;
           this->showAllGrades();
        }
};