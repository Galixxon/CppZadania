#ifndef _STOS_HPP
#define _STOS_HPP

#include<string>

class stos
{
    private:
        int pojemnosc;
        int ile;
        std::string* tablica;
    public:
        stos(int);
        stos() : stos(1) {};
        stos(const std::initializer_list<std::string>&);
        stos(const stos &);
        stos& operator=(const stos&);
        stos(stos&&);
        stos& operator=(stos&&);

        ~stos();
        void wloz(const std::string&);
        std::string sciagnij();
        std::string sprawdz();
        int rozmiar();
        stos odwroc();
        void wypisz();
        int elementy();

};
#endif