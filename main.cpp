#include <iostream>
#include <conio.h>
#include "map.cpp"
#include "Player.cpp"

using namespace std;

// Setting Up and Loading

player Player;

// End of Setting Up and Loading

int main()
{
    int LastLocaX=Player.cdtX;
    int LastLocaY=Player.cdtY;
    int ch, ch2;
    bool Exit = false;

    Map CrtMap(Player.CrtLocation + ".txt");
    

    while (!Exit)
    {

        CrtMap.content[Player.cdtX+(CrtMap.width+1)*Player.cdtY]='@';
        cout << CrtMap.content << endl
             << "--------\n";

        ch = getch();
        system("cls");

        

        if (ch == 0 || ch == 224)
        {
            ch2 = getch();

            Player.Moving(ch2);

            if(CrtMap.content[Player.cdtX+(CrtMap.width+1)*Player.cdtY]!=' '){
                Player.cdtX=LastLocaX;
                Player.cdtY=LastLocaY;

                cout<<"Can not Go that way.\n";
            }
        }
        else
        {
            int E;

            switch (ch)
            {
            case 101:
                cout << ch << "  Exit the Game? Press Enter to Confirm.\n";
                cout << "-----\n";

                E = getch();

                if (E == 13)
                {
                    cout << "Exit the Game.\n";
                    Exit = 1;
                    break;
                }
                else
                {
                    cout << "Back to the Game.\n";
                    break;
                }
            default:
                cout << ch << "  No such Input\n";
                break;
            }

        }
        cout << "-----\n";
    }
}