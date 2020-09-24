//
// Created by y on 9/16/20.
//

#include "rename_cmd.h"
#include "parser.h"
#include "auxiliary_functions.h"


bool RenameCmd::isValid(const Parser &cmd){

    if(cmd.getParams().size() != 2){
        return false;
    }

    if(cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }
    return true;
}

void RenameCmd::run(const Parser &cmd, StructureDna &structure, const IOCallback<UI>& ioCallback) {
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }
    std::string name = structure.findDna(id).getName();
    std::string newName = cmd.getParams()[1];

    if (name != newName){
        structure.renameDna(name, newName);
    }
}

void RenameCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}

size_t RenameCmd::getIdDna(StructureDna &structure, const std::string &cmd, const IOCallback<UI>& ioCallback) {

    if (cmd[0] == '@'){
        std::string name = cmd.substr(1);

        if (!structure.isExist(name)){
            ioCallback.runWrite("name is not exist. please enter again\n");
            return 0;
        }
        return structure.findDna(name).getId();
    }
    else {
        size_t id = stringToNum(cmd.substr(1));

        if (!structure.isExist(id)){
            ioCallback.runWrite("id is not exist. please enter again\n");
            return 0;
        }
        return id;
    }
}

