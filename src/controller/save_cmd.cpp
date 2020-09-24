//
// Created by y on 9/15/20.
//
#include "save_cmd.h"
#include "parser.h"
#include "auxiliary_functions.h"
#include "../view/file_writer.h"


bool SaveCmd::isValid(const Parser &cmd) {
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }
    if(cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }
    if(cmd.getParams().size() == 2){
        if(cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

size_t SaveCmd::getIdDna(StructureDna &structure, const std::string& cmd, const IOCallback<UI>& ioCallback){

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

void SaveCmd::run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback){
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }
    std::string fileName, name = structure.findDna(id).getName();
    cmd.getParams().size() == 2 ? fileName = cmd.getParams()[1].substr(1) : fileName = name;
    FileWriter fileWriter("../model/raw_dna_files/" + fileName + ".rawdna");
    fileWriter.write(structure.findDna(id).getDnaSeq()->getDna());
}

void SaveCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}

