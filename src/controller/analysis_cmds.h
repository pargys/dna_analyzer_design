//
// Created by y on 9/16/20.
//

#ifndef SRC_ANALYSIS_CMDS_H
#define SRC_ANALYSIS_CMDS_H

#include "i_command.h"
#include <cstdio>

class AnalysisCmds: public ICommand{
public:
    /*virtual*/ void createCmd(const Parser& cmd) = 0;
    /*virtual*/ void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback) = 0;
    /*virtual*/~AnalysisCmds() = 0;
};


#endif //SRC_ANALYSIS_CMDS_H
