#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Map
{
    public:
    string content;
    int width = 0, height = 0;
    Map(const string path)
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

        
    }
};