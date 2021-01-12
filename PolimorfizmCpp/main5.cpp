#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"
#include <map>
#include <vector>

void foo(Person &p){
    p.introduce();
}

void bar (Person *p){
    p->introduce();
}

int main(){
    //Person k;
    //Student k;
    Worker k;

    k.setName("Tommy", "Bytes");
    if(k.setDateOfBirth(2000,07,4));
    if(k.setAddress("Octal", "17", "64-381", "New Line"));
    //k.addGrade(4, Physics);

    
    std::cout << "foo result:" << std::endl;
    foo(k);

    std::cout << std::endl << "bar result:" << std::endl;
    bar(&k);

    // Person:
    // Results for Person introduce are the same, although bar function require &p as a parameter

    // Student:
    // Foo and bar show the same result, they display Person introduce instead of Student introduce

    // Worker:
    // Foo and bar show the same result, they display Person introduce instead of Worker introduce

    // Summary:
    // There is no difference between Person, Student and Worker introduce because foo and bar functions 
    // cast object as a Person class 
    // Example: Student s; call foo(s)  result:  Person::introduce() is called, not Student::introduce()

                                    //Virtual call bar and foo functions

    /*
        std::cout << "foo result:" << std::endl;
        foo(k);

        std::cout << std::endl << "bar result:" << std::endl;
        bar(&k);
    */ 

    // Person:
    // Foo and bar show the same result, as it was without virtual function
    
    // Student:
    // Foo and bar show the same result, but both functions invoke Student introduce

    // Worker:
    // Foo and bar show the same result, but both functions invoke Worker introduce

    // Virtual function "introduce()"" ensure that the correct function is called for an object, regardless 
    // Person reference in foo and bar functions
    // Example: Student s; call foo(s)  result:  Student::introduce() is called, not Person::introduce()

    /*
        Worker *p1 = new Worker;
        std::cout << std::endl << "bar p1(Worker) result: " << typeid(p1).name() << std::endl;
      //  p1->setAddress("New Line", "12", "56-987", "Run"); // added after lazy loading to prevent segmentation fault
        bar(p1);
        Person *o1 = static_cast<Person*>(p1);
        std::cout << std::endl << "bar o1(cast p1 to Person) result:" << typeid(o1).name() << std::endl;
        bar(o1);
        Person *o2 = static_cast<Worker*>(o1);
        std::cout << std::endl << "bar o2(cast o1 to Person) result:" << typeid(o2).name() << std::endl;
        bar(o2);
    */

    // Derived Worker p1  "Person cast" to Base Person o1 // OK
    // Base Person o1 "Worker cast" to Base Person o2 // not OK  
    // Result: Worker p1, Person o1, Person o2
    // bar function returns Worker functionality for p1, o1 and o2

    /* 
        Person *o3 = new Person;
        std::cout << std::endl << "bar o3(Person) result:" << typeid(o3).name() << std::endl;
        //o3->setAddress("New Lines", "32", "46-987", "Runers");
        bar(o3);
        Worker *p2 = static_cast<Worker*>(o3);
        std::cout << std::endl << "bar p2(cast o3 to Worker) result:" << typeid(p2).name() << std::endl;
        bar(p2);
    */

    // Base Person o3 "Worker cast" to Derived Worker p2 // OK  
    // Result: Person o3, Worker p2

    /*
        Worker *p3 = new Worker;
        std::cout << std::endl << "bar p3(Worker) result:" << typeid(p3).name() << std::endl;
        p3->setAddress("Old Line", "62", "46-587", "Compiler");
        bar(p3);
        Person *o4 = dynamic_cast<Person*>(p3);
        std::cout << std::endl << "bar o4(Person) result:" << typeid(o4).name() << std::endl;
        bar(o4);
    */
    /*  Worker *p4 = dynamic_cast<Person *>(o4);
        std::cout << std::endl << "bar p4(Worker) result:" << typeid(p4).name() << std::endl;
        bar(p4);
    */

    // Derived Worker p3 "Person dynamic cast" to Base Person o4 // OK
    // Base Person o4 "Person dynamic cast" to Derived Worker p4 // compilation fail 
    // bar function returns Worker functioanlity for p3 and o4
   
   /*
    Person *o5 = new Person;
    Worker *p5 = dynamic_cast<Worker*>(o5);
    if(p5 == nullptr) std::cout << "Cast error" << std::endl;
    else p5->showLeadSubjects();
    */

    // dynamic_cast failed and returned nullptr

    // "dynamic_cast != nullptr" should be avoid. If dynamic_cast fail and return nullptr program
    // will stop or crash

    // virtual void introduce() = 0 makes Person pure virtual class


                                        //After adding lazy loading

    // few attempts gave results as given below this comment but there were a problem with foo and bar functions
    // in most cases Derived class destructor was called but Base class (Person) costructor call caused error
    // (cannnot access memory at address - after research memory already freed). Virtual destructor in Base class 
    // do not solved the problem - to sum up unpredictable destructor call

    // Person p -  foo(p) and bar(&p) works the same as it was before lazy loading - Person result

    // Student p -  foo(p) and bar(&p) works the same as it was before lazy loading - Person result

    // Worker p -  foo(p) and bar(&p) works the same as it was before lazy loading - Person result

                                        //Virtual

    // Person p -  foo(p) and bar(&p) works the same as it was before lazy loading - Person result 

    // Student p -  foo(p) and bar(&p) works the same as it was before lazy loading - Student result 

    // Worker p -  foo(p) and bar(&p) works the same as it was before lazy loading - Worker result 

    // Class attributes must be defined  for example Person p1* = new Person; p1->setAttribute(); or
    // mechanism within class to prevent nullptr return or else "segmentation fault error"


    // Worker p1 Person o1, o2 the same result as it was before lazy loading

    // Person o3, Worker p2 the same result as it was before

    // Person o4, Worker p3, p4 the same result

    // while using dynamic cast on "o5" returns nullptr function works

    // PersonFactory is an abstract class so map object will refer to Worker/Student - Factory thi allow to create students and workers
    std::vector<Person*> personArray;
    std::map<std::string, PersonFactory*>m;
    bool go = true;
    std::string currentCommand;
    m["worker"] = new WorkerFactory();
    m["student"] = new StudentFactory();

    while(go){
        std::cout << "commands: 'worker', 'student', 'show', 'quit'" << std::endl;
        std::cin >> currentCommand;
        if(currentCommand == "worker"){
            personArray.push_back(m[currentCommand]->create());
        }
        if(currentCommand == "student"){
            personArray.push_back(m[currentCommand]->create());
        } 
         if(currentCommand == "show"){
             for(int i = 0; i < personArray.size(); i++){
                 std::cout <<std::endl;
                 personArray[i]->introduce();
             }
         }
         if(currentCommand == "quit") go = false;
    }

    // As predicted map with abstract class allow to call derived class and create Students and Workers instead of Person

    return 0;
}