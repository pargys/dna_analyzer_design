//
// Created by y on 9/16/20.
//

#include "find_cmd.h"
#include "parser.h"
#include "../model/structure_dna.h"
#include "../view/iwriter.h"
#include "auxiliary_functions.h"

bool FindCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() != 2){
        return false;
    }

    if (cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@') {
        return false;
    }
    return true;
}

void FindCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}

size_t FindCmd::getIdDna(StructureDna &structure, const std::string &cmd, const IOCallback<UI>& ioCallback){

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

void FindCmd::run(const Parser &cmd, StructureDna &structure, const IOCallback<UI>& ioCallback) {
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }
    std::string subSeq;
    bool isExistSub = cmd.getParams()[1][0] == '@' or cmd.getParams()[1][0] == '#';

    if (isExistSub){
        size_t subSeqId = getIdDna(structure, cmd.getParams()[1], ioCallback);
        subSeq = structure.findDna(subSeqId).getDnaSeq()->getDna();
    }

    else {
        subSeq = cmd.getParams()[1];
    }
    DnaSequence seq =  *(structure.findDna(id).getDnaSeq());
    size_t index = seq.find(subSeq);

    if (index == seq.length()) {
        ioCallback.runWrite(subSeq + " is not sub seq of " + seq.getDna());
    }

    else{
        print(index, ioCallback);
    }
}

void FindCmd::print(size_t index, const IOCallback<UI>& ioCallback){
    ioCallback.runWrite(numToString(index) + "\n");
}
