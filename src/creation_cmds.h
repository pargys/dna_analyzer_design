//
// Created by y on 7/5/20.
//

#ifndef SRC_CREATION_CMDS_H
#define SRC_CREATION_CMDS_H
#include "i_command.h"
#include "parser.h"

class CreationCmds: public ICommand{
    /*virtual*/ void run(const Parser& cmd) = 0;
};

#endif //SRC_CREATION_CMDS_H
