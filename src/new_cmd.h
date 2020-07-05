//
// Created by y on 7/5/20.
//

#ifndef SRC_NEW_CMD_H
#define SRC_NEW_CMD_H
#include "creation_cmds.h"

class NewCmd: public CreationCmds{
public:
    /*virtual*/void run(std::vector<std::string>);
};

#endif //SRC_NEW_CMD_H
