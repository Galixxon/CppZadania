//Kamil Galik 314570
#include <iostream>
#include <vector>
#include <string>

const std::vector<std::pair<int,std::string>> rzym = {
        {1000,"M"},
        {900,"CM"}, {500,"D"}, {400, "CD"}, {100, "C"},
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

std::string bin2rom(long int x)
{
    std::string ret = "";
    unsigned short iter = 0;
    while(x > 0)
    {
        if(x >= rzym[iter].first)
        {
            x-=rzym[iter].first;
            ret.append(rzym[iter].second);
        }
        else
        {
            if(iter <= 12)
                iter++;
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int num;
    for(int i = 1; i < argc; i++)
    {
        try
        {
            std::string str(argv[i]);
            num = stoi(str);
            if(num > 3999 || num < 1)
            {
                throw std::invalid_argument("Number should be in range 1-3999");
            }
            std::cout<<str<<" -> "<<bin2rom(num)<<"\n";
        
        }
        catch(std::invalid_argument &error)
        {
            std::clog<<"Invalid argument: "<<error.what()<<std::endl;
        }
    }
    return 0;
}