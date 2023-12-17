#include <iostream>
#include <conio.h>
#include "map.cpp"
#include "Player.cpp"

using namespace std;

// Setting Up and Loading


Map Town("Town_1.txt");
Map CrtMap("ExMap.txt");
player Player;
ifstream inputfile("Help.txt");
string Help = string((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());

// End of Setting Up and Loading

void Command(string Input){
    int num;
    if(Input=="Setgold"){
        cout<<"Change to...";
        cin>>num;
        Player.SetGold(num);
        cout << "Gold Set!\n"
             << "--------\n";
    }
    else if(Input=="Showgold"){
        cout << "You Have " << Player.Gold << " Gold.\n"
             << "--------\n";
    }
}

int main()
{
    int LastLocaX=Player.cdtX;
    int LastLocaY=Player.cdtY;
    int ch, ch2;
    bool Exit = false;
    string SysReturnInfo="";

    switch(Player.CrtLocation)
    {
        case 1:
            CrtMap = Town;

    }

    

    while (!Exit)
    {
        SysReturnInfo = "";
        ch = getch();
        system("cls");


        if (ch == 0 || ch == 224)
        {
            ch2 = getch();

            SysReturnInfo+=Player.Moving(ch2);

            switch(CrtMap.content[Player.cdtX+(CrtMap.width+1)*Player.cdtY])
            {
                case ' ':
                    CrtMap.content[LastLocaX + (CrtMap.width + 1) * LastLocaY] = ' ';
                    LastLocaX = Player.cdtX;
                    LastLocaY = Player.cdtY;
                    break;

                case '#':
                    Player.cdtX = LastLocaX;
                    Player.cdtY = LastLocaY;
                    SysReturnInfo += "Can not Go that way.";
                    break;

                case 'M':
                    
                    SysReturnInfo += "This is a ";
                    switch(CrtMap.content[Player.cdtX+(CrtMap.width+1)*(Player.cdtY+2)])
                    {
                        case 'W':
                            SysReturnInfo += "Weapon Merchant.";
                            break;
                        case 'A':
                            SysReturnInfo += "Armor Merchant.";
                            break;
                    }
                    Player.cdtX = LastLocaX;
                    Player.cdtY = LastLocaY;
                default :
                    CrtMap.content[LastLocaX + (CrtMap.width + 1) * LastLocaY] = ' ';
                    LastLocaX = Player.cdtX;
                    LastLocaY = Player.cdtY;
                    break;
            }


            

            CrtMap.content[Player.cdtX + (CrtMap.width + 1) * Player.cdtY] = '@';
            cout << CrtMap.content << endl
                 << "--------\n"
                 << SysReturnInfo << endl
                 << "--------\n";
        }
        else
        {
            CrtMap.content[Player.cdtX + (CrtMap.width + 1) * Player.cdtY] = '@';
            cout << CrtMap.content << endl
                 << "--------\n";

            int E;
            string Input;

            switch (ch)
            {
            case 101:
                cout << ch << "  Exit the Game? Press Enter to Confirm.\n";

                E = getch();

                if (E == 13)
                {
                    cout << "Exit the Game.\n"
                         << "--------\n";
                    Exit = 1;
                    break;
                }
                else
                {
                    cout << "Back to the Game.\n"
                         << "--------\n";
                    break;
                }
            case 99:
                cout<<"Command Mode\n";
                cin >> Input;
                Command(Input);
                break;
            case 104:
                cout << Help << endl
                     << "--------\n";
                break;

            default:
                cout << ch << "  No such Input\n"
                     << endl
                     << "--------\n";
                
            }

        }

    }
}