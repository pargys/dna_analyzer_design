//
// Created by y on 7/6/20.
//

#include <sstream>
#include "parser.h"
#include "load_cmd.h"
#include "structure_dna.h"
#include "file_reader.h"
#include "iwriter.h"
#include "meta_data_dna.h"

LoadCmd::LoadCmd(const Parser& cmd){
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void LoadCmd::run(const Parser &cmd, StructureDna& structure, IWriter& output){
    FileReader file(cmd.getParams()[0].c_str());
    file.read();
    std::string dnaName;
    if(cmd.getParams().size() == 1){
        dnaName = cmd.getParams()[0];
    }
    else{
        dnaName = cmd.getParams()[1];
    }
    if(structure.isExist(dnaName)){
        MetaDataDna temp(structure.find(dnaName));
        std::stringstream counterString;
        counterString<< temp.getCounter();
        dnaName = dnaName + "_" + counterString.str();
        temp.increaseCounter();
    }
    MetaDataDna* data = new MetaDataDna(file, dnaName, (std::string)"new");
    structure.add(data);
    print(structure, output);
}

void LoadCmd::print(StructureDna& structure, IWriter& writer){
    std::string dna = structure.find(MetaDataDna::getId()).getDnaSeq().getDna();
    size_t n = dna.length();
    if(n > 40){
        dna = dna.substr(0, 31) + "..." + dna.substr(n-3, n-1);
    }
    std::stringstream idString;
    idString<< structure.find(MetaDataDna::getId()).getId().getId();
    writer.write("[" + idString.str() + "]" + " " + structure.find(MetaDataDna::getId()).getName().getName() + ": " + dna + "\n");
}