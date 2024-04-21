#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelup.h"

class Assassin : public hp, public StatBlock, public LevelSystem
{
public:
    static const hptype BASEHP = (hptype)10u;
    static const stattype BASEAD = (stattype)7u;
    static const stattype BASEAP = (stattype)1u;

    static const hptype HPGROWTH = (hptype)5u;
    static const stattype ADGROWTH = (stattype)6u;
    static const stattype APGROWTH = (stattype)1u;

    Assassin() : hp(BASEHP, BASEHP), StatBlock(BASEAD, BASEAP) {}

private:
    void LevelUp() override
    {
        setMaxHP(HPGROWTH + getMaxHp());
        increaseStats(ADGROWTH, APGROWTH);
    }
};