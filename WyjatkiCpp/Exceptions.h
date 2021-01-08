#include <exception>
#include <iostream>
#include <string>

class StackException: public std::exception{
    public:
        StackException() {};
        virtual const char* what() const noexcept override{
            return "Invalid operation at stack!";
        }
};

class StackFullException : public StackException{
        int element = 0;
        int maxStackSize = 0;
        std::string message;
    public:
        StackFullException() {};
        StackFullException(std::string msg, int elem, int size){
            this->element = elem;
            this->maxStackSize = size;
            this->message = msg;
        }

        virtual const char* what() const noexcept override{
            return "Cannot push element ";
        }

        int getElement(){
            return element; 
        }

        int getMax(){
            return maxStackSize;
        }
};


class StackEmptyException : public StackException{
        std::string message;
    public:
        StackEmptyException() { }
        StackEmptyException(std::string msg): message(msg) { }

        virtual const char* what() const noexcept override{
            return "Cannot pop!";
        } 

        std::string getaMsg(){
            return message;
        }

};