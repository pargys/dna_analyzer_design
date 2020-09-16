//
// Created by y on 9/16/20.
//

#ifndef SRC_RENAME_CMD_H
#define SRC_RENAME_CMD_H

#include "management_cmds.h"
#include <string>

class RenameCmd: public ManagementCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    /*virtual*/~RenameCmd(){}

private:
    bool isValid(const Parser& cmd);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
};

#endif //SRC_RENAME_CMD_H
