//
// Created by y on 9/15/20.
//

#include "len_cmd.h"
#include "parser.h"
#include "../model/structure_dna.h"
#include "../view/iwriter.h"
#include "auxiliary_functions.h"


bool LenCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() != 1){
        return false;
    }

    if (cmd.getParams()[0][0] != '#') {
        return false;
    }
    return true;
}

void LenCmd::run(const Parser &cmd, StructureDna& structure, const IOCallback<UI>& ioCallback){
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }

    if (!structure.isExist(id)){
        ioCallback.runWrite("id is not exist. please enter again\n");
        return;
    }
    size_t len = structure.findDna(id).getDnaSeq()->length();
    print(len, ioCallback);
}

void LenCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}

void LenCmd::print(size_t len, const IOCallback<UI>& ioCallback) {
    ioCallback.runWrite(numToString(len) + "\n");
}

size_t LenCmd::getIdDna(StructureDna &structure, const std::string &cmd, const IOCallback<UI>& ioCallback){

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