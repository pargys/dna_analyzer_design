//
// Created by y on 7/5/20.
//

#include "parser.h"
#include "new_cmd.h"
#include "structure_dna.h"
#include "iwriter.h"
#include "auxiliary_functions.h"

NewCmd::NewCmd(const Parser& cmd){
    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

bool NewCmd::isValid(const Parser &cmd) {
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }
    if(cmd.getParams().size() == 2){
        if(cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

void NewCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output) {
    static size_t countDna;
    std::string dnaName;
    if(cmd.getParams().size() == 1){
        dnaName = "seq" + numToString(++countDna);
        while(structure.isExist(dnaName)){
            dnaName = "seq" + numToString(++countDna);
        }

    } else {
        dnaName = cmd.getParams()[1].substr(1);
        if(structure.isExist(dnaName)){
            output.write("name is already exist! please enter again\n");
            return;
        }
    }
    MetaDataDna *data = new MetaDataDna(cmd.getParams()[0], dnaName, (std::string) "new");
    structure.add(data);
    print(structure, output);
}


void NewCmd::print(StructureDna& structure, IWriter& output){
    std::string id = numToString(structure.find(MetaDataDna::getId()).getId().getId());
    output.write("[" + id + "]" + " " + structure.find(MetaDataDna::getId()).getName().getName() + ": " + structure.find(MetaDataDna::getId()).getDnaSeq().getDna() + "\n");
}


