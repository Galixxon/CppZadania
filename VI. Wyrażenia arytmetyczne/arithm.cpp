#include "arithm.hpp"

Stala::Stala() : priority(5) {}
int Stala::getPriority()
{
    return priority;
}
double Stala::oblicz()
{
    return val;
}
std::string Stala::opis()
{
    return name;
}

Liczba::Liczba(double l) : Stala()
{
    val = l;
    name = std::to_string(val);
}

Pi::Pi() : Stala()
{
    val = 3.14159265;
    name = "pi";
}

Fi::Fi() : Stala()
{
    val = 1.6180339887;
    name = "fi";
}

E::E() : Stala()
{
    val = 2.718281828459;
    name = "e";
}

void Zmienna::addVar(std::string s, double val)
{
    int notFoundFlag = 1;
    for(auto& p : vars)
    {
        if(p.first == s)
        {
            notFoundFlag = 0;
            p.second = val;
        }
    }
    if(notFoundFlag)
    {
        vars.push_back(std::pair<std::string, double>(s,val));
    }
}
double Zmienna::getVal(std::string s)
{
    for(auto& p : vars)
    {
        if(p.first == s)
        {
            return p.second;
        }
    }
    throw std::invalid_argument("Var not found");
}
Zmienna::Zmienna(std::string n) : Stala()
{
    name = n;
    val = getVal(name);
}

Binop::Binop(int value, Wyrazenie *wyr1,Wyrazenie *wyr2) : priority(value)
{
    left = wyr1;
    right = wyr2;
}
int Binop::getPriority()
{
    return priority;
}

Dodaj::Dodaj(Wyrazenie *wyr1,Wyrazenie *wyr2) : Binop(1, wyr1,wyr2){}
double Dodaj::oblicz()
{
    return left->oblicz() + right->oblicz();
}
std::string Dodaj::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    return l_string + "+" + r_string;
}

Odejmij::Odejmij(Wyrazenie *wyr1,Wyrazenie *wyr2) : Binop(1,wyr1,wyr2){}
double Odejmij::oblicz()
{
    return left->oblicz() - right->oblicz();
}
std::string Odejmij::opis()
{
    std::string ret = left->opis();
    if(right->getPriority() == priority)
    {
        ret += "-(" + right->opis() +")";
    }
    else
    {
        ret += "-" + right->opis();
    }
    return ret;
}

Pomnoz::Pomnoz(Wyrazenie *wyr1,Wyrazenie *wyr2) : Binop(2,wyr1,wyr2){}
double Pomnoz::oblicz()
{
    return left->oblicz() * right->oblicz();
}
std::string Pomnoz::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    if(left->getPriority() < priority)
    {
        l_string = "(" + l_string + ")";
    }
    if(right->getPriority() < priority)
    {
        r_string = "(" + r_string + ")";
    }
    return l_string + "*" + r_string;
}

Podziel::Podziel(Wyrazenie *wyr1, Wyrazenie *wyr2) : Binop(2,wyr1,wyr2){}
double Podziel::oblicz()
{
    double temp = right->oblicz();
    if(temp == 0.0)
    {
        throw std::invalid_argument("Division by 0");
    }
    return left->oblicz() / temp;
}
std::string Podziel::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    if(left->getPriority() < priority)
    {
        l_string = "(" + l_string + ")";
    }
    if(right->getPriority() < priority)
    {
        r_string = "(" + r_string + ")";
    }
    return l_string + "/" + r_string;
}

Log::Log(Wyrazenie *wyr1, Wyrazenie *wyr2) : Binop(4,wyr1,wyr2){}
double Log::oblicz()
{
    double x = right->oblicz();
    double b = left->oblicz();
    if(x <= 0 || b == 1)
    {
        throw std::invalid_argument("Logarithm arguments not valid.");
    }
    else
    {
        return log10(x)/log10(b);
    }
}
std::string Log::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    if(left->getPriority() < priority)
    {
        l_string = "(" + l_string + ")";
    }
    if(right->getPriority() < priority)
    {
        r_string = "(" + r_string + ")";
    }
    return "log(" + l_string + "," + r_string + ")";
}

Modulo::Modulo(Wyrazenie *wyr1, Wyrazenie *wyr2) : Binop(3,wyr1,wyr2){}
double Modulo::oblicz()
{
    double temp = right->oblicz();
    if(temp == 0.0)
    {
        throw std::invalid_argument("a mod 0 is undefined");
    }
    return fmod(left->oblicz(), temp);
}
std::string Modulo::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    if(left->getPriority() < priority)
    {
        l_string = "(" + l_string + ")";
    }
    if(right->getPriority() < priority)
    {
        r_string = "(" + r_string + ")";
    }
    return l_string + "%" + r_string;
}

Potega::Potega(Wyrazenie *wyr1, Wyrazenie *wyr2) : Binop(3,wyr1,wyr2){}
double Potega::oblicz()
{
    return pow(left->oblicz(), right->oblicz());
}

std::string Potega::opis()
{
    std::string l_string = left->opis();
    std::string r_string = right->opis();
    if(left->getPriority() < priority)
    {
        l_string = "(" + l_string + ")";
    }
    if(right->getPriority() < priority)
    {
        r_string = "(" + r_string + ")";
    }
    return l_string + "^" + r_string;
}

Unop::Unop(int val) : priority(val) {}
int Unop::getPriority()
{
    return priority;
}

Sin::Sin(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Sin::oblicz()
{
    return sinf32x(subf->oblicz());
}
std::string Sin::opis()
{
    return "sin(" + subf->opis() + ")";
}


Cos::Cos(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Cos::oblicz()
{
    return cosf32x(subf->oblicz());
}
std::string Cos::opis()
{
    return "cos(" + subf->opis() + ")";
}


Exp::Exp(Wyrazenie *wyr) : Unop(3)
{
    subf = wyr;
}
double Exp::oblicz()
{
    double ret = pow(2.718281828459,subf->oblicz());
    return ret;
}
std::string Exp::opis()
{
    return "exp(" + subf->opis() + ")";
}

Ln::Ln(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Ln::oblicz()
{
    return log(subf->oblicz());
}
std::string Ln::opis()
{
    return "ln(" + subf->opis() + ")";
}

Abs::Abs(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Abs::oblicz()
{
    return abs(subf->oblicz());
}
std::string Abs::opis()
{
    return "abs(" + subf->opis() + ")";
}


Przeciw::Przeciw(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Przeciw::oblicz()
{
    return -(subf->oblicz());
}
std::string Przeciw::opis()
{
    std::string ret;
    if(subf->getPriority() < 10)
    {
        ret = "-(" + subf->opis() + ")";
    }
    else
    {
        ret = "-" + subf->opis();
    }
    return ret;
}

Odwrot::Odwrot(Wyrazenie *wyr) : Unop(4)
{
    subf = wyr;
}
double Odwrot::oblicz()
{
    double ret = subf->oblicz();
    if(ret == 0.0f)
    {
        throw std::invalid_argument("Division by 0");
    }
    return 1.0/ret;
}
std::string Odwrot::opis()
{
    std::string ret;
    if(subf->getPriority() < 10)
    {
        ret = "1/(" + subf->opis() + ")";
    }
    else
    {
        ret = "1/" + subf->opis();
    }
    return ret;
}

std::vector<std::pair<std::string,double>> Zmienna::vars;