#include <iostream>

template <typename T>

T maximum(T const& a, T const& b){
    return a > b ? a : b;  // ternary operator 
}

class X{
    private:
        int x;
    public:
        X(){}
        X(int _x){
            this->x = _x;
        }
        int getX() const {
            return x;
        }
        friend std::ostream& operator << (std::ostream& os, X const & x){
            os << x.x;
            return os;
        }

        bool operator > (const X & z) const {
            return this->x > z.x;
        } 

};

template <typename T>
class X1{
    private:
        T x;

    public:
        X1(){}
        X1(T _x){
            this->x = _x;
        }
        T getX1() const{
            return x;
        }
        friend std::ostream& operator << (std::ostream& os, X1 const & x){
            os << x.x;
            return os;
        }

};

template < typename T >
bool operator > (X1<T> const & a, X1<T> const & b){
            return a.getX1() > b.getX1();
        }

template <>
bool operator > (X1<std::string> const & a, X1<std::string> const & b){
    return a.getX1().size() > b.getX1().size();
}


template <typename T, typename C = X1<T> >
class Y{
    T zmienna;
    C klasaX1;
};


template <typename T>
class A{
    typename T::id i;
    public:
        void f() {i.g(); }
};

class B {
    public:
    class id{
        public:
            void g() {std:: cout << "f and g functions called" <<std::endl;}
    };
};


auto maxLambda = [](auto a, auto b) {return a > b ? a : b;}; 