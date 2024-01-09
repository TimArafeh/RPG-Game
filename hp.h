#pragma once
#include "hitpointtypes.h"

class hp
{
public:
    // Returns true if set successfully
    bool setMaxHP(hptype new_max_hp)
    {
        if (new_max_hp < 1)
            return false;

        MaxHP = new_max_hp;

        if (CurrentHP > MaxHP)
            CurrentHP = MaxHP;

        return true;
    }

    // Max HP getter
    hptype getMaxHp()
    {
        return MaxHP;
    }

    // Current HP getter
    hptype getCurrentHP()
    {
        return CurrentHP;
    }

    void damageTaken(hptype damage)
    {
        if (damage > CurrentHP)
        {
            CurrentHP = 0;
            return;
        }

        CurrentHP -= damage;
    }

    void healingTaken(hptype heal)
    {
        if (heal += CurrentHP > MaxHP)
        {
            CurrentHP = MaxHP;
        }

        CurrentHP += heal;
    }

    hp()
    {
        CurrentHP = 1;
        MaxHP = 1;
    }

    hp(hptype cHP, hptype mHP)
    {
        CurrentHP = cHP;
        MaxHP = mHP;
        if (CurrentHP > MaxHP)
            CurrentHP = MaxHP;
    }

private:
    hptype Shield;
    hptype CurrentHP;
    hptype MaxHP;
};