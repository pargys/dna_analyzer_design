//
// Created by y on 7/5/20.
//

#ifndef SRC_NEW_CMD_H
#define SRC_NEW_CMD_H

#include "creation_cmds.h"

class NewCmd: public CreationCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    /*virtual*/~NewCmd(){}

private:
    bool isValid(const Parser& cmd);
    void print(StructureDna& structure, const IOCallback<UI>& ioCallback);
};

#endif //SRC_NEW_CMD_H
