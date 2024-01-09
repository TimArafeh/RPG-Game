#pragma once
#include "hp.h"
#include "statblock.h"
class Mage : public hp, public StatBlock
{
public:
    static const hptype HPGROWTH = (hptype)7u;
    static const stattype BASEAD = (stattype)1u;
    static const stattype BASEAP = (stattype)4u;

    Mage() : hp(HPGROWTH, HPGROWTH), StatBlock(BASEAD, BASEAP) {}

private:
};