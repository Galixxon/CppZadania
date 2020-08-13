//Kod kompilowany z flagą -std=c++11
#include <iostream>
#include "pomoc.hpp"

int main()
{
    try
    {
        wektor w1(2,3);
        wektor w2(4,7);

        punkt a(6,1);
        punkt b(a,w1);
        punkt c(-3,1);
        punkt copy(c);

        prosta pr1(w2);
        prosta pr2(3,4,5);
        prosta prtemp(6,8,10);
        prosta prostaA(2,4,5);
        prosta prostaB(5,2,1);
        prosta pr3(w1,pr1);


        std::cout<<"pkt c na prostej pr2: "<<pr2.czyPktNaProstej(c)<<"\n";
        std::cout<<"Czy proste pr1 i pr2 równoległę: "<<prosta::czyProsteRownolegle(pr1,pr2)<<"\n";
        std::cout<<"Czy proste pr1 i prtemp równoległę: "<<prosta::czyProsteRownolegle(pr1,prtemp)<<"\n";
        std::cout<<"Prosta2: "<<pr2.getA()<<" "<<pr2.getB()<<" "<<pr2.getC()<<"\n";
        printf("c(%lf,%lf), copy(%lf,%lf)\n", c.x,c.y,copy.x,copy.y);
        punkt p = prosta::przeciecie(prostaA,prostaB);
        printf("punkt przeciecia O(%lf,%lf)\n",p.x,p.y);
    }
    catch(std::invalid_argument &error)
    {
        std::cout<<"Error invalid_argiment: "<<error.what()<<std::endl;
    }
    

    return 0;
}