#include <iostream>
#include "playercharacter.h"

int main()
{
    PlayerCharacter ahri(new Tank());

    for (int i = 0; i < 2; i++)
    {
        std::cout << ahri.getClassName()
                  << " Level " << ahri.getLevel() << '\n'
                  << "-EXP: " << ahri.getCurrentEXP() << "/" << ahri.getEXPToNextLevel() << '\n'
                  << "-HP: " << ahri.getCurrentHP() << '/' << ahri.getMaxHP() << '\n'
                  << "-AD: " << ahri.getAD() << '\n'
                  << "-AP: " << ahri.getAP() << '\n';
        if (i < 1)
            ahri.gainEXP(100u);
    }
    return 0;
}