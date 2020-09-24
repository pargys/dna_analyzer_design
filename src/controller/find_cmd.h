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
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    /*virtual*/~FindCmd(){}

private:
    bool isValid(const Parser& cmd);
    size_t getIdDna(StructureDna& structure, const std::string& cmd, const IOCallback<UI>& ioCallback);
    void print(size_t index, const IOCallback<UI>& ioCallback);
};


#endif //SRC_FIND_CMD_H
