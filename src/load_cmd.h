//
// Created by y on 7/6/20.
//

#ifndef SRC_LOAD_CMD_H
#define SRC_LOAD_CMD_H
#include "creation_cmds.h"

class LoadCmd{
    LoadCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd);
    /*virtual*/void print(IWriter* writer);
};

#endif //SRC_LOAD_CMD_H
