//
// Created by y on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H

#include "io_callback.h"
#include "../view/ui.h"

class Parser;
class StructureDna;
class IWriter;
class IReader;

class ICommand{
public:
    virtual void createCmd(const Parser& cmd) = 0;
    virtual void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback) = 0;
    virtual ~ICommand() = 0;
};

#endif //SRC_I_COMMAND_H
