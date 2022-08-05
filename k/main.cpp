#include <iostream>
#include <string>
#include <fstream>
#include <set>

typedef std::set<std::string> StringSet;

void answer(std::string&, StringSet&);

int main()
{
//    const std::string INP_FILE_NAME = "/Users/iskandersergazin/Desktop/HSE_CPP/YC3/code/k/input.txt";
    const std::string INP_FILE_NAME = "input.txt";

    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    std::string key;
    std::string str;

    StringSet setAns;
    while(getline(input_file, key, ' ') && key[0]!='#')
    {
        if(key[0] == '+')
        {
            str="";
            getline(input_file, str);
            setAns.insert(str);
            continue;
        }
        if(key[0] == '-')
        {
            str="";
            getline(input_file, str);
            setAns.erase(str);
            continue;
        }
        else
        {
            str="";
            getline(input_file, str);
            answer(str, setAns);
            continue;
        }
    }
    return 0;
}
void answer(std::string& str, StringSet& set)
{
    StringSet::iterator it = set.find(str);
    if(it == set.end())
    {
        std::cout << "NO"<< std::endl;
    }
    else
    {
        std::cout << "YES"<< std::endl;
    }
}

