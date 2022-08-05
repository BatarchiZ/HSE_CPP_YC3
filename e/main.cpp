#include <iostream>
#include <vector>
#include <algorithm>

void swap_columns(std::vector<std::vector<int>> &matrix, size_t i, size_t j)
{
    for (int is = 0; is < matrix.size(); is++)
    {
        for (int js = 0; js < matrix[is].size(); js++)
        {
            if (js == i)
            {
                std::swap(matrix[is][js], matrix[is][j]);
            }
        }
    }
}
