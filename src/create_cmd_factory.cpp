//
// Created by y on 7/5/20.
//

#include "create_cmd_factory.h"
#include "new_cmd.h"
#include "load_cmd.h"

ICommand* CreateCmdFactory::create(const Parser& cmd){
    if(cmd.getCmdName() == "new"){
        return new NewCmd(cmd);
    }
    if(cmd.getCmdName() == "load"){
        return new LoadCmd(cmd);
    }
    return NULL;
}

