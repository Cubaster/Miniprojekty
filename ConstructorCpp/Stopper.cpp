#include "Stopper.h"

void Stopper::start(){
     begin_time = clock();
}

void Stopper::stop(){
    end_time = clock();
}

void Stopper::reset(){
    begin_time = NULL;
    end_time = NULL;
}

double Stopper::getTime(){
    return difftime(end_time, begin_time)/ (long long) CLOCKS_PER_SEC;
}

