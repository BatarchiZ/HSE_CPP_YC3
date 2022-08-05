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
#include <map>
#include <vector>
#include <string>
#include <fstream>


typedef std::map<char,int> CharIntMap;

typedef std::vector<std::vector<char>> Matrix;

CharIntMap createMap(std::string, CharIntMap );

int findMax(CharIntMap);

Matrix makeMatrix(CharIntMap, int);

void printMatrix(Matrix);


int main()
{
//    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/j/input.txt";
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);
    CharIntMap aMap;
    while(!input_file.eof())
    {
        std::string str;
        getline(input_file, str);
        aMap = createMap(str, aMap);
    }
    int max = findMax(aMap);
    //TESTS
    Matrix testMatrix = makeMatrix(aMap, max);
    //Print Matrix
    printMatrix(testMatrix);
    return 0;
}
CharIntMap createMap(std::string str, CharIntMap aMap)
{
    for(char i : str)
    {
        if(i != ' ')
        {
            CharIntMap::iterator it = aMap.find(i);
            if (it == aMap.end())
            {
                aMap.insert({i, 1});
            }
            if (it != aMap.end())
            {
                it->second += 1;
            }
        }
    }
    return aMap;
}

int findMax(CharIntMap aMap)
{
    int max = 0;
    for(CharIntMap::iterator it = aMap.begin(); it!=aMap.end(); ++it)
    {
        if(it->second > max)
        {
            max = it->second;
        }
    }
    return max;
}

Matrix makeMatrix(CharIntMap aMap, int max)
{
    std::vector<std::vector<char>> matrix;
    for(CharIntMap::iterator it = aMap.begin(); it!= aMap.end(); it++ )
    {
        std::vector<char> v1;
        v1.push_back(it->first);
        for(int i = 0;i < it->second; i++)
        {
            v1.push_back('#');
        }
        if(v1.size()<=max)
        {
            for (int i = v1.size(); i <= max; i++)
            {
                v1.push_back(' ');
            }
        }
        matrix.push_back(v1);
        v1.clear();
    }
    return matrix;
}
void printMatrix(Matrix matrix)
{
    int i =0;
    for(int j = matrix[i].size()-1; j>=0; j--)
    {
        for(i=0; i<matrix.size(); i++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}