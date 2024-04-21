#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelup.h"

class Support : public hp, public StatBlock, public LevelSystem
{
public:
    static const hptype BASEHP = (hptype)9u;
    static const stattype BASEAD = (stattype)2u;
    static const stattype BASEAP = (stattype)3u;

    static const hptype HPGROWTH = (hptype)6u;
    static const stattype ADGROWTH = (stattype)1u;
    static const stattype APGROWTH = (stattype)2u;

    Support() : hp(BASEHP, BASEHP), StatBlock(BASEAD, BASEAP) {}

private:
    void LevelUp() override
    {
        setMaxHP(HPGROWTH + getMaxHp());
        increaseStats(ADGROWTH, APGROWTH);
    }
};