#include<iostream>
#include<map>

using namespace std;

class Item
{
public:
    string type;
    string name;
    int ID;
    int reqSTR=0,reqDEX=0,reqINT=0,reqLVL=0;
    int addLUK=0,addSTR=0,addDEX=0,addINT=0;
    int ATK=0,DEF=0;
    int RecoverHealth=0,RecoverMana=0;
    int StackLimit=1;
    int Stack=1;

    Item(string t="Comsumable",string n="ErrorItem",int id=0)
    {
        type=t;
        name=n;
        ID=id;
    }
    void ShowAllStat_WeaponAndArmor()
    {
        cout << "Type: " << type << "  Name: " << name << "  ID: " << ID << endl;
        cout<<"Requirement: \nLevel: "<<reqLVL<<"  STR: "<<reqSTR<<"  DEX: "<<reqDEX<<"  INT: "<<reqINT<<endl;
        cout<<"ATK: "<<ATK<<"  DEF: "<<DEF<<endl;

    }
    void ShowAllStat_Comsumable()
    {
        cout << "Type: " << type << "  Name: " << name << "  ID: " << ID << endl;
        cout << "Requirement: \nLevel: " << reqLVL << "  STR: " << reqSTR << "  DEX: " << reqDEX << "  INT: " << reqINT << endl;
        cout << "RecoverHealth: " << RecoverHealth << "  RecoverMana: " << RecoverMana << endl;
    }
    void SetRequiremant(int s,int d,int i,int lvl)
    {
        reqSTR = s;
        reqDEX = d;
        reqINT = i;
        reqLVL = lvl;
    }
    void SetAddtion(int s, int d, int i, int luk)
    {
        addSTR=s;
        addDEX=d;
        addINT=i;
        addLUK=luk;
    }
    void SetCombatStat(int atk, int def)
    {
        ATK=atk;
        DEF=def;
    }
    void SetRecoverHealthAndMana(int h,int m)
    {
        RecoverHealth=h;
        RecoverMana=m;
    }
    void SetStackLimit(int sl)
    {
        StackLimit=sl;
    }
};

Item Sword("Weapon", "Sword",1);
Item Wand("Weapon","Wand",2);
Item SmallHealthPotion("Comsumable", "SmallHealthPotion",101);
Item BigHealthPotion("Comsumable", "BigHealthPotion",102);
Item SmallManaPotion("Comsumable", "SmallManaPotion",103);
Item BigManaPotion("Comsumable", "BigManaPotion",104);

map<string, Item> AllItem =
    {
        {Sword.name, Sword},
        {Wand.name, Wand},
        {SmallHealthPotion.name, SmallHealthPotion},
        {BigHealthPotion.name, BigHealthPotion},
        {SmallManaPotion.name, SmallManaPotion},
        {BigManaPotion.name, BigManaPotion}};

bool InitializedItem()
{
    Sword.SetCombatStat(10,0);
    Sword.SetAddtion(5,0,0,0);
    Sword.SetRequiremant(10,5,0,5);

    Wand.SetCombatStat(10,0);
    Wand.SetAddtion(0,5,5,0);
    Wand.SetRequiremant(0,5,10,5);

    SmallHealthPotion.SetRecoverHealthAndMana(20,0);
    SmallHealthPotion.SetStackLimit(10);

    BigHealthPotion.SetRecoverHealthAndMana(50,0);
    BigHealthPotion.SetStackLimit(10);

    return 1;

}