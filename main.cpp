#include<iostream>
#include "tabbit.hpp"

int main()
{
    tab_bit t(12ul);
    tab_bit c{1,0,1,0};
    tab_bit a(10);
    a[2] = 1;
    a[6] = 2;
    std::cout<<a<<std::endl<<t<<std::endl;
    std::cout<<(c|a)<<std::endl;
    return 0;
}