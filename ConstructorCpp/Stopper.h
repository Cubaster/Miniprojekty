#pragma once
#include <ctime>

class Stopper{
    private:
        clock_t begin_time;
        clock_t end_time;
    public:
        void start();
        void stop();
        void reset();
        double getTime();
};