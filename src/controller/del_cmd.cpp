//
// Created by y on 9/15/20.
//

#include "del_cmd.h"
#include "../model/structure_dna.h"
#include "../view/iwriter.h"
#include "parser.h"
#include "auxiliary_functions.h"


bool DelCmd::isValid(const Parser &cmd){

    if(cmd.getParams().size() != 1){
        return false;
    }

    if(cmd.getParams()[0][0] != '#' && cmd.getParams()[0][0] != '@'){
        return false;
    }
    return true;
}

size_t DelCmd::getIdDna(StructureDna& structure, const std::string& cmd, IWriter& output){

    if (cmd[0] == '@'){
        std::string name = cmd.substr(1);

        if (!structure.isExist(name)){
            output.write("name is not exist. please enter again\n");
            return 0;
        }
        return structure.findDna(name).getId();
    }
    else {
        size_t id = stringToNum(cmd.substr(1));

        if (!structure.isExist(id)){
            output.write("id is not exist. please enter again\n");
            return 0;
        }
        return id;
    }
}

void DelCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output, IReader& input){
    size_t id = getIdDna(structure, cmd.getParams()[0], output);

    if (!id){
        return;
    }
    std::string name = structure.findDna(id).getName();
    std::string dnaSeq = structure.findDna(id).getDnaSeq()->getDna();
    bool isConfirm = isConfirmed(name, dnaSeq, output, input);
    if (isConfirm){
        structure.eraseDna(id);
    }
    print(id, name, dnaSeq, output, isConfirm);
}

bool DelCmd::isConfirmed(std::string name, std::string dnaSeq, IWriter& output, IReader& input) {
    output.write("Do you really want to delete " + name + ":" + dnaSeq + "?");
    output.write("Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");
    output.write("> confirm >>>");
    input.read();
    std::string confirm = input.getStr();
    while (confirm != "Y" and confirm != "y" and confirm != "N" and confirm != "n"){
        output.write("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.");
        output.write("> confirm >>>");
        input.read();
        confirm = input.getStr();
    }

    return confirm == "Y" || confirm == "y";
}

void DelCmd::print(size_t id, std::string name, std::string dnaSeq, IWriter &output, bool isDeleted) {

    if (isDeleted){
        output.write("Deleted:[" + numToString(id) + "] " + name + ": " + dnaSeq);
    }
    else{
        output.write("Deletion canceled");
    }
}

void DelCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}


