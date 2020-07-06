//
// Created by y on 7/6/20.
//

#include "load_cmd.h"
#include "structure_dna.h"
#include "file_reader.h"
#include <sstream>

LoadCmd::LoadCmd(const Parser& cmd){
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void LoadCmd::run(const Parser &cmd){
    FileReader file;
    file.read(cmd.getParams()[0]);
    std::string dnaName;
    if(cmd.getParams().size() == 1){
        dnaName = cmd.getParams()[0];
    }
    else{
        dnaName = cmd.getParams()[1];
    }
    MetaDataDna* data = new MetaDataDna(file, dnaName, (std::string)"new");
    StructureDna::getIdStructure().insert(std::pair<IdDna, MetaDataDna*> (MetaDataDna::getId(), data));
    StructureDna::getNameStructure().insert(std::pair<NameDna, MetaDataDna*>(dnaName, data));
}

void LoadCmd::print(IWriter *writer){
    std::stringstream idString;
    std::string nameDna = StructureDna::getIdStructure()[MetaDataDna::getId()]->getDnaSeq().getDna();
    size_t n = nameDna.length();
    if(n > 40){
        nameDna = nameDna.substr(0, 31) + "..." + nameDna.substr(n-3, n-1);
    }

    idString<< StructureDna::getIdStructure()[MetaDataDna::getId()]->getId().getId();
    writer->write("[" + idString.str() + "]" + " " + StructureDna::getIdStructure()[MetaDataDna::getId()]->getName().getName() + ": " + nameDna + "\n");
}



