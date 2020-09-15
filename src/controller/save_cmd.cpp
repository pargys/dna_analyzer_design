//
// Created by y on 9/15/20.
//
#include "save_cmd.h"
#include "../model/structure_dna.h"
#include "parser.h"
#include "auxiliary_functions.h"
#include "../view/iwriter.h"
#include "../view/file_writer.h"


bool SaveCmd::isValid(const Parser &cmd) {
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


void SaveCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input){
    size_t id;
    std::string name, fileName;
    if (cmd.getParams()[0][0] == '@'){
        name = cmd.getParams()[0].substr(1);

        if (!structure.isExist(name)){
            output.write("name is not exist! please enter again\n");
            return;
        }
        id = structure.findDna(name).getId();
    }
    else {
        id = stringToNum(cmd.getParams()[0].substr(1));

        if (!structure.isExist(id)){
            output.write("id is not exist! please enter again\n");
            return;
        }
        name = structure.findDna(id).getName();
    }
    cmd.getParams().size() == 2 ? fileName = cmd.getParams()[1].substr(1) : fileName = name;
    FileWriter fileWriter("../model/raw_dna_files/" + fileName + ".rawdna");
    fileWriter.write(structure.findDna(id).getDnaSeq()->getDna());
}

void SaveCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}
