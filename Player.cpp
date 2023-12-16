#include <iostream>

using namespace std;

class player
{
public:

    player(){}
    int cdtX=2;
    int cdtY=2;
    string CrtLocation="Town";

    void SetCoordinate(int x,int y){
        cdtX=x;
        cdtY=y;
    }

    void Moving(int ch2){
        switch (ch2)
        {
        case 72:
            cout << ch2 << "  up\n";
            cdtY--;
            break;

        case 75:
            cout << ch2 << "  left\n";
            cdtX--;
            break;

        case 80:
            cout << ch2 << "  down\n";
            cdtY++;
            break;

        case 77:
            cout << ch2 << "  right\n";
            cdtX++;
            break;

        default:
            cout << ch2 << "  No such Input\n";
            break;
        }
    }
};