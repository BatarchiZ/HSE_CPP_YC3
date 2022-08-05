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

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>> &);

int main()
{
    // TODO: provide your solution here.
    std::vector<std::vector<int>> vect
            {
                    {0, 3, 2, 4},
                    {2, 3, 5, 5},
                    {5, 1, 2, 3}
            };
    std::pair<size_t, size_t> ansp = max_element(vect);
    std::cout << ansp.first << ansp.second;

//    std:: cout << max_element(vect);
    return 0;
}

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int>> &matrix)
{
    std::pair<size_t, size_t> ansPair = {0, 0};
    int number = matrix[0][0];
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (number < matrix[i][j])
            {
                ansPair = {i, j};
                number = matrix[i][j];
            }
        }
    }
    return ansPair;
}