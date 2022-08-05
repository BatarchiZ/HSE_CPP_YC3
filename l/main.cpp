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
#include <vector>
#include <fstream>
#include <string>
#include <set>

std::vector<char> strToV(std::string);

bool checkFile(std::vector<char>);

std::vector<char> processV(std::vector<char> v);

typedef std::set<std::string> StringSet;

StringSet addToSet(std::vector<char>, StringSet);

StringSet mergeSets(StringSet, StringSet);


int main()
{
//    const std::string INPUT_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/l/input.txt";
    const std::string INPUT_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INPUT_FILE_NAME);

    std::string str;
    StringSet setAns;
    while (!input_file.eof())
    {
        getline(input_file, str);
        if (!str.empty())
        {
            std::vector<char> v = strToV(str);
            if (checkFile(v))
            {
                std::vector<char> v1 = processV(v);
                StringSet s;
                setAns = mergeSets(addToSet(v1, s), setAns);
            }
        }
    }
    for (std::string i: setAns)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

StringSet mergeSets(StringSet s1, StringSet s2)
{
    for (std::string i: s1)
    {
        s2.insert(i);
    }
    return s2;
}

std::vector<char> strToV(std::string s)
{
    std::vector<char> outV;
    for (char i: s)
    {
        outV.push_back(i);
    }
    return outV;
}

bool checkFile(std::vector<char> v)
{
    if (v.back() != '/')
    {
        return true;
    }
    return false;
}

std::vector<char> processV(std::vector<char> v)
{
    std::vector<char>::reverse_iterator rIter;
    for (rIter = v.rbegin(); rIter != v.rend(); rIter++)
    {
        if (*rIter != '/')
        {
            v.erase(std::next(
                    rIter).base()); //Dirty hack to get the position of reverse iterator for forward iterator as erase accepts iterator //Alternatively just use normal iterator and iterate backwards
        } else
        {
            break;
        }
    }
    return v;
}

StringSet addToSet(std::vector<char> v, StringSet s)
{
    std::string tempStr = "/";
    for (char i: v)
    {
        if (i == '/')
        {
            if (tempStr.size() != 1)
            {
                tempStr.push_back('/');
            }
            s.insert(tempStr);
        } else
        {
            tempStr.push_back(i);
        }
    }
    return s;
}