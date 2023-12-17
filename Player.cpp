#include <iostream>

using namespace std;

class player
{
public:

    player(){}
    int cdtX=2;
    int cdtY=2;
    int CrtLocation=1;

    void SetCoordinate(int x,int y){
        cdtX=x;
        cdtY=y;
    }

    string Moving(int ch2){
        switch (ch2)
        {
        case 72:
            cdtY--;
            return "72 up \n";

        case 75:
            cdtX--;
            return  "75 left \n";

        case 80:
            cdtY++;
            return "80 down \n";

        case 77:
            cdtX++;
            return "77 right \n";

        default:
            return to_string(ch2)+"  No such Input \n";
        }
    }

    int Gold=100;

    void SetGold(int num){
        Gold=num;
    }
};