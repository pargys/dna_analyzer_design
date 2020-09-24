//
// Created by y on 7/6/20.
//
#include "dup_cmd.h"
#include "parser.h"
#include "auxiliary_functions.h"

bool DupCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }

    if (cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }

    if (cmd.getParams().size() == 2){

        if (cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}


size_t DupCmd::getIdDna(StructureDna &structure, const std::string &cmd, const IOCallback<UI>& ioCallback){

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

std::string DupCmd::getNewName(StructureDna& structure, size_t id, std::string name){
    structure.findDna(id).increaseCounter();
    std::string dnaName = name + "_" + numToString(structure.findDna(id).getCounter());

    while (structure.isExist(dnaName)){
        structure.findDna(dnaName).increaseCounter();
        dnaName = name + "_" + numToString(structure.findDna(dnaName).getCounter());
    }
    return dnaName;
}

void DupCmd::run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback) {
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }
    std::string dnaName, name = structure.findDna(id).getName();

    if (cmd.getParams().size() == 1){
        dnaName = getNewName(structure, id, name);
    }
    else {
        dnaName = cmd.getParams()[1].substr(1);

        if (structure.isExist(dnaName)){
            ioCallback.runWrite("name is exist. please enter again\n");
            return;
        }
    }
    std::string dna = structure.findDna(id).getDnaSeq()->getDna();
    MetaDataDna* data = new MetaDataDna(dna, dnaName, (std::string)"new");
    structure.add(data);
    print(structure, ioCallback);
}

void DupCmd::print(StructureDna &structure, const IOCallback<UI>& ioCallback){
    MetaDataDna metaData(structure.findDna(MetaDataDna::getLastId()));
    std::string id = numToString(metaData.getId());
    ioCallback.runWrite("[" + id + "]" + " " + metaData.getName() + ": " + metaData.getDnaSeq()->getDna() + "\n");
}

void DupCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}


