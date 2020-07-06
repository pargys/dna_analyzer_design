//
// Created by y on 7/5/20.
//
#include "name_dna.h"
#include "string.h"
bool operator<(const NameDna& name1, const NameDna& name2){
    return strcmp(name1.getName().c_str(), name2.getName().c_str());
}