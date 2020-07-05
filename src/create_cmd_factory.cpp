//
// Created by y on 7/5/20.
//

#include "create_cmd_factory.h"
#include "new_cmd.h"

ICommand* CreateCmdFactory::create(const Parser& cmdName){
    if(cmdName.getCmdName() == "new"){
        return new NewCmd(cmdName);
    }
    return NULL;
}

