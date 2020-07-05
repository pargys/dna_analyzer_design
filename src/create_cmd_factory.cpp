//
// Created by y on 7/5/20.
//

#include "create_cmd_factory.h"
#include "new_cmd.h"

ICommand* CreateCmdFactory::create(const std::string &cmdName){
    if(cmdName == "new"){
        return new NewCmd;
    }
    return NULL;
}

