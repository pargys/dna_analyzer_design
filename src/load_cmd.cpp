//
// Created by y on 7/6/20.
//

#include "load_cmd.h"
#include "structure_dna.h"
#include "file_reader.h"

LoadCmd::LoadCmd(const Parser& cmd){
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void LoadCmd::run(const Parser &cmd){
    FileReader file;
    file.read(cmd.getParams()[0]);
    std::string dnaName, dnaSeq=file.getStr();
    if(cmd.getParams().size() == 1){
        dnaName = cmd.getParams()[0];
    }
    else{
        dnaName = cmd.getParams()[1];
    }
    MetaDataDna* data = new MetaDataDna(dnaSeq, dnaName, (std::string)"new");
    StructureDna::getIdStructure().insert(std::pair<IdDna, MetaDataDna*> (MetaDataDna::getId(), data));
    StructureDna::getNameStructure().insert(std::pair<NameDna, MetaDataDna*>(dnaName, data));
}



