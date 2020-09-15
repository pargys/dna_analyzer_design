//
// Created by y on 9/15/20.
//

#ifndef SRC_SAVE_CMD_H
#define SRC_SAVE_CMD_H

#include "creation_cmds.h"

class SaveCmd: public CreationCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output);
    /*virtual*/~SaveCmd(){}

private:
    bool isValid(const Parser& cmd);
};

#endif //SRC_SAVE_CMD_H
