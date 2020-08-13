#ifndef _POMOC_HPP
#define _POMOC_HPP


class wektor
{
    public:
        const double dx,dy;
        wektor() = default;
        wektor(const double &newx,const double &newy) : dx(newx), dy(newy){}
        wektor(const wektor &vec) : dx(vec.dx), dy(vec.dy){}\
        wektor & operator= (const wektor&)  = delete;
        static wektor skladanie(const wektor& , const wektor&);
};

class punkt
{
    public:
        const double x,y;
        punkt() = default;
        punkt(const double &newx,const double &newy) : x(newx), y(newy){}
        punkt(const punkt &p, const wektor &vec) : x(p.x + vec.dx), y(p.y + vec.dy){}
        punkt(const punkt &pkt) : x(pkt.x), y(pkt.y){}  
        punkt & operator= (const punkt&) = delete;
};

class prosta
{
    private:
        double a,b,c;
       
    public:
        void normuj();
        double getA();
        double getB();
        double getC();
        prosta() = default;
        prosta(const punkt&, const punkt&);
        prosta(const wektor&);
        prosta(const double&,const double&,const double&);
        prosta(const wektor&, const prosta&);
        prosta(const prosta&) = delete;
        
        bool czyProstopadly(const wektor&);
        bool czyPktNaProstej(const punkt &);
        bool czyRownolegly(const wektor &);

        static bool czyProsteRownolegle(prosta &,prosta &);
        static bool czyProsteProstopadle(prosta &,prosta &);
        static punkt przeciecie(prosta &, prosta &);
};

#endif