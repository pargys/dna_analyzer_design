//
// Created by y on 7/6/20.
//

#ifndef SRC_LOAD_CMD_H
#define SRC_LOAD_CMD_H

#include "creation_cmds.h"

class LoadCmd: public CreationCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    /*virtual*/~LoadCmd(){}

private:
    bool isValid(const Parser& cmd);
    void print(StructureDna& structure, const IOCallback<UI>& ioCallback);
};

#endif //SRC_LOAD_CMD_H
