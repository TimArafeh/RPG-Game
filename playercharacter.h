#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>
#include <string>

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate : public StatBlock
{
public:
    static const exptype LEVEL2AT = 100u;

    PlayerCharacterDelegate() : StatBlock(0u, 0u)
    {
        CurrentLevel = 1u;
        CurrentEXP = 0u;
        EXPToNextLevel = LEVEL2AT;
        HP = std::make_unique<PointWell>();
    }

    void gainEXP(exptype gained_exp)
    {
        CurrentEXP += gained_exp;
        while (check_if_level())
            ;
        {
        }
    }

    leveltype getLevel()
    {
        return CurrentLevel;
    }

    exptype getCurrentEXP()
    {
        return CurrentEXP;
    }

    exptype getEXPToNextLevel()
    {
        return EXPToNextLevel;
    }

    virtual void LevelUp() = 0;
    virtual std::string getClassName() = 0;

    std::unique_ptr<PointWell> HP;

protected:
    leveltype CurrentLevel;
    exptype CurrentEXP;
    exptype EXPToNextLevel;

    bool check_if_level()
    {
        // At level 1 needs 0xp
        // At level 2 needs (LEVEL2AT) exp
        // At level 3 needs (previous_required_exp * LEVELSCALAR) exp
        // At level 4 needs (previous_required_exp * LEVELSCALAR) exp
        // ... (Basically looking to make it so that the exp needed for every level increases as you increase in level)

        static const leveltype LEVELSCALAR = 2u;
        if (CurrentEXP >= EXPToNextLevel)
        {
            CurrentLevel++;
            LevelUp();
            EXPToNextLevel *= LEVELSCALAR;
            return true;
        }

        return false;
    }
};

#define PCCONSTRUCT : PlayerCharacterDelegate() \
    {                                           \
        HP->setMax(BASEHP);                     \
        HP->increaseCurrent(BASEHP);            \
        increaseStats(BASEAD, BASEAP);          \
    }

#define LEVELUP                                                                        \
    void LevelUp() override                                                            \
    {                                                                                  \
        HP->setMax((welltype)(BASEHP / 2.f) + HP->getMax());                           \
        HP->increaseCurrent((welltype)(BASEHP / 2.f));                                 \
        increaseStats((stattype)((BASEAD + 1) / 2.f), (stattype)((BASEAP + 1) / 2.f)); \
    }

class Mage : public PlayerCharacterDelegate
{
public:
    static const welltype BASEHP = (welltype)8u;
    static const stattype BASEAD = (stattype)1u;
    static const stattype BASEAP = (stattype)8u;

    Mage() PCCONSTRUCT

        std::string getClassName() override
    {
        return std::string("Mage");
    }

private:
    LEVELUP
};

class Tank : public PlayerCharacterDelegate
{
public:
    static const welltype BASEHP = (welltype)20u;
    static const stattype BASEAD = (stattype)4u;
    static const stattype BASEAP = (stattype)1u;

    Tank() PCCONSTRUCT

        std::string getClassName() override
    {
        return std::string("Tank");
    }

private:
    LEVELUP
};

class Assassin : public PlayerCharacterDelegate
{
public:
    static const welltype BASEHP = (welltype)10u;
    static const stattype BASEAD = (stattype)8u;
    static const stattype BASEAP = (stattype)1u;

    Assassin() PCCONSTRUCT

        std::string getClassName() override
    {
        return std::string("Assassin");
    }

private:
    LEVELUP
};

class Support : public PlayerCharacterDelegate
{
public:
    static const welltype BASEHP = (welltype)6u;
    static const stattype BASEAD = (stattype)2u;
    static const stattype BASEAP = (stattype)4u;

    Support() PCCONSTRUCT
        std::string getClassName() override
    {
        return std::string("Support");
    }

private:
    LEVELUP
};

class PlayerCharacter
{
private:
    PlayerCharacterDelegate *pcclass;

public:
    PlayerCharacter() = delete;
    PlayerCharacter(PlayerCharacterDelegate *pc) : pcclass(pc) {}

    ~PlayerCharacter()
    {
        delete pcclass;
        pcclass = nullptr;
    }

    std::string getClassName()
    {
        return pcclass->getClassName();
    }

    leveltype getLevel()
    {
        return pcclass->getLevel();
    }

    exptype getCurrentEXP()
    {
        return pcclass->getCurrentEXP();
    }

    exptype getEXPToNextLevel()
    {
        return pcclass->getEXPToNextLevel();
    }

    welltype getCurrentHP()
    {
        return pcclass->HP->getCurrent();
    }

    welltype getMaxHP()
    {
        return pcclass->HP->getMax();
    }

    stattype getAD()
    {
        return pcclass->getAD();
    }

    stattype getAP()
    {
        return pcclass->getAP();
    }

    void gainEXP(exptype amt)
    {
        pcclass->gainEXP(amt);
    }

    void takeDamage(welltype amt)
    {
        pcclass->HP->reduceCurrent(amt);
    }

    void heal(welltype amt)
    {
        pcclass->HP->increaseCurrent(amt);
    }
};