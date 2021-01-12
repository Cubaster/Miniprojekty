#include "Student.h"

int main(){
    Student s;

    s.setName("Tommy", "Bytes");

    //std::cout << s.getName() << std::endl;

    if(s.setDateOfBirth(2000,07,4));/*{                   
        std::cout << s.getDate() << std::endl;         //format YYYY-MM-DD
    }
    else{
        std::cout << " Invalid date " << std::endl;
    }*/

    if(s.setAddress("Octal", "17", "64-381", "New Line"));
        //std::cout << "Address set" << std::endl;

    s.showsubjects();
    s.addGrade(5, Physics);
    s.addGrade(4, Physics);
    s.addGrade(0, Physics);
    Student s1(s);
    s.showGrades(Physics);
    s.showGrades(English);
    std::cout << std::endl;
    s.showAllGrades();
    s.introduce();

   
   s1.addGrade(4,Object_Oriented_Programming);
   s1.introduce();

   s.introduce();


}