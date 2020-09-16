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
    MetaDataDna& findDna(size_t id);
    MetaDataDna& findDna(const std::string& name);
    bool isExist(size_t id) const;
    bool isExist(const std::string& name) const;
    void eraseDna(size_t id);
    std::map<size_t, MetaDataDna*> getIdMap() {return m_idStructure;}
    std::map<std::string, MetaDataDna*> getNameMap() {return m_nameStructure;}
    void renameDna(const std::string& name, const std::string& newName);

private:
    std::map<size_t, MetaDataDna*> m_idStructure;
    std::map<std::string, MetaDataDna*> m_nameStructure;
};

#endif //SRC_STRUCTURE_DNA_H
