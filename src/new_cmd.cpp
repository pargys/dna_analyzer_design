//
// Created by y on 7/5/20.
//

#include "parser.h"
#include "new_cmd.h"
#include "structure_dna.h"
#include <sstream>
#include "iwriter.h"

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
    std::string dnaName;
    std::stringstream ss;
    if (cmd.getParams().size() == 1) {
        ss << "seq" << ++countDna;
        dnaName = ss.str();
    } else {
        dnaName = cmd.getParams()[1];
    }
    if(structure.isExist(dnaName)){
        std::stringstream counterString;
        structure.find(dnaName).increaseCounter();
        counterString<< structure.find(dnaName).getCounter();
        dnaName = dnaName + "_" + counterString.str();
    }
    MetaDataDna *data = new MetaDataDna(cmd.getParams()[0], dnaName, (std::string) "new");
    structure.add(data);
    print(structure, output);
}


void NewCmd::print(StructureDna& structure, IWriter& output){
    std::stringstream idString;
    idString<< structure.find(MetaDataDna::getId()).getId().getId();
    output.write("[" + idString.str() + "]" + " " + structure.find(MetaDataDna::getId()).getName().getName() + ": " + structure.find(MetaDataDna::getId()).getDnaSeq().getDna() + "\n");
}


