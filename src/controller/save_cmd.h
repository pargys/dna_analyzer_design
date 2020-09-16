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
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
    /*virtual*/~SaveCmd(){}

private:
    bool isValid(const Parser& cmd);
};

#endif //SRC_SAVE_CMD_H
