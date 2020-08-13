#ifndef __KALKULATOR_HPP
#define __KALKULATOR_HPP
#include<map>

namespace kalkulator
{
    class symbol
    {
        public:
        virtual double oblicz() =0;
        virtual ~symbol()=default;
    };

    class operand : public symbol
    {
        public:
        operand()=default;
        operand(const double& v) : val(v) {}
        operand(const double&& v) : val(v) {}
        virtual double oblicz(); //Wszystkie operandy poza zmienną mają taką samą funkcję oblicz
        private:
        double val;
    };

    class liczba : public operand
    {
        public:
        liczba(const double& v) : operand(v) {}
    };

    class zmienna : public operand
    {
        public:
        zmienna(const std::string& n) : name(n) {}
        static void assign(const std::string& name, double val);
        static void clear();
        double oblicz();
        private:
        static std::map<std::string, double> vars;
        std::string name;
    };

//Done
    class stala : public operand
    {
        public:
        stala(const double&& cst) : operand(cst) {}
    };

    class pi : public stala
    {
        public:
        pi() : stala(3.141592653589) {}
    };

    class e : public stala
    {
        public:
        e() : stala(2.718281828459) {}
    };

    class fi : public stala
    {
        public:
        fi() : stala(1.618033988750) {}
    };

    
    class funkcja : public symbol
    {
        public:
        virtual double oblicz() =0;
    };

    class add : public funkcja
    {
        public:
        add(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;

    };

    class sub : public funkcja
    {
        public:
        sub(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class mult : public funkcja
    {
        public:
        mult(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class div : public funkcja
    {
        public:
        div(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class modulo : public funkcja
    {
        public:
        modulo(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class min : public funkcja
    {
        public:
        min(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class max : public funkcja
    {
        public:
        max(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class log : public funkcja
    {
        public:
        log(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };

    class pow : public funkcja
    {
        public:
        pow(symbol *_s1, symbol *_s2) : s1(_s1), s2(_s2) {}
        double oblicz();
        private:
        symbol *s1;
        symbol *s2;
    };



    class abs : public funkcja
    {
        public:
        abs(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class sgn : public funkcja
    {
        public:
        sgn(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class floor : public funkcja
    {
        public:
        floor(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class ceil : public funkcja
    {
        public:
        ceil(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class frac : public funkcja
    {
        public:
        frac(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class sin : public funkcja
    {
        public:
        sin(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class cos : public funkcja
    {
        public:
        cos(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class atan : public funkcja
    {
        public:
        atan(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class acot : public funkcja
    {
        public:
        acot(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class ln : public funkcja
    {
        public:
        ln(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };

    class exp : public funkcja
    {
        public:
        exp(symbol *_s) : s(_s) {}
        double oblicz();
        private:
        symbol *s;
    };
}
#endif