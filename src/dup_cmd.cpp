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

