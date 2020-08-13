//Kamil Galik 314570
//Całą implementację listy zawarłem w pliku list.hpp. Próba rozbicia tego na pliki .hpp i .cpp skończyła się lawiną blędów "undefined reference",
//a źródła internetowe podpowiedzialy by trzymać to wszytko w jednym pliku. 
#include<iostream>
#include "list.hpp"

int main()
{
    //normalny konstruktor
    list<float> *fl_list = new list<float>();
    fl_list->addElem(1.32,0);
    fl_list->addElem(2.4,1);
    fl_list->addElem(0.34,2);
    fl_list->addElem(-0.1,1);
    std::cout<<*fl_list<<std::endl;

    //konstruktor z initializer list
    list<int> ayy({2,3,4,5});
    std::cout<<"List from initializer list \"ayy\": "<<ayy<<std::endl;

    //konstruktor kopiujący
    list<int> *l = new list<int>(ayy);
    l->addElem(10,0);
    l->addElem(16,1);
    l->addElem(12,2);
    l->addElem(11,5);
    std::cout<<"Copied list form ayy: "<<*l<<std::endl;
    l->delElem(4);
    std::cout<<"Deleted one element [4] from list above: "<<*l<<std::endl;
    std::cout<<"Counted elements of this list: "<<l->countElems()<<std::endl;
    
    //konstruktor przenoszący
    list<int> *a = new list<int>(std::move(ayy));

    std::cout<<"Index of element with value 12: "<<a->findElem(12)<<std::endl;

    return 0;
}