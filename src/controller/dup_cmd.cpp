//
// Created by y on 7/6/20.
//
#include "dup_cmd.h"
#include "../model/structure_dna.h"
#include "parser.h"
#include "auxiliary_functions.h"
#include "../view/iwriter.h"


bool DupCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        return false;
    }

    if (cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }

    if (cmd.getParams().size() == 2){

        if (cmd.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

void DupCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input){

    if (cmd.getParams()[0][0] == '#'){
        runForId(cmd, structure, output);
    }

    else if (cmd.getParams()[0][0] == '@'){
        runForName(cmd, structure, output);
    }
}

void DupCmd::runForId(const Parser &cmd, StructureDna &structure, IWriter& output){
    size_t id = stringToNum(cmd.getParams()[0].substr(1));

    if (!structure.isExist(id)){
        output.write("id is not exist! please enter again\n");
        return;
    }
    std::string dnaName, name = structure.findDna(id).getName();

    if (cmd.getParams().size() == 1){
        structure.findDna(id).increaseCounter();
        dnaName = name + "_" + numToString(structure.findDna(id).getCounter());

        while (structure.isExist(dnaName)){
            structure.findDna(dnaName).increaseCounter();
            dnaName = name + "_" + numToString(structure.findDna(dnaName).getCounter());
        }
    }
    else {
        dnaName = cmd.getParams()[1].substr(1);

        if (structure.isExist(dnaName)){
            output.write("name is exist! please enter again\n");
            return;
        }
    }
    MetaDataDna metaData = structure.findDna(id);
    std::string dna = metaData.getDnaSeq()->getDna();
    MetaDataDna* data = new MetaDataDna(dna, dnaName, (std::string)"new");
    structure.add(data);
    print(structure, output);
}

void DupCmd::runForName(const Parser &cmd, StructureDna &structure, IWriter& output){
    std::string name = cmd.getParams()[0].substr(1);

    if (!structure.isExist(name)){
        output.write("name is not exist! please enter again\n");
        return;
    }
    std::string dnaName;

    if (cmd.getParams().size() == 1){
        structure.findDna(name).increaseCounter();
        dnaName = name + "_" + numToString(structure.findDna(name).getCounter());

        while (structure.isExist(dnaName)){
            structure.findDna(dnaName).increaseCounter();
            dnaName = name + "_" + numToString(structure.findDna(dnaName).getCounter());
        }
    }
    else {
        dnaName = cmd.getParams()[1].substr(1);
        if (structure.isExist(dnaName)){
            output.write("name is exist! please enter again\n");
            return;
        }
    }
    std::string dna = structure.findDna(name).getDnaSeq()->getDna();
    MetaDataDna* data = new MetaDataDna(dna, dnaName, (std::string)"new");
    structure.add(data);
    print(structure, output);
}

void DupCmd::print(StructureDna &structure, IWriter &output){
    MetaDataDna metaData(structure.findDna(MetaDataDna::getId()));
    std::string id = numToString(metaData.getId());
    output.write("[" + id + "]" + " " + metaData.getName() + ": " + metaData.getDnaSeq()->getDna() + "\n");
}

void DupCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}
