//
// Created by y on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H
#include <vector>
#include <string>

class ICommand{
public:
    virtual void run(std::vector<std::string>) = 0;
};

#endif //SRC_I_COMMAND_H
