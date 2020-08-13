//Kamil Galik 314570
//Lista 9.

#include "custom_manip.hpp"
#include "file_wrapper.hpp"
#include "testers.hpp"

int main()
{
    testManipulators();
    std::cout<<std::endl;
    testManipulatorsWithSorting();
    std::cout<<std::endl;
    testIOwithRandomNumbers();
    std::cout<<std::endl;
    testIObyteByByte();
    return 0;
}