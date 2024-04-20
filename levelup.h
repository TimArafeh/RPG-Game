#pragma once
#include <cstdint>

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class LevelSystem
{
public:
    static const exptype LEVEL2AT = 100u;

    LevelSystem()
    {
        CurrentLevel = 1u;
        CurrentEXP = 0u;
        EXPToNextLevel = LEVEL2AT;
    }

    void gainEXP(exptype gained_exp)
    {
        CurrentEXP += gained_exp;
        while (check_if_level())
            ;
        {
        }
    }

    leveltype getLevel()
    {
        return CurrentLevel;
    }

    exptype getCurrentEXP()
    {
        return CurrentEXP;
    }

    exptype getEXPToNextLevel()
    {
        return EXPToNextLevel;
    }

    virtual void LevelUp() = 0;

protected:
    leveltype CurrentLevel;
    exptype CurrentEXP;
    exptype EXPToNextLevel;

    bool check_if_level()
    {
        // At level 1 needs 0xp
        // At level 2 needs (LEVEL2AT) exp
        // At level 3 needs (previous_required_exp * LEVELSCALAR) exp
        // At level 4 needs (previous_required_exp * LEVELSCALAR) exp
        // ... (Basically looking to make it so that the exp needed for every level increases as you increase in level)

        static const leveltype LEVELSCALAR = 2u;
        if (CurrentEXP >= EXPToNextLevel)
        {
            CurrentLevel++;
            LevelUp();
            EXPToNextLevel *= LEVELSCALAR;
            return true;
        }

        return false;
    }
};