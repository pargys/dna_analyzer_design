//
// Created by y on 7/5/20.
//
#include "structure_dna.h"

std::map<IdDna, MetaDataDna*>& StructureDna::getIdStructure(){
    static std::map<IdDna, MetaDataDna*> idStructure;
    return  idStructure;
}

std::map<NameDna, MetaDataDna*>& StructureDna::getNameStructure(){
    static std::map<NameDna, MetaDataDna*> nameStructure;
    return nameStructure;
}

