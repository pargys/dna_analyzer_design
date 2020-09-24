//
// Created by y on 9/15/20.
//

#ifndef SRC_SAVE_CMD_H
#define SRC_SAVE_CMD_H

#include "management_cmds.h"
#include <string>

class SaveCmd: public ManagementCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, const IOCallback<UI>& ioCallback);
    /*virtual*/~SaveCmd(){}

private:
    bool isValid(const Parser& cmd);
};

#endif //SRC_SAVE_CMD_H
