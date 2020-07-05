//
// Created by y on 7/5/20.
//

#ifndef SRC_NEW_CMD_H
#define SRC_NEW_CMD_H
#include "creation_cmds.h"
#include "parser.h"

class NewCmd: public CreationCmds{
public:
    NewCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd);
};

#endif //SRC_NEW_CMD_H
