#include <iostream>

class Car{
    private:
        float tank_capacity;
        float fuel_level;
        unsigned int kilometers;
        std::string model;
    
    public:
        Car(){ 
            this->tank_capacity = 40.2;
            this-> fuel_level = 10.3;
            this->kilometers = 5;
            this->model = "";
        }

        Car(float capacity, std::string model){
            this->tank_capacity = capacity;
            this-> fuel_level = 10.3;
            this->kilometers = 5;
            this->model = model;
        }

        float get_fuel_level() {
            return this->fuel_level;
        }

        float get_tank_capacity() const {
            return this->tank_capacity;
        }

        unsigned int get_kilometers() {
            return this->kilometers;
        }

        std::string get_model() {
            return this->model;
        }


        bool tank(float amount){
            if(this->fuel_level + amount <= this->tank_capacity){
                this->fuel_level += amount;
                return true;
            }
            return false;
        }

        void move(unsigned int distance) {
            this->kilometers += distance;
        }

        operator bool () const{
            if(this->model != "" && this->tank_capacity > 0) return true;
            return false;
        }
        
        bool operator !() const{
            if(this->model != "" && this->tank_capacity > 0) return true;
            return false;
        }
        
        // friend method  - allows "ostream" to access private memebers of Car object 

        friend std::ostream& operator << (std::ostream &os, const Car &car){
            os << car.model << " " << car.fuel_level << "\n";
            return os;
        } 

        // const after method name is used to prevent modifications on Car attributes and allows
        // const Car  invoke const method
        // example: model = "audi" , within method: model = "bwm" - error const method (model cannnot be modified)

        bool operator < (const Car &car) const {
            return this->model < car.model;
        }

        Car& operator ++ (){
           this->move(10);
           return *this; 
        }

        Car& operator, (const Car &car){
            this->kilometers = car.kilometers;
            return *this; 
        }

        Car& operator |= (const Car &car){
            this->model += car.model;
            return *this;
        }
};

struct cmp{
    bool operator() (const Car &car1, const Car &car2) const {
        return car1.get_tank_capacity() < car2.get_tank_capacity();
    }
};