#include "stos.hpp"
#include<iostream>
#include <initializer_list>
    stos::stos(int size)
    {
        std::clog<<"A"<<std::endl;
        if(size > 100 || size < 1)
        {
            throw std::invalid_argument("Rozmiar stosu musi być liczbą od 1 do 100");
        }
        pojemnosc = size;
        ile = 0;
        tablica = new std::string[pojemnosc];
    }
    stos::stos(const stos &s)
    {
        std::clog<<"B"<<std::endl;
        ile = s.ile;
        tablica = new std::string[ile];
        for(int i = 0; i < ile; i++)
        {
            tablica[i] = s.tablica[i];
        }
        pojemnosc = s.pojemnosc;
    }
    
    stos& stos::operator=(const stos &s)
    {
        return *this;
    }

    stos::stos(stos&& s)
    {
        std::clog<<"B"<<std::endl;
        ile = s.ile;
        tablica = s.tablica;
        pojemnosc = s.pojemnosc;
        s.tablica = nullptr;
    }

    stos& stos::operator=(stos&& s)
    {
        return *this;
    }

    stos::stos(const std::initializer_list<std::string>& list)
    {
        std::clog<<"C"<<std::endl;
        pojemnosc = list.size();
        tablica = new std::string[pojemnosc];
        std::string *tabptr = tablica;
        ile = pojemnosc;
        for(auto ptr = list.begin(); ptr != list.end(); ++ptr)
        {
            *tabptr = *ptr;
            tabptr++;
        }
    }

    stos::~stos() 
    {
        delete[] tablica;
    }

    void stos::wloz(const std::string& elem)
    {
       if(ile == pojemnosc)
       {
           throw std::invalid_argument("Stos pełny");
       }
       tablica[ile] = elem;
       ile++;
    }
    std::string stos::sciagnij()
    {
        if(ile == 0)
        {
            throw std::invalid_argument("Stos pusty");
        }
        ile--;
        return tablica[ile];
    }
    std::string stos::sprawdz()
    {
        if(ile == 0)
        {
            throw std::invalid_argument("Stos pusty");
        }
        return tablica[ile-1];
    }
    int stos::rozmiar()
    {
        return ile;
    }
    stos stos::odwroc()
    {
        stos nowy(pojemnosc);
        std::string item;
        for(int i = ile-1; i >= 0; i--)
        {
            nowy.wloz(tablica[i]);
        }
        return nowy;
    }
    void stos::wypisz()
    {
        for(int i = 0; i < pojemnosc; i++)
        {
           if(i < ile)
           {
               std::cout<<"|"<<tablica[i]<<"| ";
           }
           else
           {
               std::cout<<"| | ";
           }
        }
        std::cout<<"\n";
    }
    int stos::elementy()
    {
        return pojemnosc;
    }