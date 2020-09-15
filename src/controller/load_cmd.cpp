//
// Created by y on 7/6/20.
//

#include "parser.h"
#include "load_cmd.h"
#include "../model/structure_dna.h"
#include "../view/file_reader.h"
#include "../view/iwriter.h"
#include "auxiliary_functions.h"


bool LoadCmd::isValid(const Parser &cmd) {

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

void LoadCmd::run(const Parser &cmd, StructureDna& structure, IWriter& output, IReader& input){
    std::string dnaName, fileName = cmd.getParams()[0];
    FileReader file(fileName.c_str());
    file.read();
    fileName = file.getFileName();

    if (cmd.getParams().size() == 1){
        dnaName = fileName;

        while (structure.isExist(dnaName)){
            structure.findDna(dnaName).increaseCounter();
            dnaName = fileName + "_" + numToString(structure.findDna(dnaName).getCounter());
        }
    }
    else {
        dnaName = cmd.getParams()[1].substr(1);

        if (structure.isExist(dnaName)){
            output.write("name is already exist! please enter again\n");
            return;
        }
    }

    MetaDataDna* data = new MetaDataDna(file, dnaName, (std::string)"new");
    structure.add(data);
    print(structure, output);
}

void LoadCmd::print(StructureDna& structure, IWriter& writer){
    MetaDataDna metaData(structure.findDna(MetaDataDna::getId()));
    std::string dna = metaData.getDnaSeq()->getDna();
    size_t n = dna.length();

    if (n > 40){
        dna = dna.substr(0, 31) + "..." + dna.substr(n-3, n-1);
    }
    std::string id = numToString(metaData.getId());
    writer.write("[" + id + "]" + " " + metaData.getName() + ": " + dna + "\n");
}

void LoadCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}
