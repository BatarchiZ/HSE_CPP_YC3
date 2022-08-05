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

int compMatrix(std::vector<std::vector<int>>);

std::vector<std::vector<int>> inputMatrix(std::istream &, int);

int main()
{
    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/c/input.txt";
//    const std::string INP_FILE_NAME = "input.txt";

    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);
    std::string n;
    getline(input_file, n);
    int int_n = stoi(n);

    std::vector<std::vector<int>> matrix1 = inputMatrix(input_file, int_n);
    compMatrix(matrix1);
    return 0;
}

std::vector<std::vector<int>> inputMatrix(std::istream &is, int num)
{
    std::vector<std::vector<int>> matrix_1;
    for (int i = 0; i < num; i++)
    {
        std::string s;
        std::vector<int> v1;
        for (int j = 0; j < num - 1; j++)
        {
            getline(is, s, ' ');
            v1.push_back(stoi(s));
            s = "";
        }
        getline(is, s);
        v1.push_back(stoi(s));
        s = "";
        matrix_1.push_back(v1);
        v1.clear();
    }
    return matrix_1;
}

int compMatrix(std::vector<std::vector<int>> matrix1)
{
    for (int row = 0; row < matrix1.size(); row++)
    {
        for (int column = 0; column < matrix1[row].size(); column++)
        {
            for (int third = 0; third < matrix1.size(); third++)
            {
                if (matrix1[matrix1[row][column]][third] != matrix1[row][matrix1[column][third]])
                {
                    std::cout << "NO";
                    return 0;
                }
                std::cout << matrix1[matrix1[row][column]][third];
                std::cout << matrix1[row][matrix1[column][third]] << std::endl;
            }
        }
    }
    std::cout << "YES";
    return 0;
}