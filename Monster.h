#include "Ability.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Monster
{
    Ability ability;
public:
    Monster(Ability ability)
    {
        this->ability = ability;
    }
    void damage(int amount)
    {
        this->ability.hp -= (amount-this->ability.def);
    }
    void printmonsterHP()
    {
        cout<<"怪物當前血量:"<<this->ability.hp<<endl;
    }
    void attackplayer(Player player)
    {
        cout<<"攻擊玩家"<<endl;
        player.playerdamage(this->ability.atk);
        cout<<"玩家受到傷害!"<<endl;
        player.printplayerHP();
    }
};