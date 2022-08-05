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
#include <iostream>
#include <fstream>
#include <set>
#include <string>

typedef std::set<char> CharSet;

int main()
{
//    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/h/input.txt";
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    CharSet s;
    std::string strBase;
    getline(input_file, strBase);

    CharSet setAns;
    for (char i: strBase)
    {
        s.insert(i);
        setAns.insert(i);
    }

    while (!input_file.eof())
    {

        std::string compSt;
        getline(input_file, compSt);

        CharSet s2;
        for (char i: compSt)
        {
            s2.insert(i);
        }

        if (compSt.empty())
        {
            break;
        }
        for (char i: s)
        {

            CharSet::iterator searchingFor = s2.find(i);
            if (searchingFor == s2.end())
            {
                setAns.erase(i);
            }
        }

    }

    for (char i: setAns)
    {
        std::cout << i;
    }
    return 0;
}