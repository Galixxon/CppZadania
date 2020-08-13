#ifndef _FILE_WRAPPER_HPP__
#define _FILE_WRAPPER_HPP__
#include<fstream>
class wejscie
{
    private:
    std::ifstream inputFile;
    public:
    wejscie(const std::string& filename);
    ~wejscie();
    bool eof();
    int readInt();
    char readChar();
    double readDouble();
};

class wyjscie
{
    private:
    std::ofstream outputFile;
    public:
    wyjscie(const std::string& filename);
    ~wyjscie();
    void writeInt(const int& i);
    void writeChar(const char& c);
    void writeDouble(const double& d);
};


#endif