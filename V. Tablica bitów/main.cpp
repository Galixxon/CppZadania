//Kamil Galik 314570
#include<iostream>
#include "tabbit.hpp"

int main()
{
    tab_bit t(46);
    tab_bit u(45ul);
    tab_bit v(t);
    tab_bit w(tab_bit {1,0,1,1,0,1,1});
    v[1] = 1;
    t[45] = 1;
    t[5] = 1;
    bool b = v[1];
    u[63] = 1;
    u[45] = u[46] = u[63];
    u[63] = 0;
    u[45] = false;
    std::cout<<"T array: "<<t<<std::endl;
    std::cout<<"U array: "<<u<<std::endl;
    std::cout<<"V array: "<<v<<std::endl;
    std::cout<<"W array: "<<w<<std::endl;
    std::cout<<"Value of v[1]: "<<b<<std::endl;
    std::cout<<"W^U: "<<(w^u)<<std::endl;
    std::cout<<"W&U: "<<(w&u)<<std::endl;
    std::cout<<"W|U: "<<(w|u)<<std::endl;
    std::cout<<"!W: "<<(!w)<<std::endl;

    t |= u;
    std::cout<<"t |= u:"<<t<<std::endl;
    t ^= w;
    std::cout<<"t ^= w:"<<t<<std::endl;
    u &= w;
    std::cout<<"u &= w:"<<u<<std::endl;
    return 0;
}