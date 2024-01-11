#ifndef AttackSkill_cpp
#define AttackSkill_cpp
#include <iostream>
#include <map>
#include "Item.cpp"
#include "Player.cpp"
#include "main.cpp"

using namespace std;

int Swing(int ATK)
{
    cout << "You use 'Swing'\n";
    return ATK;
}

int QuickSwing(int Dex, int ATK)
{
    cout << "You use 'QuickSwing'\n";
    return Dex * 0.5 + ATK;
}

int HeavySwing(int Str, int ATK)
{
    cout << "You use 'HeavySwing'\n";
    return Str * 0.5 + ATK;
}

int FireBall(int ATK)
{
    cout << "You cast 'FireBall'\n";
    return ATK;
}

int BigFireBall(int Int, int ATK)
{
    cout << "You cast 'BigFireBall'\n";
    return Int + ATK;
}

int RustedSwordAttack(player P)
{
    int ran = rand() % 3;
    switch (ran)
    {
    case 1:
        return Swing(P.ATK);
        break;
    case 2:
        return QuickSwing(P.Dexterity, P.ATK);
        break;
    case 3:
        return HeavySwing(P.Strength, P.ATK);
        break;
    }
    return 0;
}

int StandardSwordAttack(player P)
{
    int ran = rand() % 3;
    switch (ran)
    {
    case 1:
        return Swing(P.ATK);
        break;
    case 2:
        return QuickSwing(P.Dexterity, P.ATK);
        break;
    case 3:
        return HeavySwing(P.Strength, P.ATK);
        break;
    }
    return 0;
}

int BarkWandAttack(player P)
{
    int ran = rand() % 3;
    switch (ran)
    {
    case 1:
        return FireBall(P.ATK);
        break;
    case 2:
        return FireBall(P.ATK);
        break;
    case 3:
        return BigFireBall(P.Intelligence, P.ATK);
        break;
    }
    return 0;
}

int OakWandAttack(player P)
{
    int ran = rand() % 3;
    switch (ran)
    {
    case 1:
        return FireBall(P.ATK);
        break;
    case 2:
        return FireBall(P.ATK);
        break;
    case 3:
        return BigFireBall(P.Intelligence, P.ATK);
        break;
    }
    return 0;
}

int GodWraith(int ATK)
{
    cout << "Fury!!!!!!!!!!!!!!!!!!!!!!!\n";
    return ATK;
}

int PlayerAttack(player P)
{
    int Dmg = 0;
    switch (P.EquippedWeapon.ID)
    {
    case 1:
        Dmg = RustedSwordAttack(P);
        break;
    case 2:
        Dmg = BarkWandAttack(P);
        break;
    case 3:
        Dmg = StandardSwordAttack(P);
        break;
    case 4:
        Dmg = OakWandAttack(P);
        break;
    case 1001:
        Dmg = GodWraith(P.ATK);
        break;
    default:
        Dmg = 0;
        break;
    }
    return Dmg;
}

#endif