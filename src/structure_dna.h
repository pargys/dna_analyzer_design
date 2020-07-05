//
// Created by y on 7/5/20.
//

#ifndef SRC_STRUCTURE_DNA_H
#define SRC_STRUCTURE_DNA_H
#include <map>
#include "id_dna.h"
#include "name_dna.h"
#include "status_dna.h"
#include "meta_data_dna.h"

class StructureDna{
public:
    static std::map<IdDna, MetaDataDna>& getIdStructure();
    static std::map<NameDna, MetaDataDna*>& getNameStructure();
    static std::map<StatusDna, MetaDataDna*>& getStatusStructure();
};

#endif //SRC_STRUCTURE_DNA_H
