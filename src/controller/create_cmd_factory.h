//
// Created by y on 7/5/20.
//

#ifndef SRC_CREATE_CMD_FACTORY_H
#define SRC_CREATE_CMD_FACTORY_H
#include <map>
#include <string>

class ICommand;
class Parser;

class CreateCmdFactory{
public:
    static std::map<std::string, ICommand*> init();
    static ICommand* create(const Parser& cmdName);
    static void release();

private:
    static std::map<std::string, ICommand*> s_commands;
};

#endif //SRC_CREATE_CMD_FACTORY_H
