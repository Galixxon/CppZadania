#include<iostream>
#include<cmath>
#include<exception>

namespace obliczenia
{
    int gcd(const int & _a,const int & _b);

    class wyjatek_wymierny : public std::exception
    {
        public:
        wyjatek_wymierny() = default;
        wyjatek_wymierny(const wyjatek_wymierny& wym) {}
        wyjatek_wymierny& operator= (const wyjatek_wymierny& wym) =default;
        virtual ~wyjatek_wymierny() =0;
        virtual const char* what() const throw() =0;
    };

    class dzielenie_przez_0 : public wyjatek_wymierny
    {
        public:
        dzielenie_przez_0() = default;
        dzielenie_przez_0(const dzielenie_przez_0& dziel) {};
        const char* what() const throw();
    };

    class przekroczenie_zakresu : public wyjatek_wymierny
    {
        public:
        przekroczenie_zakresu() = default;
        przekroczenie_zakresu(const przekroczenie_zakresu& dziel) {};
        const char* what() const throw();
    };

    class wymierna
    {
        private:
        int licz, mian;
        public:
        wymierna(int l, int m);
        wymierna(int liczba) : wymierna(liczba,1) {}
        wymierna(const wymierna &wym) = default;
        wymierna & operator= (const wymierna & wym) = default;
        private:
        void normalize();

        public:
        operator double() const {return (double)licz/mian;}
        explicit operator int() const {return (licz < mian/2.0)? licz/mian : licz/mian +1;}

        friend std::ostream& operator<< (std::ostream &wyj, const wymierna &w);
        friend wymierna operator+(const wymierna& wym1,const wymierna& wym2);
        friend wymierna operator-(const wymierna& wym1,const wymierna& wym2);
        friend wymierna operator*(const wymierna& wym1,const wymierna& wym2);
        friend wymierna operator/(const wymierna& wym1,const wymierna& wym2);
        friend wymierna operator-(const wymierna& wym);
        friend wymierna operator!(const wymierna& wym);

    };

    std::ostream& operator<< (std::ostream &wyj, const wymierna &w);
    wymierna operator+(const wymierna& wym1,const wymierna& wym2);
    wymierna operator-(const wymierna& wym1,const wymierna& wym2);
    wymierna operator*(const wymierna& wym1,const wymierna& wym2);
    wymierna operator/(const wymierna& wym1,const wymierna& wym2);
    wymierna operator-(const wymierna& wym);
    wymierna operator!(const wymierna& wym);
}
