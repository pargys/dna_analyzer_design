//
// Created by y on 7/5/20.
//

#ifndef SRC_CREATE_CMD_FACTORY_H
#define SRC_CREATE_CMD_FACTORY_H
class ICommand;
#include <string>

class CreateCmdFactory{
public:
    static ICommand* create(const std::string& cmdName);
};

#endif //SRC_CREATE_CMD_FACTORY_H
