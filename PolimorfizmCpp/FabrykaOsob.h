#pragma once
#include "Pracownik.h"
#include "Student.h"

class PersonFactory{
    public:
        virtual Person* create() = 0;

};