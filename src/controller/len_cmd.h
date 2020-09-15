//
// Created by y on 9/15/20.
//

#ifndef SRC_LEN_CMD_H
#define SRC_LEN_CMD_H

#include "creation_cmds.h"

class LenCmd: public CreationCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output);
    /*virtual*/~LenCmd(){}

private:
    bool isValid(const Parser& cmd);
    void print(size_t len, IWriter& output);
};

#endif //SRC_LEN_CMD_H
