#include<iostream>
#include<vector>
#include<cmath>
double getVal(std::string s);

class Wyrazenie
{
    public:
    virtual int getPriority() = 0;
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
};


class Stala : public Wyrazenie
{
    protected:
    const int priority;
    double val;
    std::string name;
    public:
    Stala();
    int getPriority();
    double oblicz();
    std::string opis();
};

class Liczba : public Stala
{
    public:
    Liczba(double l);
};

class Pi : public Stala
{
    public:
    Pi();
};

class Fi : public Stala
{
    public:
    Fi();
};

class E : public Stala
{
    public:
    E();
};

class Zmienna : public Stala
{
    public:
    static std::vector<std::pair<std::string, double>> vars;
    static void addVar(std::string s, double val);
    private:
    double getVal(std::string s);
    protected:
    const int priority = 10;
    public:
    Zmienna(std::string n);
};



class Binop : public Wyrazenie
{
    protected:
    const int priority;
    Wyrazenie *left;
    Wyrazenie *right;

    public:
    Binop(int value, Wyrazenie *wyr1,Wyrazenie *wyr2);
    int getPriority();
};


class Dodaj : public Binop
{
    public:
    Dodaj(Wyrazenie *wyr1,Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Odejmij : public Binop
{
    public:
    Odejmij(Wyrazenie *wyr1,Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Pomnoz : public Binop
{
    public:
    Pomnoz(Wyrazenie *wyr1,Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Podziel : public Binop
{
    public:
    Podziel(Wyrazenie *wyr1, Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Log : public Binop
{
    public:
    Log(Wyrazenie *wyr1, Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Modulo : public Binop
{
    public:
    Modulo(Wyrazenie *wyr1, Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};

class Potega : public Binop
{
    public:
    Potega(Wyrazenie *wyr1, Wyrazenie *wyr2);
    double oblicz();
    std::string opis();
};


class Unop : public Wyrazenie
{
    protected:
    const int priority;
    Wyrazenie *subf;
    public:
    Unop(int val);
    int getPriority();
};

class Sin : public Unop
{
    public:
    Sin(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};


class Cos : public Unop
{
    public:
    Cos(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};

class Exp : public Unop
{
    public:
    Exp(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};

class Ln : public Unop
{
    public:
    Ln(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};

class Abs : public Unop
{
    public:
    Abs(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};

class Przeciw : public Unop
{
    public:
    Przeciw(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};

class Odwrot : public Unop
{
    public:
    Odwrot(Wyrazenie *wyr);
    double oblicz();
    std::string opis();
};
