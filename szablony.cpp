
#include "szablony.h"

int main(){
    std::cout << maximum(6, 7) << std::endl; // the same type  (int)
    std::cout << maximum(6.3, 7.3) << std::endl;    // the same type (double)
    //std::cout << maximum(6.5, 7) << std::endl;      // double vs int mismatch (collision)
    std::cout << maximum<double>(4, 5) << std::endl;    // the same type(double)
    std::cout << maximum<double>(4.1, 5.7) << std::endl;    // the same type (double)
    std::cout << maximum<int>(4.6, 3) << std::endl;         // the same type (int)
    std::cout << maximum<double>(4.6, 3) << std::endl;      // the same type (double)
    std::cout << maximum<bool>(4.6, 3) << std::endl;        // the same type (bool)
    //std::cout << maximum<std::string>(4.6, 3) << std::endl;   // invalid initialization of reference type double vs string
    std::cout << maximum<std::string>("aaa", "bb") << std::endl;  // the same type (string)

    std::cout << maximum(X(4), X(3)) << std::endl;  // require "operator <" overload
    
    std::cout << maximum(X1<int>(4), X1<int>(3)) << std::endl;
    std::cout << maximum(X1<std::string>("aaa"), X1<std::string>("bb")) << std::endl;
    
    Y<int> y;
    Y<int, double > y2;

    std::cout << typeid(y).name() <<std::endl;
    std::cout << typeid(y2).name() <<std::endl;

    A<B> ab;
    ab.f();

    bool b = maxLambda(3, 3.14);
    auto c = maxLambda(3, 3.14);

    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}