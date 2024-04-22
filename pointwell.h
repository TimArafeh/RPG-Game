#pragma once
#include <cstdint>
typedef std::uint16_t welltype;

// Changed HP to PointWell because the system of HP can be used on multiple different things as well like mana points or coins or anything that follows the same concept of a pointwell
class PointWell
{
public:
    // Returns true if set successfully
    bool setMax(welltype new_max)
    {
        if (new_max < 1)
            return false;

        MaxWell = new_max;

        if (CurrentFullness > MaxWell)
            CurrentFullness = MaxWell;

        return true;
    }

    // Max getter
    welltype getMax()
    {
        return MaxWell;
    }

    // Current getter
    welltype getCurrent()
    {
        return CurrentFullness;
    }

    void reduceCurrent(welltype damage)
    {
        if (damage > CurrentFullness)
        {
            CurrentFullness = 0;
            return;
        }

        CurrentFullness -= damage;
    }

    void increaseCurrent(welltype amount)
    {
        if (amount + CurrentFullness > MaxWell)
        {
            CurrentFullness = MaxWell;
            return;
        }

        CurrentFullness += amount;
    }

    PointWell()
    {
        CurrentFullness = 1;
        MaxWell = 1;
    }

    PointWell(welltype c, welltype m)
    {
        CurrentFullness = c;
        MaxWell = m;
        if (CurrentFullness > MaxWell)
            CurrentFullness = MaxWell;
    }

private:
    welltype CurrentFullness;
    welltype MaxWell;
};