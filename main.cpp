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
    int ch, ch2;
    bool Exit = false;

    Map CrtMap(Player.CrtLocation + ".txt");

    while (!Exit)
    {
        ch = getch();
        system("cls");

        cout << CrtMap.content << endl
             << "--------\n";

        if (ch == 0 || ch == 224)
        {
            ch2 = getch();

            Player.Moving(ch2);
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