#include "custom_manip.hpp"

int ignore::getLettersToDel() const
{
    return lettersToDel;
}

int index::getIndex() const
{
    return ind;
}

int index::getWidth() const
{
    return width;
}

std::ostream& operator<<(std::ostream& in, const index &ind) //Index
{
    int allSize = ind.getWidth();
    int number  = ind.getIndex();
    std::string retNum = std::to_string(number);
    int numSize = retNum.size();
    int offsetSize = (numSize < allSize) ? allSize-numSize : 0;
    in<<"[";
    for(int i = 0; i < offsetSize;i++)
    {
        in<<" ";
    }
    return in<<retNum<<"]";
}


std::istream& operator>>(std::istream& in, const ignore &ign) //Ignore
{
    
    int size = ign.getLettersToDel();
    char *s = new char[size+1];
    in.get(s,size+1,'\n');
    if(in.peek() == 10)
    {
        in.get();
    }
    delete[] s;
    return in;
}

