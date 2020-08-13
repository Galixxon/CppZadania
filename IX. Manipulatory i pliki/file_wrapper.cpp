#include "file_wrapper.hpp"
wejscie::wejscie(const std::string& filename)
{
    inputFile.open(filename,std::ios::in);
    if(!inputFile.good()) throw std::ios_base::failure("Could not open a file: " + filename);
}

wejscie::~wejscie()
{
    inputFile.close();
}

bool wejscie::eof()
{
    return inputFile.peek() == EOF;
}

char wejscie::readChar()
{
    char ret;
    ret = inputFile.get();
    if(inputFile.fail()) throw std::ios_base::failure("Error while reading a char.");
    return ret;
}

int wejscie::readInt()
{
    int ret;
    inputFile>>ret;
    if(inputFile.fail()) throw std::ios_base::failure("Error while reading an int.");
    return ret;
}

double wejscie::readDouble()
{
    int ret;
    inputFile>>ret;
    if(inputFile.fail()) throw std::ios_base::failure("Error while reading an double.");
    return ret;
}


wyjscie::wyjscie(const std::string& filename)
{
    outputFile.open(filename,std::ios::out);
    if(!outputFile.good()) throw std::ios_base::failure("Could not open a file: " + filename);
}

wyjscie::~wyjscie()
{
    outputFile.close();
}

void wyjscie::writeChar(const char& c)
{
    outputFile<<c;
    if(outputFile.fail()) throw std::ios_base::failure("Error while writing char");
}


void wyjscie::writeInt(const int& i)
{
    outputFile<<i;
    if(outputFile.fail()) throw std::ios_base::failure("Error while writing int");
}


void wyjscie::writeDouble(const double& d)
{
    outputFile<<d;
    if(outputFile.fail()) throw std::ios_base::failure("Error while writing double");
}