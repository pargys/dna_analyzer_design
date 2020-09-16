//
// Created by y on 9/16/20.
//

#include "rename_cmd.h"
#include "../model/structure_dna.h"
#include "../view/iwriter.h"
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

void RenameCmd::run(const Parser &cmd, StructureDna &structure, IWriter &output, IReader &input) {
    size_t id = getIdDna(structure, cmd.getParams()[0], output);

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
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

size_t RenameCmd::getIdDna(StructureDna &structure, const std::string &cmd, IWriter &output) {

    if (cmd[0] == '@'){
        std::string name = cmd.substr(1);

        if (!structure.isExist(name)){
            output.write("name is not exist. please enter again\n");
            return 0;
        }
        return structure.findDna(name).getId();
    }
    else {
        size_t id = stringToNum(cmd.substr(1));

        if (!structure.isExist(id)){
            output.write("id is not exist. please enter again\n");
            return 0;
        }
        return id;
    }
}

