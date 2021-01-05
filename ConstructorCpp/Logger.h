#pragma once
#include <iostream>
#include <ctime>

class Logger{
    private:
        bool disp;
    public:
        Logger(bool debug);
        void log(std::string data);

};