#include "FabrykaOsob.h"

class WorkerFactory: public PersonFactory{
    public:
        virtual Worker* create();
};
