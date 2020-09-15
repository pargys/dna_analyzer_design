//
// Created by y on 9/15/20.
//

#include "len_cmd.h"
#include "parser.h"
#include "../model/structure_dna.h"
#include "../view/iwriter.h"
#include "auxiliary_functions.h"


bool LenCmd::isValid(const Parser &cmd) {

    if (cmd.getParams().size() != 1){
        return false;
    }

    if (cmd.getParams()[0][0] != '#') {
        return false;
    }
    return true;
}

void LenCmd::run(const Parser &cmd, StructureDna& structure, IWriter& output, IReader& input){
    size_t id = stringToNum(cmd.getParams()[0].substr(1));

    if (!structure.isExist(id)){
        output.write("id is not exist! please enter again\n");
        return;
    }
    size_t len = structure.findDna(id).getDnaSeq()->length();
    print(len, output);
}

void LenCmd::createCmd(const Parser &cmd) {

    if (!isValid(cmd)){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void LenCmd::print(size_t len, IWriter &output) {
    output.write(numToString(len));
}
