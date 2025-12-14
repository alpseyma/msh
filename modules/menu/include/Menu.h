#ifndef MENU_H
#define MENU_H

#include <map>
#include <string>

class Command;

class Menu {
public:
    void addCommand(int option, const std::string& label, Command* command);
    void show() const;
    void handleInput(int option);

private:
    struct MenuItem {
        std::string label;
        Command* command;
    };

    std::map<int, MenuItem> m_items;
};

#endif

