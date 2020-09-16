//
// Created by y on 9/15/20.
//

#ifndef SRC_LEN_CMD_H
#define SRC_LEN_CMD_H

#include "analysis_cmds.h"
#include <string>

class LenCmd: public AnalysisCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    /*virtual*/~LenCmd(){}

private:
    bool isValid(const Parser& cmd);
    void print(size_t len, IWriter& output);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
};

#endif //SRC_LEN_CMD_H
