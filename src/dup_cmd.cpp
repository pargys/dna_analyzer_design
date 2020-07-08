//
// Created by y on 7/6/20.
//
#include "dup_cmd.h"
#include "structure_dna.h"
#include "parser.h"
#include "auxiliary_functions.h"
#include "iwriter.h"

DupCmd::DupCmd(const Parser &cmd){
    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

bool DupCmd::isValid(const Parser &cmd) {
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }
    if(cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }
    if(cmd.getParams().size() == 2){
        if(cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

void DupCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output){
    if(cmd.getParams()[0][0] == '#'){
        runForId(cmd, structure, output);
    }
    else if(cmd.getParams()[0][0] == '@'){
        runForName(cmd, structure, output);
    }
    print(structure, output);
}

void DupCmd::runForId(const Parser &cmd, StructureDna &structure, IWriter& output){
    size_t id = stringToNum(cmd.getParams()[0].substr(1));
    if(!structure.isExist(id)){
        output.write("id is not exist! please enter again\n");
        return;
    }
    std::string dnaName, name = structure.find(id).getName().getName();
    if(cmd.getParams().size() == 1){
        structure.find(id).increaseCounter();
        dnaName = name + "_" + numToString(structure.find(id).getCounter());
        while(structure.isExist(dnaName)){
            structure.find(dnaName).increaseCounter();
            dnaName = name + "_" + numToString(structure.find(dnaName).getCounter());
        }
    }
    else{
        dnaName = cmd.getParams()[1].substr(1);
        if(structure.isExist(dnaName)){
            output.write("name is exist! please enter again\n");
            return;
        }
    }
    std::string dna = structure.find(id).getDnaSeq().getDna();
    MetaDataDna* data = new MetaDataDna(dna, dnaName, (std::string)"new");
    structure.add(data);
}

void DupCmd::runForName(const Parser &cmd, StructureDna &structure, IWriter& output){
    std::string name = cmd.getParams()[0].substr(1);
    if(!structure.isExist(name)){
        output.write("name is not exist! please enter again\n");
        return;
    }
    std::string dnaName;
    if(cmd.getParams().size() == 1){
        structure.find(name).increaseCounter();
        dnaName = name + "_" + numToString(structure.find(name).getCounter());
        while(structure.isExist(dnaName)){
            structure.find(dnaName).increaseCounter();
            dnaName = name + "_" + numToString(structure.find(dnaName).getCounter());
        }
    }
    else{
        dnaName = cmd.getParams()[1].substr(1);
        if(structure.isExist(dnaName)){
            output.write("name is exist! please enter again\n");
            return;
        }
    }
    std::string dna = structure.find(name).getDnaSeq().getDna();
    MetaDataDna* data = new MetaDataDna(dna, dnaName, (std::string)"new");
    structure.add(data);
}

void DupCmd::print(StructureDna &structure, IWriter &output){
    std::string id = numToString(structure.find(MetaDataDna::getId()).getId().getId());
    output.write("[" + id + "]" + " " + structure.find(MetaDataDna::getId()).getName().getName() + ": " + structure.find(MetaDataDna::getId()).getDnaSeq().getDna() + "\n");
}
