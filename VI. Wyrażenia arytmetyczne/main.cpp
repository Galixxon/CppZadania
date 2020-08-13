//Kamil Galik 314570
#include<iostream>
#include "arithm.hpp"

int main()
{
    Zmienna::addVar("x", 2);
    Zmienna::addVar("y", 2);
    Wyrazenie *w;
    
    for(double i = 0.0; i < 1.01; i+= 0.01)
    {
        Zmienna::addVar("x", i);
        w = new Podziel(
            new Pomnoz(
                new Odejmij(
                    new Zmienna("x"),
                     new Liczba(1)
                     ),
                new Zmienna("x")
                ),
            new Liczba(2)
        );
        std::cout<<w->opis()<<std::endl;
        std::cout<<"wartosc dla x="<<i<<"-> "<<w->oblicz()<<"\n"<<std::endl;
        delete[] w;
        w = new Podziel(
                new Dodaj(
                    new Liczba(3),
                    new Liczba(5)
                    ),
                new Dodaj(
                    new Liczba(2),
                    new Pomnoz(
                        new Zmienna("x"),
                        new Liczba(7)
                    )
                )
            );
        std::cout<<w->opis()<<std::endl;
        std::cout<<"wartosc dla y=2 x="<<i<<"-> "<<w->oblicz()<<"\n"<<std::endl;
        delete[] w;
        w = new Dodaj(
            new Liczba(2),
            new Odejmij(
                new Pomnoz(
                    new Zmienna("x"),
                    new Liczba(7)
                ),
                new Dodaj(
                    new Pomnoz(
                        new Zmienna("y"),
                        new Liczba(3)
                    ),
                    new Liczba(5)
                )
            )
        );
        std::cout<<w->opis()<<std::endl;
        std::cout<<"wartosc dla y=2 x="<<i<<"-> "<<w->oblicz()<<"\n"<<std::endl;
        delete[] w;
        w = new Podziel(
                new Cos(
                    new Pomnoz(
                        new Dodaj(
                            new Zmienna("x"),
                            new Liczba(1)
                            ),
                        new Zmienna("x")
                        )
                    ),
                new Potega(
                    new E(),
                    new Potega(
                        new Zmienna("x"),
                        new Liczba(2)
                    )
                )
            );
        std::cout<<w->opis()<<std::endl;
        std::cout<<"wartosc dla y=2 x="<<i<<"-> "<<w->oblicz()<<"\n"<<std::endl;
        delete[] w;
    }

    return 0;
}
