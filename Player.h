#include "Ability.h"
#include "Money.h"
#include "Monster.h"
#include <iostream>
using namespace std;

class Player
{
    Ability ability;
    Money money;
public:
    // constructor 建構子
    Player(Ability ability, Money money) // 創造時要傳入變數
    {
        this->ability = ability;
        this->money = money;
    }

    void Attack(Monster monster)
    {
        cout<<"攻擊怪物"<<endl;
        monster.damage(this->ability.atk);
        cout<<"怪物受到傷害!"<<endl;
        monster.printmonsterHP();
    }

    void Skill(Monster monster)
    {
        monster.damage(this->ability.atk * 2);
    }
    void playerdamage(int amount)
    {
        this->ability.hp-=(amount-this->ability.def);
    }
    void printplayerHP()
    {
        cout<<"玩家當前血量:"<<this->ability.hp<<endl;
    }
};