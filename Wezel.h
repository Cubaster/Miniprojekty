#include <iostream>
#include <memory>

class Wezel{
    private:
        std::shared_ptr<Wezel> w;
        std::weak_ptr<Wezel> wp;
    public:
        Wezel();
        ~Wezel();
        void next(std::shared_ptr<Wezel> n);
        void weaknext(std::weak_ptr<Wezel> n);

};

Wezel::Wezel(){};

Wezel::~Wezel(){
    std::cout << "Destrukcja_obiektu" << std::endl;
}

void Wezel::next(std::shared_ptr<Wezel> n){
    w = n;
}

void Wezel::weaknext(std::weak_ptr<Wezel> n){
    wp = n;
}