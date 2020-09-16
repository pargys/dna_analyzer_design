//
// Created by y on 9/15/20.
//

#ifndef SRC_DEL_CMD_H
#define SRC_DEL_CMD_H

#include "management_cmds.h"
#include <string>

class DelCmd: public ManagementCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    /*virtual*/~DelCmd(){}

private:
    bool isValid(const Parser& cmd);
    bool isConfirmed(std::string name, std::string dnaSeq, IWriter& output, IReader& input);
    void print(size_t id, std::string name, std::string dnaSeq, IWriter& output, bool isDeleted);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
};

#endif //SRC_DEL_CMD_H
