//
// Created by y on 7/6/20.
//

#ifndef SRC_DUP_CMD_H
#define SRC_DUP_CMD_H

#include "creation_cmds.h"
#include <string>

class DupCmd: public CreationCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    /*virtual*/~DupCmd() {}

private:
    bool isValid(const Parser& cmd);
    void print(StructureDna& structure, IWriter& output);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
    std::string getNewName(StructureDna& structure, size_t id, std::string name);
};

#endif //SRC_DUP_CMD_H
