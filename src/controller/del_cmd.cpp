//
// Created by y on 9/15/20.
//

#include "del_cmd.h"
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

size_t DelCmd::getIdDna(StructureDna& structure, const std::string& cmd, const IOCallback<UI>& ioCallback){

    if (cmd[0] == '@'){
        std::string name = cmd.substr(1);

        if (!structure.isExist(name)){
            ioCallback.runWrite("name is not exist. please enter again\n");
            return 0;
        }
        return structure.findDna(name).getId();
    }
    else {
        size_t id = stringToNum(cmd.substr(1));

        if (!structure.isExist(id)){
            ioCallback.runWrite("id is not exist. please enter again\n");
            return 0;
        }
        return id;
    }
}

void DelCmd::run(const Parser& cmd, StructureDna& structure, const IOCallback<UI>& ioCallback){
    size_t id = getIdDna(structure, cmd.getParams()[0], ioCallback);

    if (!id){
        return;
    }
    std::string name = structure.findDna(id).getName();
    std::string dnaSeq = structure.findDna(id).getDnaSeq()->getDna();
    bool isConfirm = isConfirmed(name, dnaSeq, ioCallback);
    if (isConfirm){
        structure.eraseDna(id);
    }
    print(id, name, dnaSeq, ioCallback, isConfirm);
}

bool DelCmd::isConfirmed(std::string name, std::string dnaSeq, const IOCallback<UI>& ioCallback) {
    ioCallback.runWrite("Do you really want to delete " + name + ":" + dnaSeq + "?\n");
    ioCallback.runWrite("Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n");
    ioCallback.runWrite("> confirm >>> ");
    std::string confirm = ioCallback.runRead();
    while (confirm != "Y" and confirm != "y" and confirm != "N" and confirm != "n"){
        ioCallback.runWrite("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n");
        ioCallback.runWrite("> confirm >>>");
        confirm = ioCallback.runRead();
    }

    return confirm == "Y" || confirm == "y";
}

void DelCmd::print(size_t id, std::string name, std::string dnaSeq, const IOCallback<UI>& ioCallback, bool isDeleted) {

    if (isDeleted){
        ioCallback.runWrite("Deleted:[" + numToString(id) + "] " + name + ": " + dnaSeq + "\n");
    }
    else{
        ioCallback.runWrite("Deletion canceled\n");
    }
}

void DelCmd::createCmd(const Parser &cmd) {

    if(!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments");
    }
}


