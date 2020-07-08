//
// Created by y on 7/5/20.
//

#ifndef SRC_STRUCTURE_DNA_H
#define SRC_STRUCTURE_DNA_H

#include <map>
#include "meta_data_dna.h"

class IdDna;
class NameDna;

class StructureDna{
public:
    void add(MetaDataDna* dna);
    MetaDataDna& find(const IdDna& id);
    MetaDataDna& find(const NameDna& name);
    bool isExist(const IdDna& id) const;
    bool isExist(const NameDna& name) const;

private:
    std::map<IdDna, MetaDataDna*> m_idStructure;
    std::map<NameDna, MetaDataDna*> m_nameStructure;
};

#endif //SRC_STRUCTURE_DNA_H
