#include "Pracownik.h"

int main(){
    Worker w;

    w.showLeadSubjects();
    std::cout << std::endl << std::endl;

    w.addSubject("English");
    w.addSubject("Automatics");
    w.addSubject("Robotics");
    std::cout << std::endl << std::endl;
    w.showLeadSubjects();
    std::cout << std::endl << std::endl;
    w.removeSubject("Automatics");
    std::cout << std::endl << std::endl;
    w.showLeadSubjects();

    std::cout << std::endl << std::endl;
    w.leadSubject("Robotics");
    w.leadSubject("Automatics");

    std::cout << std::endl << std::endl;

    w.setName("James", "Vector");

    //std::cout << s.getName() << std::endl;

    if(w.setDateOfBirth(1978,3,14));/*{                   
        std::cout << s.getDate() << std::endl;         //format YYYY-MM-DD
    }
    else{
        std::cout << " Invalid date " << std::endl;
    }*/

    if(w.setAddress("Deimal", "84", "63-281", "New Compiler"));
        //std::cout << "Address set" << std::endl;

    w.introduce();

    Worker w1(w);

    if(w1.setDateOfBirth(1989,6,21));
    w1.removeSubject("English");
    w1.addSubject("Mathematics");
    
    w1.introduce();

    return 0;
}