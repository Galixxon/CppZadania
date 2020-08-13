#include "pomoc.hpp"
#include <cmath>
#include <iostream>


void prosta::normuj()
{
    double delta;
    if(c > 0)
    {
        delta = (sqrt(a*a + b*b));
    }
    else
    {
        delta = -(sqrt(a*a + b*b));
    }
    a /= delta;
    b /= delta;
    c /= delta;
}
    
double prosta::getA()
{
    return a;
}

double prosta::getB()
{
    return b;
}

double prosta::getC()
{
    return c;
}

prosta::prosta(const punkt &pkt1, const punkt &pkt2)
{
    a = pkt2.y-pkt1.y;
    b = pkt1.x-pkt2.x;
    c = pkt2.x*pkt1.y - pkt1.x * pkt2.y;
    normuj();
}
prosta::prosta(const wektor &vec)
{
    b = -1;
    a = -(vec.dx)/(vec.dy);
    c = ((vec.dx*vec.dx)+(vec.dy*vec.dy))/vec.dy;
    normuj();
}
prosta::prosta(const double &A,const double &B,const double &C)
{
    if(A == 0 && B == 0)
    {
        throw std::invalid_argument("A i B nie mogą być 0");
    }
    a = A;
    b = B;
    c = C;
    normuj();
}
prosta::prosta(const wektor &vec, const prosta &pr)
{
    c = pr.c - pr.b*vec.dy - vec.dx*pr.a;
    b = pr.b;
    a = pr.a;
    normuj();
}

bool prosta::czyProstopadly(const wektor& vec)
{
    if(vec.dx == a && vec.dy == b)
    {
        return true;
    }
    return false;
}
bool prosta::czyPktNaProstej(const punkt &pkt)
{
    if(a * pkt.x + b*pkt.y + c == 0)
    {
        return true;
    }
    return false;
}
bool prosta::czyRownolegly(const wektor &vec)
{
    if(vec.dy/vec.dy == -(a/b))
    {
        return true;
    }
    return false;
}

bool prosta::czyProsteRownolegle(prosta &pr1,prosta &pr2)
{
    if((pr1.getA()*pr2.getB() - pr1.getB()*pr2.getA()) == 0) 
    {
        return true;
    }
    return false;
}

bool prosta::czyProsteProstopadle(prosta &pr1,prosta &pr2)
{
    if(pr1.getA()*pr1.getB() + pr2.getB()*pr2.getA() == 0) 
    {
        return true;
    }
    return false;
}

punkt prosta::przeciecie(prosta &pr1, prosta &pr2)
{
    if(prosta::czyProsteRownolegle(pr1,pr2))
    {
        throw std::invalid_argument("przecięcie wyliczane jest tylko dla prostych nierónoległych");
    }
    double W = pr1.getA() * pr2.getB() - pr2.getA() * pr1.getB();
    double Wx = (-pr1.getC())*pr2.getB() + pr2.getC()*pr1.getB();
    double Wy = pr1.getA() * (-pr2.getC()) + pr2.getA() * pr1.getC();
    punkt c(Wx/W, Wy/W);
    return c;
}

wektor wektor::skladanie(const wektor &vec1, const wektor &vec2)
{
    wektor c(vec1.dx + vec2.dx, vec1.dy + vec2.dy);
    return c;
}
