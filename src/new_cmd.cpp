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
    StructureDna::getNameStructure().insert(std::pair<NameDna, MetaDataDna*>(dnaName, data));
}

void NewCmd::print(IWriter* writer){
    std::stringstream idString;
    idString<< StructureDna::getIdStructure()[MetaDataDna::getId()]->getId().getId();
    std::string s = "[" + idString.str() + "]" + " " + StructureDna::getIdStructure()[MetaDataDna::getId()]->getName().getName() + ": " + StructureDna::getIdStructure()[MetaDataDna::getId()]->getDnaSeq().getDna() + "\n";
    writer->write(s);
}
