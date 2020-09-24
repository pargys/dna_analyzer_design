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
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    /*virtual*/~LenCmd(){}

private:
    bool isValid(const Parser& cmd);
    void print(size_t len, const IOCallback<UI>& ioCallback);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, const IOCallback<UI>& ioCallback);
};

#endif //SRC_LEN_CMD_H
