//
// Created by y on 7/5/20.
//

#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H

class Parser;
class StructureDna;
class IWriter;

class ICommand{
public:
    virtual void createCmd(const Parser& cmd) = 0;
    virtual void run(const Parser& cmd, StructureDna& structure, IWriter& output) = 0;
    virtual ~ICommand() = 0;
};

#endif //SRC_I_COMMAND_H
