#include "Menu.h"
#include "Command.h"
#include "Logger.h"
#include <iostream>

void Menu::addCommand(int option, const std::string& label, Command* command) {
    m_items[option] = MenuItem{label, command};
}

void Menu::show() const {
    for (std::map<int, MenuItem>::const_iterator it = m_items.begin();
         it != m_items.end(); ++it) {
        std::cout << it->first << ") " << it->second.label << std::endl;
    }
}

void Menu::handleInput(int option) {
    if (m_items.count(option)) {
        m_items.at(option).command->execute();
    } else {
        Logger::instance().warning("Invalid menu option");
    }
}

