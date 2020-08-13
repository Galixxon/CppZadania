#include<iostream>
#ifndef _CUSTOM_MANIP_HPP__
#define _CUSTOM_MANIP_HPP__

class index
{
    private:
    int ind,width;
    public:
    index(int x,int w) : ind(x), width(w) {}
    int getIndex() const;
    int getWidth() const;
    friend std::ostream& operator<<(std::ostream& in, const index& ind);
};

class ignore
{
    private:
    int lettersToDel;
    public:
    ignore(int x) : lettersToDel(x) {}
    int getLettersToDel() const;
    friend std::istream& operator>>(std::istream& in, const ignore &ign);
};

inline std::istream& clearline(std::istream& in)
{
    char c;
    while(in.get() != '\n' && !in.eof()) {}
    return in;
}

inline std::ostream& comma(std::ostream& out)
{
    out << ", ";
    return out;
}

inline std::ostream& colon(std::ostream& out)
{
    out << ": ";
    return out;
}

#endif