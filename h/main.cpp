////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Contest X Problem Y
/// \author     Student's Name
/// \version    0.1.0
/// \date       25.01.2021
///
/// Copy the task description here.
///
////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <set>
#include <iostream>
#include <string>

int main()
{
    typedef std::set<std::string> IntSet;
    IntSet s;
    std::string str;

    while(std::cin >> str)
    {
        if(s.count(str))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
        s.insert(str);
        str = "";
    }
    return 0;
}