//
// Created by y on 9/16/20.
//

#ifndef SRC_FIND_CMD_H
#define SRC_FIND_CMD_H

#include "analysis_cmds.h"
#include <string>

class FindCmd: public AnalysisCmds{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input);
    /*virtual*/~FindCmd(){}

private:
    bool isValid(const Parser& cmd);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output);
    void print(size_t index, IWriter &output);
};


#endif //SRC_FIND_CMD_H
