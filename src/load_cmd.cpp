//
// Created by y on 7/6/20.
//

#include "parser.h"
#include "load_cmd.h"
#include "structure_dna.h"
#include "file_reader.h"
#include "iwriter.h"
#include "meta_data_dna.h"
#include "auxiliary_functions.h"

LoadCmd::LoadCmd(const Parser& cmd){
    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

bool LoadCmd::isValid(const Parser &cmd) {
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

void LoadCmd::run(const Parser &cmd, StructureDna& structure, IWriter& output){
    FileReader file(cmd.getParams()[0].c_str());
    file.read();
    std::string dnaName, fileName = cmd.getParams()[0];
    if(cmd.getParams().size() == 1){
        structure.find(fileName).increaseCounter();
        dnaName = fileName;
        while(structure.isExist(dnaName)){
            structure.find(dnaName).increaseCounter();
            dnaName = fileName + "_" + numToString(structure.find(dnaName).getCounter());
        }
    }
    else{
        dnaName = cmd.getParams()[1].substr(1);
        if(structure.isExist(dnaName)){
            output.write("name is already exist! please enter again\n");
            return;
        }
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
    std::string id = numToString(structure.find(MetaDataDna::getId()).getId().getId());
    writer.write("[" + id + "]" + " " + structure.find(MetaDataDna::getId()).getName().getName() + ": " + dna + "\n");
}