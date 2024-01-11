#ifndef Player_cpp
#define Player_cpp
#include <iostream>
#include "Item.cpp"

using namespace std;

class player
{
public:
    player() {}

    int cdtX = 2;
    int cdtY = 2;

    int CrtLocation = 1;

    int Level = 5;

    int Strength = 5 + Level + EquippedArmor.addSTR + EquippedWeapon.addSTR;
    int Dexterity = 5 + Level + EquippedArmor.addDEX + EquippedWeapon.addDEX;
    int Intelligence = 5 + Level + EquippedArmor.addINT + EquippedWeapon.addINT;

    int ATK = EquippedArmor.ATK + EquippedWeapon.ATK;
    int DEF = EquippedArmor.DEF + EquippedWeapon.DEF;

    int Luck = 0 + Level / 5 + EquippedArmor.addINT + EquippedWeapon.addINT;

    int MaxHealth = 100 + Strength;
    int MaxMana = 100 + Intelligence;

    int NowHealth = MaxHealth;
    int NowMana = MaxMana;

    int Gold = 100;
    Item Backpack[10] = {
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

    Item EquippedWeapon;
    Item EquippedArmor;

    string EquipingArmor(Item armor)
    {
        if (armor.type == "Armor")
        {
            if (Strength >= armor.reqSTR && Dexterity >= armor.reqDEX && Intelligence >= armor.reqINT && Level >= armor.reqLVL)
            {
                EquippedArmor = armor;
                RefreshPlayerStat();
                return "Equip Success!";
            }
            else
            {
                return "You Don't have enough Stat!";
            }
        }
        else
        {
            return "Equip Failed! Wrong Item's Type!";
        }
    }

    string EquipingWeapon(Item weapon)
    {
        if (weapon.type == "Weapon")
        {
            if (Strength >= weapon.reqSTR && Dexterity >= weapon.reqDEX && Intelligence >= weapon.reqINT && Level >= weapon.reqLVL)
            {
                EquippedWeapon = weapon;
                RefreshPlayerStat();
                return "Equip Success!";
            }
            else
            {
                return "You Don't have enough Stat!";
            }
        }
        else
        {
            return "Equip Failed! Wrong Item's Type!";
        }
    }

    void EquipingItem()
    {
        string word;
        cin >> word;
        Item item = AllItem[word];
        bool e = 0;
        for (int i = 0; i < 10; i++)
        {
            if (Backpack[i].name == item.name)
            {
                if (item.type == "Weapon")
                {
                    Item item2 = EquippedWeapon;
                    cout << EquipingWeapon(item) << endl;
                    Backpack[i] = item2;
                    e = 1;
                }
                else if (item.type == "Armor")
                {
                    Item item2 = EquippedArmor;
                    cout << EquipingArmor(item) << endl;
                    Backpack[i] = item2;
                    e = 1;
                }
            }
            if (!e)
            {
                cout << "You don't have this in your Backpack!\n";
            }
        }
    }

    void ListBackPackContent()
    {
        cout << "| ";
        for (int i = 0; i < 10; i++)
        {
            if (Backpack[i].name == "ErrorItem")
            {
                cout << "                     | ";
            }
            else if (Backpack[i].type == "Consumable")
            {
                cout << Backpack[i].name << " x" << Backpack[i].Stack << " | ";
            }
            else
            {
                cout << Backpack[i].name << " | ";
            }
            if (i == 4)
            {
                cout << endl
                     << "| ";
            }
        }
        cout << endl;
    }

    void SetCoordinate(int x, int y)
    {
        cdtX = x;
        cdtY = y;
    }

    string Moving(int ch2)
    {
        switch (ch2)
        {
        case 72:
            cdtY--;
            return "72 up \n";

        case 75:
            cdtX--;
            return "75 left \n";

        case 80:
            cdtY++;
            return "80 down \n";

        case 77:
            cdtX++;
            return "77 right \n";

        default:
            return to_string(ch2) + "  No such Input \n";
        }
    }

    void SetGold(int num)
    {
        Gold = num;
    }

    string GetItem(Item item)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Backpack[i].name == item.name && Backpack[i].Stack < Backpack[i].StackLimit)
            {
                Backpack[i].Stack += 1;
                return "Item successfully Added!";
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (Backpack[i].name == "ErrorItem")
            {
                Backpack[i] = item;
                return "Item successfully Added!";
            }
        }
        return "Backpack is Full!";
    }

    void CheatingGear_1()
    {
        cout << GetItem(RustedSword) << endl;
        cout << GetItem(LeatherArmor) << endl;
        cout << GetItem(SmallHealthPotion) << endl;
        cout << GetItem(SmallHealthPotion) << endl;
        cout << GetItem(SmallHealthPotion) << endl;
    }

    void CheatingGear_2()
    {
        cout << GetItem(StandardSword) << endl;
        cout << GetItem(GoldArmor) << endl;
        cout << GetItem(BigHealthPotion) << endl;
        cout << GetItem(BigHealthPotion) << endl;
        cout << GetItem(BigHealthPotion) << endl;
        cout << GetItem(BigHealthPotion) << endl;
        cout << GetItem(BigHealthPotion) << endl;
    }

    void RefreshPlayerStat()
    {
        Strength = 5 + Level + EquippedArmor.addSTR + EquippedWeapon.addSTR;
        Dexterity = 5 + Level + EquippedArmor.addDEX + EquippedWeapon.addDEX;
        Intelligence = 5 + Level + EquippedArmor.addINT + EquippedWeapon.addINT;

        ATK = EquippedArmor.ATK + EquippedWeapon.ATK;
        DEF = EquippedArmor.DEF + EquippedWeapon.DEF;

        int Luck = 0 + Level / 5 + EquippedArmor.addINT + EquippedWeapon.addINT;

        MaxHealth = 100 + Strength;
        MaxMana = 100 + Intelligence;

        if (NowHealth > MaxHealth)
        {
            NowHealth = MaxHealth;
        }
        if (NowMana > MaxMana)
        {
            NowMana = MaxMana;
        }
    }

    void GODMODE()
    {
        EquippedArmor = GODBODY;
        EquippedWeapon = GODHAND;
        Gold = 99999;
        RefreshPlayerStat();
    }

    void ShowPlayerStat()
    {
        cout << "Level: " << Level << endl;
        cout << "Strength: " << Strength << " | Dexterity: " << Dexterity << " | Intelligence: " << Intelligence << endl;
        cout << "Luck: " << Luck << endl;
        cout << "ATK: " << ATK << " | DEF: " << DEF << endl;
        cout << "Health: " << NowHealth << " | MaxHealth: " << MaxHealth << endl;
        cout << "Mana: " << NowMana << " | MaxMana: " << MaxMana << endl;
        cout << "Gold: " << Gold << endl;
        cout << "Armor: " << EquippedArmor.name << endl;
        cout << "Weapon: " << EquippedWeapon.name << endl;
    }
};

#endif