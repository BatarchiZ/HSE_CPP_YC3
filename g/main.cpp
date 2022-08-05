#include <fstream>
#include <set>
#include <iostream>
#include <string>

int main()
{
//    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/g/input.txt";
    const std::string INP_FILE_NAME = "input.txt";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    typedef std::set<int> IntSet;
    IntSet s;

    std::string str;
    while (getline(input_file, str, ' '))
    {
        s.insert(stoi(str));
        str = "";
    }

    int v = s.size();
    std::cout << v;
    return 0;
}
