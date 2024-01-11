#ifndef NPC_cpp
#define NPC_cpp
#include <iostream>
#include <map>
#include "Item.cpp"

using namespace std;

class NPC
{
public:
    string Name;
    int Location;
    string Type;
    float Profit=1.2;
    int Health=100;
    int ATK=0,DEF=0;

    NPC(string name = "NoBody", int loca = 0, string type = "AM")
    {
        Name = name;
        Location = loca;
        Type = type;
    }

    Item Shop[10] = {
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
        ErrorItem,
    };

    void AddShopContent(Item item)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Shop[i].name == item.name && Shop[i].Stack < Shop[i].StackLimit)
            {
                Shop[i].Stack += 1;
                return ;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (Shop[i].name == "ErrorItem")
            {
                Shop[i] = item;
                return ;
            }
        }
        return ;
    }

    void ListShopContent()
    {
        cout << "| ";
        for (int i = 0; i < 10; i++)
        {
            if (Shop[i].name == "ErrorItem")
            {
                cout << "                     | ";
            }
            else if (Shop[i].type == "Consumable")
            {
                cout << Shop[i].name << " x" << Shop[i].Stack << " | ";
            }
            else
            {
                cout << Shop[i].name << " | ";
            }
            if (i == 4)
            {
                cout << endl
                     << "| ";
            }
        }
        cout << endl;
    }

    void SetProfit(int p)
    {
        Profit=p;
    }

    void SetBasicStat(int h,int atk,int def)
    {
        Health=h;
        ATK=atk;
        DEF=def;
    }
};

NPC GreenTownWM("GreenTownWM", 1, "WM");
NPC GreenTownAM("GreenTownAM", 1, "AM");
NPC GreenGoblin("GreenGoblin",1,"EMY");


bool InitializedNPC()
{
    GreenTownWM.AddShopContent(RustedSword);
    GreenTownWM.AddShopContent(BarkWand);
    GreenTownWM.AddShopContent(StandardSword);
    GreenTownWM.AddShopContent(OakWand);
    GreenTownWM.SetProfit(1.5);

    GreenTownAM.AddShopContent(LeatherArmor);
    GreenTownAM.AddShopContent(GoldArmor);
    GreenTownAM.AddShopContent(SmallHealthPotion);
    GreenTownAM.AddShopContent(BigHealthPotion);
    GreenTownAM.AddShopContent(SmallManaPotion);
    GreenTownAM.AddShopContent(BigManaPotion);
    GreenTownAM.SetProfit(1.5);

    GreenGoblin.SetBasicStat(50,10,5);

    return 1;
}

bool NPCInitialized = (bool)InitializedNPC();

map<string, NPC> AllNPC =
    {
        {GreenTownWM.Name, GreenTownWM},
        {GreenTownAM.Name, GreenTownAM}};

#endif