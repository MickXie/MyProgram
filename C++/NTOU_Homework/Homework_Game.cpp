#include <iostream>
#include <string>
#include <memory>

class Character
{
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Character(const std::string &n, int h, int ap)
        : name(n), health(h), attackPower(ap) {}
    virtual ~Character() = default;

    virtual void attack(Character *target) = 0;
    virtual void specialAbility() = 0;

    void takeDamage(int damage)
    {
        health -= damage;
        if (health < 0)
            health = 0;
    }

    bool isDefeated() const { return health <= 0; }

    void displayStatus() const
    {
        std::cout << name << " - Health: " << health
                  << "| Attack Power: " << attackPower << std::endl;
    }

    const std::string &getName() const { return name; }
    int getHealth() const { return health; }
};

class Warrior : public Character
{
public:
    Warrior(const std::string &n) : Character(n, 120, 15) {}

    void attack(Character *target) override
    {
        std::cout << name << " swings a sword at " << target->getName() << "!\n";
        target->takeDamage(attackPower);
        std::cout << target->getName() << " takes " << attackPower << " damage.\n";
        target->displayStatus();
        displayStatus();
    }

    void specialAbility() override
    {
        std::cout << name << " uses Berserk! Attack power increases!\n";
        attackPower += 5;
    }
};
class Mage : public Character
{
public:
    Mage(const std::string &n) : Character(n, 100, 20) {}

    void attack(Character *target) override
    {
        std::cout << name << " casts a fireball at " << target->getName() << "!\n";
        target->takeDamage(attackPower);
        std::cout << target->getName() << " takes " << attackPower << " damage.\n";
        target->displayStatus();
        displayStatus();
    }

    void specialAbility() override
    {
        std::cout << name << " heals with magic!\n";
        health += 30;
    }
};

// Archer 派生類
class Archer : public Character
{
public:
    Archer(const std::string &n) : Character(n, 100, 18) {}

    void attack(Character *target) override
    {
        std::cout << name << " shoots an arrow at " << target->getName() << "!\n";
        target->takeDamage(attackPower);
        std::cout << target->getName() << " takes " << attackPower << " damage.\n";
        target->displayStatus();
        displayStatus();
    }

    void specialAbility() override
    {
        std::cout << name << " uses Rapid Shot! Attacks twice!\n";
        attackPower *= 2;
    }
};

class BattleArena
{
public:
    static void startBattle(Character *player1, Character *player2)
    {
        std::cout << "Battle Begins: "
                  << player1->getName() << " VS " << player2->getName() << "!\n";

        while (!player1->isDefeated() && !player2->isDefeated())
        {

            player1->attack(player2);
            if (player2->isDefeated())
            {
                std::cout << player2->getName() << " is defeated!\n";
                break;
            }

            player2->attack(player1);
            if (player1->isDefeated())
            {
                std::cout << player1->getName() << " is defeated!\n";
                break;
            }
        }

        if (player1->isDefeated())
        {
            std::cout << player2->getName() << " wins the battle!\n";
        }
        else
        {
            std::cout << player1->getName() << " wins the battle!\n";
        }
    }
};

int main()
{
    std::unique_ptr<Character> player1 = std::make_unique<Archer>("MyHero");
    std::unique_ptr<Character> player2 = std::make_unique<Warrior>("MyBoss");

    BattleArena::startBattle(player1.get(), player2.get());

    return 0;
}