#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<limits>
#include<string>

int64_t czyPierwsza(int64_t num)
{
    int64_t n = static_cast<int64_t>(sqrt(num));
    for(int64_t i = 2; i <= n; i++)
    {
        if(num%i == 0)
        {
            return i;
        }
    }
    return num;
}

std::vector<int64_t> rozklad(int64_t liczba)
{
    std::vector<int64_t> vec;
    int64_t num;
    if(liczba >= -1 && liczba <= 1)
    {
        vec.push_back(liczba);
        return vec;
    }
    if(liczba == INT64_MIN)
    {
        vec.push_back(-1);
        vec.push_back(2);
        liczba/=2;
        liczba*=-1;
    }

    if(liczba<0)
    {
        vec.push_back(-1);
        liczba/=-1;
    }
    while(liczba > 1)
    {
        num = czyPierwsza(liczba);
        vec.push_back(num);
        liczba/=num;
    }
    return vec;
}


int64_t konwertuj(std::string num)
{
    int64_t n = 0, a = 1;
    int fac, stop = 0;
    std::string minstr = std::to_string(INT64_MIN);
    std::string maxstr = std::to_string(INT64_MAX);
    if(num[0] == '-')
    {
        if(num > minstr)
        {
            throw std::invalid_argument("Za mała liczba: " + num);
        }
        fac = -1;
        stop = 1;
    }
    else
    {
        if(num > maxstr)
        {
            throw std::invalid_argument("Za duza liczba: " + num);
        }
        fac = 1;
        stop = 0;
    }
    for(int i =  num.size()-1; i >= stop; i--)
    {
        if(num[i]>='0' && num[i]<='9')
        {
            n+=(num[i]-'0')*a;
            a*=10;
        }
        else
        {
            throw std::invalid_argument("Nieprawidłowy zapis liczby: " + num);
        }
    }

    n*= fac;
    return n;
}

void wypiszjedno(int64_t num)
{
    std::cout<<num<<" * ";
}

void wypisz(std::vector<int64_t> vec, int64_t num)
{
    std::cout<<num<<" = ";
    int n = vec.size()-1;
    for_each(vec.begin(), vec.end()-1, wypiszjedno);
    std::cout<<vec[n]<<'\n';
}

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        std::cerr<<"Aby skorzystać z programu należy przekazać liczby, które chcemy rozłożyć na czynniki pierwsze, przekazać jako argumenty wywołania.\n./main {args}\nPrzykład: ./main 2 12 4\n";
        return 0;
    }
    else
    {
        
        int64_t num;
        std::vector<int64_t> vec;
        std::string str;
        for(int i = 1; i < argc; i++)
        {
            str = argv[i];
            try
            {
                num = konwertuj(str);
            }
            catch(const std::invalid_argument& error)
            {
                std::cerr << "Invalid argument: " << error.what() << std::endl;
                continue;
            }
            vec = rozklad(num);
            wypisz(vec,num);
        }
       
    }
    return 0;
}