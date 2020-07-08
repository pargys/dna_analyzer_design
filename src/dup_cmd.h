//
// Created by y on 7/6/20.
//

#ifndef SRC_DUP_CMD_H
#define SRC_DUP_CMD_H

#include "creation_cmds.h"
#include "creation_cmds.h"

class DupCmd: public CreationCmds{
public:
    DupCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output);

private:
    bool isValid(const Parser& cmd);
    void print(StructureDna& structure, IWriter& output);
    void runForId(const Parser& cmd, StructureDna& structure, IWriter& output);
    void runForName(const Parser& cmd, StructureDna& structure, IWriter& output);
};

#endif //SRC_DUP_CMD_H
