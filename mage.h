#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelup.h"
class Mage : public hp, public StatBlock, public LevelSystem

{
public:
    static const hptype BASEHP = (hptype)7u;
    static const stattype BASEAD = (stattype)1u;
    static const stattype BASEAP = (stattype)4u;

    static const hptype HPGROWTH = (hptype)3u;
    static const stattype ADGROWTH = (stattype)1u;
    static const stattype APGROWTH = (stattype)4u;

    Mage() : hp(HPGROWTH, HPGROWTH), StatBlock(BASEAD, BASEAP) {}

private:
    void LevelUp() override
    {
        setMaxHP(HPGROWTH + getMaxHp());
        increaseStats(ADGROWTH, APGROWTH);
    }
};