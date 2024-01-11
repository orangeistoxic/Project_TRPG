#ifndef Item_cpp
#define Item_cpp

#include <iostream>
#include <map>

using namespace std;

class Item
{
public:
    string type;
    string name;
    int ID;
    int Price;
    int reqSTR = 0, reqDEX = 0, reqINT = 0, reqLVL = 0;
    int addLUK = 0, addSTR = 0, addDEX = 0, addINT = 0;
    int ATK = 0, DEF = 0;
    int RecoverHealth = 0, RecoverMana = 0;
    int StackLimit = 1;
    int Stack = 1;

    Item(string t = "Consumable", string n = "ErrorItem", int id = 0, int pric = 0)
    {
        type = t;
        name = n;
        ID = id;
        Price = pric;
    }

    void ShowAllStat_WeaponAndArmor()
    {
        cout << "Type: " << type << "  Name: " << name << "  ID: " << ID << " Price: " << Price << endl;
        cout << "Requirement: \nLevel: " << reqLVL << "  STR: " << reqSTR << "  DEX: " << reqDEX << "  INT: " << reqINT << endl;
        cout << "ATK: " << ATK << "  DEF: " << DEF << endl;
    }

    void ShowAllStat_Consumable()
    {
        cout << "Type: " << type << "  Name: " << name << "  ID: " << ID << " Price: " << Price << endl;
        cout << "Requirement: \nLevel: " << reqLVL << "  STR: " << reqSTR << "  DEX: " << reqDEX << "  INT: " << reqINT << endl;
        cout << "RecoverHealth: " << RecoverHealth << "  RecoverMana: " << RecoverMana << endl;
        cout << "Currently have: " << Stack << " Stack Limit: " << StackLimit << endl;
    }

    void SetRequiremant(int s, int d, int i, int lvl)
    {
        reqSTR = s;
        reqDEX = d;
        reqINT = i;
        reqLVL = lvl;
    }

    void SetAddtion(int s, int d, int i, int luk)
    {
        addSTR = s;
        addDEX = d;
        addINT = i;
        addLUK = luk;
    }

    void SetCombatStat(int atk, int def)
    {
        ATK = atk;
        DEF = def;
    }

    void SetRecoverHealthAndMana(int h, int m)
    {
        RecoverHealth = h;
        RecoverMana = m;
    }

    void SetStackLimit(int sl)
    {
        StackLimit = sl;
    }
};

Item ErrorItem;
Item RustedSword("Weapon", "RustedSword", 1, 20);
Item BarkWand("Weapon", "BarkWand", 2, 20);
Item StandardSword("Weapon", "StandardSword", 3, 30);
Item OakWand("Weapon", "OakWand", 4, 30);
Item LeatherArmor("Armor", "LeatherArmor", 51, 10);
Item GoldArmor("Armor", "GoldArmor", 52, 50);
Item SmallHealthPotion("Consumable", "SmallHealthPotion", 101, 5);
Item BigHealthPotion("Consumable", "BigHealthPotion", 102, 10);
Item SmallManaPotion("Consumable", "SmallManaPotion", 103, 5);
Item BigManaPotion("Consumable", "BigManaPotion", 104, 10);
Item GODHAND("Weapon", "GODHAND", 1001, 0);
Item GODBODY("Armor", "GODBODY", 1002, 0);

bool InitializedItem()
{
    RustedSword.SetCombatStat(10, 0);
    RustedSword.SetAddtion(5, 0, 0, 0);
    RustedSword.SetRequiremant(3, 3, 0, 5);

    BarkWand.SetCombatStat(10, 0);
    BarkWand.SetAddtion(0, 5, 5, 0);
    BarkWand.SetRequiremant(0, 5, 10, 5);

    StandardSword.SetAddtion(7, 0, 3, 0);
    StandardSword.SetCombatStat(15, 3);
    StandardSword.SetRequiremant(5, 3, 0, 7);

    OakWand.SetAddtion(0, 0, 7, 0);
    OakWand.SetCombatStat(15, 2);
    OakWand.SetRequiremant(0, 5, 15, 7);

    LeatherArmor.SetRequiremant(3, 3, 0, 3);
    LeatherArmor.SetAddtion(0, 5, 0, 3);
    LeatherArmor.SetCombatStat(0, 10);

    GoldArmor.SetRequiremant(10, 5, 5, 20);
    GoldArmor.SetAddtion(20, 0, 10, 40);
    GoldArmor.SetCombatStat(5, 40);

    SmallHealthPotion.SetRecoverHealthAndMana(20, 0);
    SmallHealthPotion.SetStackLimit(10);

    BigHealthPotion.SetRecoverHealthAndMana(50, 0);
    BigHealthPotion.SetStackLimit(10);

    GODHAND.SetAddtion(99, 99, 99, 99);
    GODHAND.SetCombatStat(99, 99);
    GODHAND.SetRequiremant(0, 0, 0, 0);

    GODBODY.SetAddtion(99, 99, 99, 99);
    GODBODY.SetCombatStat(99, 99);
    GODBODY.SetRequiremant(0, 0, 0, 0);

    return 1;
}

bool ItemInitialized = (bool)InitializedItem();

map<string, Item> AllItem =
    {
        {RustedSword.name, RustedSword},
        {BarkWand.name, BarkWand},
        {SmallHealthPotion.name, SmallHealthPotion},
        {BigHealthPotion.name, BigHealthPotion},
        {SmallManaPotion.name, SmallManaPotion},
        {BigManaPotion.name, BigManaPotion},
        {LeatherArmor.name, LeatherArmor},
        {GoldArmor.name, GoldArmor},
        {StandardSword.name, StandardSword},
        {OakWand.name, OakWand},
        {GODHAND.name, GODHAND},
        {GODBODY.name, GODBODY}};

#endif