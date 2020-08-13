#include "tabbit.hpp"
#include <iostream>
#include <cmath>

tab_bit::tab_bit (int rozm)
{
    dl = rozm;
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    tab = new slowo[tabSize] ();
}

tab_bit::tab_bit (slowo tb)
{
    dl = rozmiarSlowa;
    tab = new slowo;
    *tab = tb;
}

tab_bit::tab_bit (const tab_bit &tb)
{
    dl = tb.dl;
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    tab = new slowo[tabSize];
    for(int i = 0; i < tabSize; i++)
    {
        tab[i] = tb.tab[i];
    }
}

tab_bit::tab_bit (tab_bit &&tb)
{
    dl = tb.dl;
    tab = tb.tab;
    tb.tab = nullptr;
}

tab_bit::tab_bit (const std::initializer_list<bool>& list)
{
    dl = list.size();
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    tab = new slowo[tabSize];
    auto ptr = list.begin();
    for(int i = dl-1; i >= 0;++ptr, i--)
    {
        pisz(i,*ptr);
    }
}

tab_bit & tab_bit::operator = (const tab_bit &tb)
{
    dl = tb.dl;
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    tab = new slowo[tabSize];
    for(int i = 0; i < tabSize; i++)
    {
        tab[i] = tb.tab[i];
    }
    return *this;
}

tab_bit & tab_bit::operator = (tab_bit &&tb)
{
    dl = tb.dl;
    tab = tb.tab;
    tb.tab = nullptr;
    return *this;
}

tab_bit::~tab_bit()
{
    delete[] tab;
}

std::ostream & operator << (std::ostream &wy, const tab_bit &tb)
{
    for(int i = tb.dl-1; i > 0; --i)
    {
        wy << tb.czytaj(i)<<", ";
    }
    wy << tb.czytaj(0) << std::endl;
    return wy;
}

std::istream & operator >> (std::istream &we, tab_bit &tb)
{
    we >> tb.dl;
    int tabSize = ceil(static_cast<double>(tb.dl)/tb.rozmiarSlowa);
    for(int i = 0; i < tabSize; i++)
    {
        we >> tb.tab[i];
    }
    return we;
}



bool tab_bit::czytaj (int i) const
{
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    int index = i%rozmiarSlowa;
    slowo s = tab[tabSize-1];
    bool b = s>>index & 1;
    return b;
}

bool tab_bit::pisz (int i, bool b)
{
    int tabSize = ceil(static_cast<double>(dl)/rozmiarSlowa);
    int index = i%rozmiarSlowa;
    tab[tabSize-1] ^= (-b ^ tab[tabSize-1]) & (1 << index);
    return b;
}

bool tab_bit::operator[] (int i) const
{
    bool b = czytaj(i);
    return b;
}

tab_bit::ref tab_bit::operator[] (int i)
{
    int indexSlowa = ceil(static_cast<double>(dl)/rozmiarSlowa) -1;
    int indexBitu = i%rozmiarSlowa;
    ref ret(tab[indexSlowa], indexBitu);
    return ret;
}

inline int tab_bit::rozmiar () const
{
    return dl;
}



tab_bit::ref::ref(slowo& s,const int i)
{
    st = &s;
    index = i;
}

tab_bit::ref::ref(const ref& r)
{
    index = r.index;
    st = new slowo;
    *st = *(r.st);
}

tab_bit::ref & tab_bit::ref::operator= (const ref& r)
{
    slowo b = *(r.st) >> r.index & 1;
    slowo res = *st;
    res = res ^ ((-b ^ res) & ((slowo)1 << index));
    *st = res;
    return *this;
}

tab_bit::ref & tab_bit::ref::operator= (const bool& r)
{
    slowo b = r;
    slowo res = *st;
    res = res ^ ((-b ^ res) & ((slowo)1 << index));
    *st = res;
    return *this;
}


tab_bit::ref & tab_bit::ref::operator= (const int& r)
{
    slowo b = (slowo)!!r;
    slowo res = *st;
    res = res ^ ((-b ^ res) & ((slowo)1 << index));
    *st = res;
    return *this;
}

tab_bit& tab_bit::operator&=(const tab_bit& tb)
{
    int tb1_size = ceil(static_cast<double>(tb.dl)/tb.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(dl)/rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    for(int i = 0; i < tabSize; i++)
    {
        tab[i] &= tb.tab[i];
    }
    return *this;
}

tab_bit& tab_bit::operator^=(const tab_bit& tb)
{
    int tb1_size = ceil(static_cast<double>(tb.dl)/tb.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(dl)/rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    for(int i = 0; i < tabSize; i++)
    {
        tab[i] ^= tb.tab[i];
    }
    return *this;
}

tab_bit& tab_bit::operator|=(const tab_bit& tb)
{
    int tb1_size = ceil(static_cast<double>(tb.dl)/tb.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(dl)/rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    for(int i = 0; i < tabSize; i++)
    {
        tab[i] |= tb.tab[i];
    }
    return *this;
}

tab_bit operator& (const tab_bit& tb1, const tab_bit& tb2)
{
    int tb1_size = ceil(static_cast<double>(tb1.dl)/tb1.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(tb2.dl)/tb2.rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    int newSize = (tb1_size > tb2_size) ? tb1_size : tb2_size;
    tab_bit ret(newSize * sizeof(tab_bit::slowo));
    for(int i = 0; i < tabSize; i++)
    {
        ret.tab[i] = tb1.tab[i] & tb2.tab[i];
    }
    return ret;
}


tab_bit operator^ (const tab_bit& tb1, const tab_bit& tb2)
{
    int tb1_size = ceil(static_cast<double>(tb1.dl)/tb1.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(tb2.dl)/tb2.rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    int newSize = (tb1_size > tb2_size) ? tb1_size : tb2_size;
    tab_bit ret(newSize * sizeof(tab_bit::slowo));
    for(int i = 0; i < tabSize; i++)
    {
        ret.tab[i] = tb1.tab[i] ^ tb2.tab[i];
    }
    return ret;
}

tab_bit operator| (const tab_bit& tb1, const tab_bit& tb2)
{
    int tb1_size = ceil(static_cast<double>(tb1.dl)/tb1.rozmiarSlowa);
    int tb2_size = ceil(static_cast<double>(tb2.dl)/tb2.rozmiarSlowa);
    int tabSize = (tb1_size < tb2_size) ? tb1_size : tb2_size;
    int newSize = (tb1_size > tb2_size) ? tb1_size : tb2_size;
    tab_bit ret(newSize * sizeof(tab_bit::slowo));
    for(int i = 0; i < tabSize; i++)
    {
        ret.tab[i] = tb1.tab[i] | tb2.tab[i];
    }
    return ret;
}

tab_bit tab_bit::operator!()
{
    int tb_size = ceil(static_cast<double>(dl)/rozmiarSlowa);
    tab_bit ret(dl);
    for(int i = 0; i < tb_size; i++)
    {
        ret[i] = !tab[i];
    }
    return ret;
}

tab_bit::ref::operator bool() const
{
    bool b = (*st) >> index & 1;
    return b;
}
