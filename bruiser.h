#pragma once
#include "hp.h"
#include "statblock.h"
class Bruiser : public hp, public StatBlock
{
public:
    static const hptype HPGROWTH = (hptype)20u;
    static const stattype BASEAD = (stattype)4u;
    static const stattype BASEAP = (stattype)1u;

    Bruiser() : hp(HPGROWTH, HPGROWTH), StatBlock(BASEAD, BASEAP) {}

private:
};