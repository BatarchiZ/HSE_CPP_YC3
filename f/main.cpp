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
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

typedef std::map<std::string, long long int> Scores;

int main()
{
//    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/f/input.txt";
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    std::string strN;
    getline(input_file, strN);
    int n = stoi(strN);

    Scores name_score;
    Scores name_counter;

    for (int i = 0; i < n; i++)
    {
        std::string name;
        getline(input_file, name, ' ');
        std::string score;
        getline(input_file, score);
        long long int nScore = stoi(score);

        //Initialize map
        //if person is not found
        Scores::iterator it = name_score.find(name);
        if (it == name_score.end())
        {
            name_score.insert({name, nScore});
        } else
        {
            it->second += nScore;
        }
        //Map holding values
        Scores::iterator it1 = name_counter.find(name);
        if (it1 == name_counter.end())
        {
            name_counter.insert({name, 1});
        } else
        {
            it1->second += 1;
        }
        //Get value and divide to get ans
        long long int resC = 0;
        Scores::iterator it3 = name_score.find(name);
        if (it3 != name_score.end())
        {
            resC = it3->second;
        }

        int resCount = 1;
        Scores::iterator it4 = name_counter.find(name);
        if (it4 != name_counter.end())
        {
            resCount = it4->second;
        }
        long long int ans = std::floor(resC / resCount);
        std::cout << ans << std::endl;
    }
    return 0;
}

