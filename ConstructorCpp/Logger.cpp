#include "Logger.h"

Logger::Logger(bool debug){this->disp = debug;}

void Logger::log(std::string data){
    time_t date;

    time(& date);
    if(disp)
    std::cout << ctime(& date) << data << std::endl;

}