//
// Created by y on 7/5/20.
//

#include "parser.h"
#include "new_cmd.h"
#include "auxiliary_functions.h"

bool NewCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }

    if (cmd.getParams().size() == 2){

        if (cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

void NewCmd::run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback) {
    static size_t countDna;
    std::string dnaName;

    if (cmd.getParams().size() == 1){
        dnaName = "seq" + numToString(++countDna);

        while (structure.isExist(dnaName)){
            dnaName = "seq" + numToString(++countDna);
        }

    } else {
        dnaName = cmd.getParams()[1].substr(1);

        if (structure.isExist(dnaName)){
            ioCallback.runWrite("name is already exist. please enter again\n");

            return;
        }
    }
    MetaDataDna *data = new MetaDataDna(cmd.getParams()[0], dnaName, (std::string) "new");
    structure.add(data);
    print(structure, ioCallback);
}


void NewCmd::print(StructureDna& structure, const IOCallback<UI>& ioCallback){
    MetaDataDna metaData(structure.findDna(MetaDataDna::getLastId()));
    std::string id = numToString(metaData.getId());

    ioCallback.runWrite("[" + id + "]" + " " + metaData.getName() + ": " + metaData.getDnaSeq()->getDna() + "\n");
}

void NewCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}



