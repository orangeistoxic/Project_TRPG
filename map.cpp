#ifndef map_cpp
#define map_cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class MMap
{
    public:
    string Name;
    string content;
    int width = 0, height = 0;
    MMap(string name = "ExMap", const string path = "ExMap_0.txt")
    {
        ifstream inputfile(path);
        if (!inputfile.is_open())
        {
            cerr << "Can not open the file-" << path << "'" << endl;
            exit(EXIT_FAILURE);
        }

        content = string((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());

        int i = 0;
        while (1)
        {
            if (content[i] == '\n')
            {
                break;
            }
            else
            {
                width++;
            }
            i++;
        }

        for (int i = 0; i < content.length(); i++)
        {
            if (content[i] == '\n')
            {
                height += 1;
            }
        }

        Name=name;
        
    }
};

MMap GreenTown("GreenTown", "GreenTown_1.txt");
MMap ExMap("ExMap", "ExMap_0.txt");

map<int, MMap> AllMap =
    {
        {0, ExMap},
        {1, GreenTown}};
#endif