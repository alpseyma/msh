#include "Menu.h"
#include "Command.h"
#include "Logger.h"
#include <iostream>

void Menu::addCommand(int option, Command* command) {
    m_commands[option] = command;
}

void Menu::show() const {
    Logger::instance().info("Menu:");
    for (std::map<int, Command*>::const_iterator it = m_commands.begin();
         it != m_commands.end(); ++it) {
        std::cout << it->first << ". Command" << std::endl;
    }
}

void Menu::handleInput(int option) {
    if (m_commands.count(option)) {
        m_commands[option]->execute();
    } else {
        Logger::instance().warning("Invalid menu option");
    }
}
