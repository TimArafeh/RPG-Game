#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelup.h"

class Bruiser : public hp, public StatBlock, public LevelSystem
{
public:
    static const hptype BASEHP = (hptype)20u;
    static const stattype BASEAD = (stattype)4u;
    static const stattype BASEAP = (stattype)1u;

    static const hptype HPGROWTH = (hptype)15u;
    static const stattype ADGROWTH = (stattype)3u;
    static const stattype APGROWTH = (stattype)1u;

    Bruiser() : hp(BASEHP, BASEHP), StatBlock(BASEAD, BASEAP) {}

private:
    void LevelUp() override
    {
        setMaxHP(HPGROWTH + getMaxHp());
        increaseStats(ADGROWTH, APGROWTH);
    }
};