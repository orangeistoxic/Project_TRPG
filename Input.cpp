#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int ch, ch2;
    bool Exit = false;
    int E;

    while (!Exit)
    {
        
        ch = getch();
        system("cls");

        if (ch == 0 || ch==224)
        {
            ch2 = getch();

            switch (ch2)
            {
            case 72:
                cout << ch2 << "  up\n";
                break;
            
            case 75:
                cout << ch2 << "  left\n";
                break;
            
            case 80:
                cout << ch2 << "  down\n";
                break;
            
            case 77:
                cout << ch2 << "  right\n";
                break;
            
            default:
                cout << ch2 << "  No such Input\n";
                break;
            }
        }
        else
        {
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