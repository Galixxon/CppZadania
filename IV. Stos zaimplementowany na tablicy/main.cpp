//Kamil Galik 314570
#include<iostream>
#include "stos.hpp"



int main()
{

    const std::string info = "Opcje: \n1 - wyjmij\n2 - włóż\n3 - sprawdź element z góry\n4 - wypisz wszystkie elementy\n5 - pokaż pojemość\n6 - pokaż ilość elementów\n0 - wyjdź\n";
    
    //konstruktory
    stos *c = new stos(10);
    stos *a = new stos{"a", "b", "c"};
    stos *b = std::move(a); //przypisanie przenoszące
    //Przypisanie kopiujące
    *c = a->odwroc(); //rvalue

    delete c;
    delete b;
    

    stos *s = new stos{"Kamil", "Galik", "1233"};
    int option = 0;
    try
    {
        do
        {
            std::cout<<info<<"Wybór: ";
            std::cin>>option;
            std::string temp_string = "";
            int temp_int = 0;
            switch(option)
            {
                case 1:
                temp_string = s->sciagnij();
                std::cout<<"Zdjęty element: "<<temp_string<<"\n\n";
                break;
                case 2:
                std::cout<<"Podaj ciąg znaków do dodania do stosu: ";
                std::cin>>temp_string;
                s->wloz(temp_string);
                break;
                case 3:
                temp_string = s->sprawdz();
                std::cout<<"\nGórny element: "<<temp_string<<"\n\n";
                break;
                case 4:
                s->wypisz();
                break;
                case 5:
                temp_int = s->elementy();
                std::cout<<"\nPojemność stosu: "<<temp_int<<"\n\n";
                break;
                case 6:
                temp_int = s->rozmiar();
                std::cout<<"\nIlość elementów na stosie: "<<temp_int<<"\n\n";
                break;
                default:
                break;
            };
        }while(option != 0); 
    }
    catch(std::invalid_argument &err)
    {
        std::clog<<"Błąd stosu: "<<err.what()<<"\n";
    }
    delete s;
    return 0;
}