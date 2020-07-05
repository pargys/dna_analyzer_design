//
// Created by y on 7/5/20.
//

#include "new_cmd.h"
#include "structure_dna.h"
#include <sstream>
NewCmd::NewCmd(const Parser& cmd){
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void NewCmd::run(const Parser& cmd){
    static size_t countDna = 0;
    std::string dnaName;
    std::stringstream ss;
    if(cmd.getParams().size() == 1){
        ss<< "seq"<< ++countDna;
        dnaName = ss.str();
    }
    else{
        dnaName = cmd.getParams()[1];
    }
    MetaDataDna* data = new MetaDataDna(cmd.getParams()[0], dnaName, (std::string)"new");
    StructureDna::getIdStructure().insert(std::pair<IdDna, MetaDataDna*> (MetaDataDna::getId(), data));
}

