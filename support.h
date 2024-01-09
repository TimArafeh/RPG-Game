#pragma once
#include "hp.h"
#include "statblock.h"
class Support : public hp, public StatBlock
{
public:
    static const hptype HPGROWTH = (hptype)12u;
    static const stattype BASEAD = (stattype)2u;
    static const stattype BASEAP = (stattype)3u;

    Support() : hp(HPGROWTH, HPGROWTH), StatBlock(BASEAD, BASEAP) {}

private:
};