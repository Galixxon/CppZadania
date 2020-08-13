#include<sstream>
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include "custom_manip.hpp"
#include "file_wrapper.hpp"

void testManipulators()
{
    std::istringstream ifs("Great\nCourse\nAppears\nOnce");
    std::vector<std::string> vec;
    std::string temp;
    std::getline(ifs>>clearline,temp);
    vec.push_back(temp);
    std::getline(ifs,temp);
    vec.push_back(temp);
    std::getline(ifs>>ignore(2),temp);
    vec.push_back(temp);
    for(auto s : vec)
    {
        std::cout<<s<<comma;
    }
    std::cout<<std::endl;
}
void testManipulatorsWithSorting()
{
    std::istringstream ifs("Nutricious\nCreator\nLorem ipsum\nBoredom");
    
    std::vector<std::pair<std::string,int>> strVec;
    std::string temp;
    int counter = 1;
    while(std::getline(ifs,temp))
    {
        strVec.push_back(std::pair<std::string,int>(temp,counter));
        ++counter;
    }
    std::sort(strVec.begin(), strVec.end());
    for(auto s : strVec)
    {
        std::cout<<index(s.second, 2)<<colon<<s.first<<std::endl;
    }
}

void testIOwithRandomNumbers()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,255);
    wyjscie *wy = nullptr;
    wejscie *we = nullptr;
    int temp;
    char space = ' ';
    
    try
    {
        wy = new wyjscie("randomNums.txt");    
        for(int i = 0; i < 10; i++)
        {
            temp = dist(gen);
            wy->writeInt(temp);
            wy->writeChar(space);
        }
        delete(wy);
        wy = nullptr;
    
        we = new wejscie("randomNums.txt");
        for(int i = 0; i < 10; i++)
        {
            temp = we->readInt();
            std::cout<<temp<<comma;
        }
        std::cout<<std::endl;
        delete(we);
        we = nullptr;
    }
    catch(std::ios_base::failure& fail)
    {
        delete(wy);
        wy = nullptr;
        delete(we);
        we = nullptr;
        std::clog<<fail.what()<<std::endl;
    }  
}
    
void testIObyteByByte()
{
    wejscie *we = nullptr;
    try
    {
        we = new wejscie("bytes.txt");
        char c;
        int i;
        while(we->eof() == false)
        {
            c = we->readChar();
            i = static_cast<int>(c);
            if(isalnum(c))
            {
                std::cout<<"Letter: "<<c<<comma<<"Dec: "<<std::dec<<i<<comma<<"Hex: "<<std::hex<<i<<std::endl;
            }
            else
            {
                std::cout<<"Letter: NONE"<<comma<<"Dec: "<<std::dec<<i<<comma<<"Hex: "<<std::hex<<i<<std::endl;
            }
            
            
        }
        delete(we);
        we=nullptr;
    }
    catch(std::ios_base::failure fail)
    {
        delete(we);
        we=nullptr;
        std::clog<<fail.what()<<std::endl;
    }
    
}
