#include <iostream>
#include "allclasses.h"

int main()
{
    Bruiser darius;
    Mage ahri;
    Support janna;
    Assassin zed;

    /*
    std::cout << "Bruiser\n"
              << "-MaxHP: " << darius.getMaxHp() << '\n'
              << "-AD: " << darius.getAD() << '\n'
              << "-AP: " << darius.getAP() << '\n';
    */

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Ahri (Level " << ahri.getLevel() << ")" << '\n'
                  << "-EXP: " << ahri.getCurrentEXP() << "/" << ahri.getEXPToNextLevel() << '\n'
                  << "-MaxHP: " << ahri.getMaxHp() << '\n'
                  << "-AD: " << ahri.getAD() << '\n'
                  << "-AP: " << ahri.getAP() << '\n';
        if (i < 1)
            ahri.gainEXP(100u);
    }

    /*
    std::cout << "Support\n"
              << "-MaxHP: " << janna.getMaxHp() << '\n'
              << "-AD: " << janna.getAD() << '\n'
              << "-AP: " << janna.getAP() << '\n';

    std::cout << "Assassin\n"
              << "-MaxHP: " << zed.getMaxHp() << '\n'
              << "-AD: " << zed.getAD() << '\n'
              << "-AP: " << zed.getAP() << '\n';
    */
    return 0;
}