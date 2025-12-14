#ifndef MENU_H
#define MENU_H

#include <map>

class Command;

class Menu {
public:
    void addCommand(int option, Command* command);
    void show() const;
    void handleInput(int option);

private:
    std::map<int, Command*> m_commands;
};

#endif
