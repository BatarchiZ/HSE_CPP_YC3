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

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &matrix)
{
    std::vector<std::vector<int>> newMatrix;
    std::vector<int> newVector;
    //Go through each row and add it as new matrix
    for (int column = 0; column < matrix[0].size(); column++)
    {
        newVector.push_back(matrix[0][column]);
        newMatrix.push_back(newVector);
        newVector.clear();
    }
    for (int row = 1; row < matrix.size(); row++)
    {
        for (int column = 0; column < matrix[row].size(); column++)
        {
            newMatrix[column].push_back(matrix[row][column]);
        }
    }
    return newMatrix;
}