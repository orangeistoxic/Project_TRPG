#ifndef main_cpp
#define main_cpp
#include <iostream>
#include <conio.h>
#include <map>
#include "map.cpp"
#include "Player.cpp"
#include "Item.cpp"
#include "NPC.cpp"
#include "AttackSkill.cpp"

using namespace std;

// Setting Up and Loading

MMap CrtMap("ExMap", "ExMap_0.txt");
player Player;
ifstream inputfile("Help.txt");

string Help = string((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>()); // Press "h" to get help.
map<string, int> AllCommand =
    {
        {"Setgold", 1},
        {"Showgold", 2},
        {"Showitemstat", 3},
        {"Equipitem", 4},
        {"Showbackpack", 5},
        {"Getstarterpack", 6},
        {"Godmode", 7},
        {"Showplayerstat", 8}};

// End of Setting Up and Loading

void Command(string Input)
{
    int num;
    string word;
    Item item;
    int NumCommand = AllCommand[Input];

    switch (NumCommand)
    {
    case 1:
        cout << "Change to...";
        cin >> num;
        Player.SetGold(num);
        cout << "Gold Set!\n"
             << "--------\n";
        break;

    case 2:
        cout << "You Have " << Player.Gold << " Gold.\n"
             << "--------\n";
        break;
    case 3:
        cout << "Which Item stat:\n";
        cin >> word;
        item = AllItem[word];
        if (item.type == "Weapon" || item.type == "Armor")
        {
            item.ShowAllStat_WeaponAndArmor();
        }
        else if (item.type == "Consumable")
        {
            item.ShowAllStat_Consumable();
        }
        break;
    case 4:
        cout << "Equip what item? In your backpack: \n";
        Player.ListBackPackContent();
        Player.EquipingItem();
        Player.RefreshPlayerStat();
        break;
    case 5:
        cout << "Your BackPack: \n";
        Player.ListBackPackContent();
        break;
    case 6:
        Player.CheatingGear_1();
        break;
    case 7:
        Player.GODMODE();
        Player.RefreshPlayerStat();
        break;
    case 8:
        cout << endl
             << "Location: " << CrtMap.Name << endl;
        Player.ShowPlayerStat();
        break;
    default:
        cout << "No such Command.\n"
             << "--------\n";
        break;
    }
}

void Trading(string type)
{
    string input;
    cin >> input;
    int num;
    string MerchantName = "";
    MerchantName += CrtMap.Name + type + "M";

    if (input == "Buy" || input == "buy" || input == "B" || input == "b")
    {
        cout << "Merchant is Selling: \n";
        AllNPC[MerchantName].ListShopContent();
        cin >> num;
        if (num > 9 || num < 0)
        {
            cout << "PLs input between 0~9\n";
        }
        else
        {
            cout << "It cost " << AllNPC[MerchantName].Shop[num].Price * AllNPC[MerchantName].Profit << " Gold,Confirm?\n";
            cin >> input;
            if (input == "Yes" || input == "yes" || input == "Y" || input == "y")
            {
                if (Player.Gold >= AllNPC[MerchantName].Shop[num].Price * AllNPC[MerchantName].Profit)
                {
                    Player.GetItem(AllNPC[MerchantName].Shop[num]);
                    Player.Gold -= AllNPC[MerchantName].Shop[num].Price * AllNPC[MerchantName].Profit;
                    cout << "Trading Sucessful!\n";
                }
                else
                {
                    cout << "Not enough Gold.\n";
                }
            }
            else
            {
                cout << "Cancel Trading.\n";
            }
        }
    }
    else if (input == "Sell" || input == "sell" || input == "S" || input == "s")
    {
        cout << "Your Backpack: \n";
        Player.ListBackPackContent();
        cin >> num;
        if (num > 9 || num < 0)
        {
            cout << "PLs input between 0~9\n";
        }
        else
        {
            cout << "It will be sold for " << Player.Backpack[num].Price << " Gold,Confirm?\n";
            cin >> input;
            if (input == "Yes" || input == "yes" || input == "Y" || input == "y")
            {
                Player.Gold += Player.Backpack[num].Price;
                Player.Backpack[num] = ErrorItem;
                cout << "Trading Sucessful!\n";
            }
        }
    }
    else if (input == "Look" || input == "look" || input == "L" || input == "l")
    {
        cout << "Merchant is Selling: \n";
        AllNPC[MerchantName].ListShopContent();
    }
    else
    {
        cout << "No such Command.\n";
    }
}

bool ConbatPhase()
{

    NPC Monster = GreenGoblin; // demo只有一種怪，所以我這裡偷懶了
    cout << "You are now facing " << Monster.Name << ", you can choose to fight or Excape.\n";
    cout << "Monster Life: " << Monster.Health << ", ATK: " << Monster.ATK << ", DEF: " << Monster.DEF << endl;
    while (1)
    {
        string input;
        if (Player.NowHealth <= 0)
        {
            return 0;
        }
        else if (Monster.Health <= 0)
        {
            return 1;
        }
        else
        {

            cout << "Fight or Excape? ";
            cin >> input;
            if (input == "F" || input == "Fight" || input=="f")
            {
                int PlayerDmg = PlayerAttack(Player);
                int TotDmg = PlayerDmg - Monster.DEF;
                if (TotDmg >= 0)
                {
                    cout << "Dealt " << TotDmg << " Damage.";
                    Monster.Health -= TotDmg;
                }
                else
                {
                    cout << "Did not dealt ant Damage.";
                }
                cout << Monster.Name << " now has " << Monster.Health << " Health.\n";

                int MonDmg = Monster.ATK - Player.DEF;
                if (MonDmg < 0)
                {
                    MonDmg = 0;
                }

                Player.NowHealth -= MonDmg;
                cout << Monster.Name << "Attack you with " << MonDmg << " Damage, now you have " << Player.NowHealth << " Health remain.\n";
            }
            else if (input == "E" || input == "Excape" || input=="e")
            {
                int ExDmg = (2 * Monster.ATK - Player.DEF);
                if (ExDmg < 0)
                {
                    ExDmg = 0;
                }
                Player.NowHealth -= ExDmg;
                if (Player.NowHealth > 0)
                {
                    cout << Monster.Name << "Attack you with " << ExDmg << " Damage, now you have " << Player.NowHealth << " Health remain.\n";
                    cout << "And you sucessfully Excape.\n";
                    return 1;
                }
                else
                {
                    cout << Monster.Name << "Attack you with " << ExDmg << "Damage, now you have " << Player.NowHealth << " Health remain.\n";
                    return 0;
                }
            }
            else
            {
                cout << "No such Command.\n";
            }
        }
    }
}

int main()
{
    int LastLocaX = Player.cdtX;
    int LastLocaY = Player.cdtY;
    int ch, ch2;
    int MonLocaX = 0, MonLocaY = 0;
    bool Exit = false;
    string SysReturnInfo = "";
    string Merchant = "";
    bool MonAlive = 0;
    bool PlayerAlive = 1;

    switch (Player.CrtLocation)
        {

        case 1:
            CrtMap = GreenTown;
            break;
        default:
            CrtMap = ExMap;
            break;
        }

    while (!Exit)
    {
        
        Merchant = "";
        SysReturnInfo = "";
        ch = getch();
        system("cls");

        if (ch == 0 || ch == 224)
        {
            ch2 = getch();

            SysReturnInfo += Player.Moving(ch2);

            switch (CrtMap.content[Player.cdtX + (CrtMap.width + 1) * Player.cdtY])
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
                switch (CrtMap.content[Player.cdtX + (CrtMap.width + 1) * (Player.cdtY + 2)])
                {
                case 'W':
                    SysReturnInfo += "Weapon Merchant.";
                    Merchant = "W";
                    break;
                case 'A':
                    SysReturnInfo += "Armor Merchant.";
                    Merchant = "A";
                    break;
                }
                Player.cdtX = LastLocaX;
                Player.cdtY = LastLocaY;
                break;
            case 'X':
                MonLocaX = Player.cdtX;
                MonLocaY = Player.cdtY;
                Player.cdtX = LastLocaX;
                Player.cdtY = LastLocaY;
                MonAlive = 1;
                break;
            default:
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

            if (Merchant == "W" || Merchant == "A")
            {
                cout << "Buy? Sell? or just Look?\n";
                Trading(Merchant);
            }

            if (MonAlive)
            {
                PlayerAlive = ConbatPhase();
                if (PlayerAlive)
                {
                    cout<<"you win!!\n";
                    MonAlive = 0;
                    CrtMap.content[MonLocaX + (CrtMap.width + 1) * MonLocaY] = ' ';
                }
                else
                {
                    cout << "You died, Press any key to Exit.\n";
                    int e = getch();
                    Exit = 1;
                }
            }
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
                cout << "Command Mode\n";
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

#endif