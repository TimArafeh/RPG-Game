#pragma once
#include "stattypes.h"

class StatBlock
{

    stattype AD; // 0xFF
    stattype AP; // 0xFF

public:
    StatBlock()
    {
        AD = (stattype)1u;
        AP = (stattype)1u;
    }

    StatBlock(stattype s, stattype i)
    {
        AD = s;
        AP = i;
    }

    stattype getAD() { return AD; }
    stattype getAP() { return AP; }
};