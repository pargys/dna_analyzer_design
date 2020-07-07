//
// Created by y on 7/5/20.
//

#include "parser.h"
#include "new_cmd.h"
#include "structure_dna.h"
#include <sstream>
#include "iwriter.h"

NewCmd::NewCmd(const Parser& cmd){
    if(cmd.getParams().size() < 1 || cmd.getParams().size() > 2){
        throw std::invalid_argument("invalid nums of arguments!");
    }
}

void NewCmd::run(const Parser& cmd, StructureDna& structure, IWriter& output) {
    std::string dnaName;
    std::stringstream ss;
    if (cmd.getParams().size() == 1) {
        ss << "seq" << ++countDna;
        dnaName = ss.str();
    } else {
        dnaName = cmd.getParams()[1];
    }
    MetaDataDna *data = new MetaDataDna(cmd.getParams()[0], dnaName, (std::string) "new");
    structure.add(data);
    print(structure, output);
}


void NewCmd::print(StructureDna& structure, IWriter& output){
    std::stringstream idString;
    idString<< structure.getIdStructure()[MetaDataDna::getId()]->getId().getId();
    output.write("[" + idString.str() + "]" + " " + structure.getIdStructure()[MetaDataDna::getId()]->getName().getName() + ": " + structure.getIdStructure()[MetaDataDna::getId()]->getDnaSeq().getDna() + "\n");
}