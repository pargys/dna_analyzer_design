//
// Created by y on 9/22/20.
//

#ifndef SRC_ENTER_CMD_H
#define SRC_ENTER_CMD_H

#include "i_command.h"

class EnterCmd: public ICommand{
public:
    /*virtual*/void createCmd(const Parser& cmd);
    /*virtual*/void run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback);
    /*virtual*/~EnterCmd() {}
};


#endif //SRC_ENTER_CMD_H
