#include "FabrykaOsob.h"

class StudentFactory: public PersonFactory{
    public:
         Student* create();
};
