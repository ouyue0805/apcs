#include <iostream>
// #include "Player.h"
// #include "Monster.h"
// #include "Ability.h"
// #include "Money.h"
using namespace std;

class Player;

struct Ability // 將能力值打包
{
    int atk;
    int def;
    int spd;
    int luk;
    int hp;
};
struct Money
{
    int amount;
    int diamond;
};

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
    void attackplayer(Player &player)
    {
        cout<<"攻擊玩家"<<endl;
        player.playerdamage(this->ability.atk);
        cout<<"玩家受到傷害!"<<endl;
        player.printplayerHP();
    }
};
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

    void Attack(Monster &monster)
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
int main() {
    Player player = Player(
        {.atk = 10, .def = 10, .spd =10, .luk = 10, .hp=100},
        {.amount = 0, .diamond = 0}
    );
    Monster monster = Monster(
        {.atk = 5, .def = 5, .spd =5, .luk = 5, .hp=1000}
    );
    player.Attack(monster);
    monster.attackplayer(player);

    return 0;
}
