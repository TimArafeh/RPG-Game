#pragma once
#include "hp.h"
#include "statblock.h"
class Assassin : public hp, public StatBlock
{
public:
    static const hptype HPGROWTH = (hptype)10u;
    static const stattype BASEAD = (stattype)7u;
    static const stattype BASEAP = (stattype)1u;

    Assassin() : hp(HPGROWTH, HPGROWTH), StatBlock(BASEAD, BASEAP) {}

private:
};