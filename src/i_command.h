//
// Created by y on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H
#include <vector>
#include <string>
#include "parser.h"
#include "iwriter.h"

class ICommand{
public:
    virtual void run(const Parser& cmd) = 0;
    virtual void print(IWriter* writer) = 0;
};

#endif //SRC_I_COMMAND_H
