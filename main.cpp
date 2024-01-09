#include <iostream>
#include "allclasses.h"

int main()
{
    Bruiser darius;
    Mage ahri;
    Support janna;
    Assassin zed;

    std::cout << "Bruiser\n"
              << "-MaxHP: " << darius.getMaxHp() << '\n'
              << "-AD: " << darius.getAD() << '\n'
              << "-AP: " << darius.getAP() << '\n';

    std::cout << "Mage\n"
              << "-MaxHP: " << ahri.getMaxHp() << '\n'
              << "-AD: " << ahri.getAD() << '\n'
              << "-AP: " << ahri.getAP() << '\n';

    std::cout << "Support\n"
              << "-MaxHP: " << janna.getMaxHp() << '\n'
              << "-AD: " << janna.getAD() << '\n'
              << "-AP: " << janna.getAP() << '\n';

    std::cout << "Assassin\n"
              << "-MaxHP: " << zed.getMaxHp() << '\n'
              << "-AD: " << zed.getAD() << '\n'
              << "-AP: " << zed.getAP() << '\n';

    return 0;
}