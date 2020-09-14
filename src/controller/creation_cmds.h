//
// Created by y on 7/5/20.
//

#ifndef SRC_CREATION_CMDS_H
#define SRC_CREATION_CMDS_H

#include <cstdio>
#include "i_command.h"

class CreationCmds: public ICommand{
public:
    /*virtual*/ void createCmd(const Parser& cmd) = 0;
    /*virtual*/ void run(const Parser& cmd, StructureDna& structure, IWriter& output) = 0;
    /*virtual*/~CreationCmds() = 0;
};

#endif //SRC_CREATION_CMDS_H
