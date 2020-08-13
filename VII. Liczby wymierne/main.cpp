//Kamil Galik 314570
#include<iostream>
#include "wymierna.hpp"

int main()
{
    try
    {
        obliczenia::wymierna wym1(-1,3);
        obliczenia::wymierna wym2(3,5);
    
        std::cout<<wym1<<" "<<wym2<<std::endl;
        std::cout<<static_cast<int>(wym1)<<" "<<(double)wym2<<std::endl;
        std::cout<<-wym1<<" "<<!wym2<<"\n\n";
        
        std::cout<<wym1 + wym2<<std::endl;
        std::cout<<wym1 - wym2<<std::endl;
        std::cout<<(double)(wym1 * wym2)<<std::endl;
        std::cout<<wym1 / wym2<<std::endl;
    
        obliczenia::wymierna wym3 = wym1;
        std::cout<<wym1<<" "<<wym3<<std::endl;

    }catch(obliczenia::wyjatek_wymierny &wym)
    {
        std::cout<<"Exception handled: "<<wym.what()<<std::endl;
    }
    return 0;
}