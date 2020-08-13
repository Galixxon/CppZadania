#include "kalkulator.hpp"
#include <iostream>
#include <cmath>
std::map<std::string, double> kalkulator::zmienna::vars;

double kalkulator::operand::oblicz()
{
    return val;
}

double kalkulator::zmienna::oblicz()
{
    auto i = vars.begin();
    auto end = vars.end();
    while(i != end && i->first != name)
    {
        ++i;
    }
    if(i->first != name)
    {
        std::clog<<"Var not found"<<std::endl;
    }
    return i->second;
}

void kalkulator::zmienna::assign(const std::string& name, double val)
{
   vars.insert(std::pair<std::string, double>(name, val));
}

void kalkulator::zmienna::clear()
{
    vars.clear();
}

double kalkulator::add::oblicz()
{
    return s1->oblicz() + s2->oblicz();
}

double kalkulator::sub::oblicz()
{
    return s1->oblicz() - s2->oblicz();
}

double kalkulator::mult::oblicz()
{
    return s1->oblicz() * s2->oblicz();
}

double kalkulator::div::oblicz()
{
    if(s2->oblicz() == 0) throw std::invalid_argument("Dzielenie przez 0");
    return s1->oblicz() / s2->oblicz();
}

double kalkulator::modulo::oblicz()
{
    if(s2->oblicz() == 0) throw std::invalid_argument("Dzielenie przez 0");
    return (int)(s1->oblicz()) % (int)(s2->oblicz());
}

double kalkulator::min::oblicz()
{
    return (s1->oblicz() < s2->oblicz()) ? s1->oblicz() : s2->oblicz();
}

double kalkulator::max::oblicz()
{
    return (s1->oblicz() > s2->oblicz()) ? s1->oblicz() : s2->oblicz();
}

double kalkulator::log::oblicz()
{
    if(s1->oblicz() == 1) throw std::invalid_argument("Taki log nie istnieje");
    return log10(s2->oblicz())/log10(s1->oblicz());
}

double kalkulator::pow::oblicz()
{
    return powl(s1->oblicz(),s2->oblicz());
}




double kalkulator::abs::oblicz()
{
    return (s->oblicz() < 0) ? -(s->oblicz()) : s->oblicz();
}

double kalkulator::sgn::oblicz()
{
    if(s->oblicz() == 0) return 0;
    return (s->oblicz() > 0) ? 1 : -1;
}

double kalkulator::floor::oblicz()
{
    return floorf64(s->oblicz());
}

double kalkulator::ceil::oblicz()
{
    return ceilf64(s->oblicz());
}

double kalkulator::frac::oblicz()
{
    return s->oblicz() - floorf64(s->oblicz());
}

double kalkulator::sin::oblicz()
{
    return sinf64(s->oblicz());
}

double kalkulator::cos::oblicz()
{
    return cosf64(s->oblicz());
}

double kalkulator::atan::oblicz()
{
    return atanf64(s->oblicz());
}

double kalkulator::acot::oblicz()
{
    return -atanf64(-(s->oblicz()));
}

double kalkulator::ln::oblicz()
{
    return log10(s->oblicz())/log10(2.718281828459);
}


double kalkulator::exp::oblicz()
{
    return expf64(s->oblicz());
}
