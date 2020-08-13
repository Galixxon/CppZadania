//Kamil Galik 314570
//Kompilowane za pomocą g++ -Wall -Wextra -g -o main main.cpp kalculator.cpp
#include<iostream>
#include "kalkulator.hpp"
#include <sstream>
#include <queue>
#include <stack>
#include <vector>


bool isNum(const std::string& num)
{
    //sprawdzenie czy wprowadzony string jest liczbą typu double, jeśli nie jest to zwracamy fałsz i zakładamy ze to zmienna
    auto p = num.begin();
    bool valid = true;
    bool dot = false;
    while(p!=num.end())
    {
        if(!std::isdigit(*p))
        {
            if(*p == '.')
            {
                if(dot)
                {
                    valid = false;
                }
                else
                {
                    dot = true;
                }
            }
            else
            {
                valid = false;
            }
        }
        ++p;
    }
    return valid;
}

double calculateONP(std::queue<std::string>& symbols, const std::vector<std::string>& name_vec)
{
    std::stack<kalkulator::symbol*> stos;
    int vec_size = name_vec.size();
    kalkulator::symbol *p, *q;
    while(symbols.empty() == 0)
    {
        std::string onp_el = symbols.front();
        symbols.pop();
        int index = 0;
        while(index<vec_size && onp_el!= name_vec[index])
        {
            ++index;
        }
        kalkulator::symbol *place;
        switch(index)
        {
            case 0:
            place = new kalkulator::pi();
            break;

            case 1:
            place = new kalkulator::fi();
            break;

            case 2:
            place = new kalkulator::e();
            break;


            case 3:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::add(q,p);
            break;

            case 4:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::sub(q,p);
            break;

            case 5:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::mult(q,p);
            break;


            case 6:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::div(q,p);
            break;

            case 7:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::modulo(q,p);
            break;

            case 8:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::min(q,p);
            break;

            case 9:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::max(q,p);
            break;

            case 10:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::log(q,p);
            break;

            case 11:
            p = stos.top();
            stos.pop();
            q = stos.top();
            stos.pop();
            place = new kalkulator::pow(q,p);
            break;


            case 12:
            p = stos.top();
            stos.pop();
            place = new kalkulator::abs(p);
            break;

            case 13:
            p = stos.top();
            stos.pop();
            place= new kalkulator::sgn(p);
            break;

            case 14:
            p = stos.top();
            stos.pop();
            place = new kalkulator::floor(p);
            break;


            case 15:
            p = stos.top();
            stos.pop();
            place = new kalkulator::ceil(p);
            break;

            case 16:
            p = stos.top();
            stos.pop();
            place = new kalkulator::frac(p);
            break;

            case 17:
            p = stos.top();
            stos.pop();
            place = new kalkulator::sin(p);
            break;

            case 18:
            p = stos.top();
            stos.pop();
            place = new kalkulator::cos(p);
            break;


            case 19:
            p = stos.top();
            stos.pop();
            place = new kalkulator::atan(p);
            break;

            case 20:
            p = stos.top();
            stos.pop();
            place = new kalkulator::acot(p);
            break;

            case 21:
            p = stos.top();
            stos.pop();
            place = new kalkulator::ln(p);
            break;

            case 22:
            p = stos.top();
            stos.pop();
            place = new kalkulator::exp(p);
            break;

            default:
            if(isNum(onp_el))
            {
                place = new kalkulator::liczba(atof(onp_el.c_str()));
            }
            else
            {
                place = new kalkulator::zmienna(onp_el);
            }
            break;
        }
        stos.push(place);
    }
    try
    {
        double ret = stos.top()->oblicz();
        return ret;
    }
    catch(std::invalid_argument& e)
    {
        std::clog<<e.what()<<std::endl;
        return 0;
    }
}

int main()
{
    const std::vector<std::string> name_vec = {"pi", "fi", "e", "+", "-", "*", "/", 
                                        "modulo", "min", "max", "log", "pow", 
                                        "abs", "sgn", "floor", "ceil", "frac", "sin", 
                                        "cos", "atan", "acot", "ln", "exp"};
    std::string input;
    std::string option;
    bool run = true;
    do
    {
        std::cout<<"ONP interpreter:> ";
        std::getline(std::cin, input);
        std::istringstream input_stream(input);
        input_stream>>option;
        if(option == "print")
        {
            std::string s;
            std::queue<std::string> symbols;
            do
            {
                input_stream>>s;
                symbols.push(s);
            }while(input_stream.rdbuf()->in_avail() != 0);

            std::cout<<calculateONP(symbols, name_vec)<<std::endl;
        }
        else if(option == "assign")
        {
            std::string s;
            std::queue<std::string> symbols;
            input_stream>>s;
            while(s != "to" && input_stream.rdbuf()->in_avail() != 0)
            {
                symbols.push(s);
                input_stream>>s;
            }
            if(s=="to")
            {
                double res = calculateONP(symbols, name_vec);
                input_stream>>s;
                kalkulator::zmienna::assign(s,res);
            }
            else
            {
                std::clog<<"Wrong command structure: assign <ONPprocedure> to <variable name>"<<std::endl;
            }
        }
        else if(option == "clear")
        {
            kalkulator::zmienna::clear();
        }
        else if(option == "exit")
        {
            run = 0;
        }
        else
        {
            std::clog<<"Invalid command"<<std::endl;
        }
    }while(run);
    
    return 0;
}