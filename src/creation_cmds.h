//
// Created by y on 7/5/20.
//

#ifndef SRC_CREATION_CMDS_H
#define SRC_CREATION_CMDS_H
#include "i_command.h"
#include "parser.h"

class CreationCmds: public ICommand{
public:
    /*virtual*/ void run(const Parser& cmd) = 0;
    /*virtual*/ void print(IWriter* writer) = 0;
    static size_t countDna;
};

#endif //SRC_CREATION_CMDS_H
