#include"wymierna.hpp"
int obliczenia::gcd(const int & _a,const int & _b)
{
    int temp;
    int a = _a;
    int b = _b;
    if(b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b > 0)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

obliczenia::wyjatek_wymierny::~wyjatek_wymierny(){}

const char* obliczenia::dzielenie_przez_0::what() const throw()
{
    return "Dzielenie przez 0!";
}

const char* obliczenia::przekroczenie_zakresu::what() const throw()
{
    return "Przekroczono zakres typu int";
}

obliczenia::wymierna::wymierna(int l, int m)
{
    licz = l;
    mian = m;
    if(mian == 0)
    {
        throw obliczenia::dzielenie_przez_0();
    }
}

void obliczenia::wymierna::normalize()
{
    int abs_licz = abs(licz);
    int abs_mian = abs(mian);
    int liczmian_gcd = gcd(abs_licz,abs_mian);
    if(liczmian_gcd > 1)
    {
        licz/=liczmian_gcd;
        mian/=liczmian_gcd;
    }
    if(mian<0)
    {
        mian = -mian;
        licz = -licz;
    }
}

std::ostream& obliczenia::operator<< (std::ostream &wyj, const wymierna &w)
{
    int l = w.licz;
    int m = w.mian;
    if(l < 0)
    {
        wyj<<"-";
        l = -l;
    }
    int cal = l/m;
    l = l - cal * m;
    wyj<<cal<<",";
    if(l == 0)
    {
        wyj<<"0";
        return wyj;
    }
    int c = 0, d = 0;
    int h = m;
    for(int i = m; i % 2 == 0; c++, i/=2, h/=2){}
    for(int i = m; i % 5 == 0; d++, i/=5, h/=2){}
    while(c >0 || d > 0)
        {
            wyj<< l*10/m;
            l = (l*10) % m;
            d--;
            c--;
        }
    if(h > 1 && l > 0)
    {
        wyj << "(";
        int pattern_l = l;
        int pattern_m = m;
        do
        {
            wyj<< l*10/m;
            l = (l*10) % m;
        }while(l != pattern_l && l > 0);
        wyj<<")";
    }

    return wyj;
}

obliczenia::wymierna obliczenia::operator+(const obliczenia::wymierna& wym1,const obliczenia::wymierna& wym2)
{
    int wym_lcm = wym1.mian / obliczenia::gcd(wym1.mian, wym2.mian) * wym2.mian;
    int licz1 = wym1.licz * (wym_lcm / wym1.mian);
    int licz2 = wym2.licz * (wym_lcm / wym2.mian);
    int sum = licz1 + licz2;
    if((sum < 0 && licz1 > 0 && licz2 > 0) || (sum > 0 && licz1 < 0 && licz2 < 0))
    {
        throw obliczenia::przekroczenie_zakresu();
    }
    obliczenia::wymierna ret(sum,wym_lcm);
    return ret;
}
obliczenia::wymierna obliczenia::operator-(const  obliczenia::wymierna& wym1,const  obliczenia::wymierna& wym2)
{

    int wym_lcm = wym1.mian / obliczenia::gcd(wym1.mian, wym2.mian) * wym2.mian;
    int licz1 = wym1.licz * (wym_lcm / wym1.mian);
    int licz2 = wym2.licz * (wym_lcm / wym2.mian);
    int substr = licz1 - licz2;
    if((substr < 0 && licz1 > 0 && -licz2 > 0) || (substr > 0 && licz1 < 0 && -licz2 < 0))
    {
        throw obliczenia::przekroczenie_zakresu();
    }
    obliczenia::wymierna ret(substr,wym_lcm);
    return ret;
}
obliczenia::wymierna obliczenia::operator*(const  obliczenia::wymierna& wym1,const  obliczenia::wymierna& wym2)
{
    int licz = wym1.licz * wym2.licz;
    int mian = wym1.mian * wym2.mian;
    if((licz < 0 && wym1.licz > 0 && wym2.licz > 0) || (licz < 0 && wym1.licz < 0 && wym2.licz < 0) || 
        (mian < 0 && wym1.mian > 0 && wym2.mian > 0) || (mian < 0 && wym1.mian < 0 && wym2.mian < 0))
    {
        throw obliczenia::przekroczenie_zakresu();
    }
    obliczenia::wymierna ret(licz,mian);
    return ret;
}
obliczenia::wymierna obliczenia::operator/(const  obliczenia::wymierna& wym1,const  obliczenia::wymierna& wym2)
{

    int licz = wym1.licz * wym2.mian;
    int mian = wym1.mian * wym2.licz;
    if((licz < 0 && wym1.licz > 0 && wym2.mian > 0) || (licz < 0 && wym1.licz < 0 && wym2.mian < 0) || 
        (mian < 0 && wym1.mian > 0 && wym2.licz > 0) || (mian < 0 && wym1.mian < 0 && wym2.licz < 0))
    {
        throw obliczenia::przekroczenie_zakresu();
    }
    obliczenia::wymierna ret(licz,mian);
    return ret;
}
obliczenia::wymierna obliczenia::operator-(const obliczenia::wymierna& wym)
{
    obliczenia::wymierna ret(-wym.licz, wym.mian);
    return ret;
}
obliczenia::wymierna obliczenia::operator!(const obliczenia::wymierna& wym)
{
    obliczenia::wymierna ret(wym.mian,wym.licz);
    return ret;
}