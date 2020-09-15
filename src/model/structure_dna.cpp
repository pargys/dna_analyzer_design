//
// Created by y on 7/5/20.
//
#include "structure_dna.h"

void StructureDna::add(MetaDataDna* dna){
    m_idStructure.insert(std::pair<size_t , MetaDataDna*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<std::string, MetaDataDna*>(dna->getName(), dna));
}

MetaDataDna &StructureDna::findDna(size_t id){
    return *(m_idStructure.find(id)->second);
}

MetaDataDna &StructureDna::findDna(const std::string& name){
    return *(m_nameStructure.find(name)->second);
}

bool StructureDna::isExist(size_t id) const{
    return m_idStructure.find(id) != m_idStructure.end();
}

bool StructureDna::isExist(const std::string& name) const{
    return m_nameStructure.find(name) != m_nameStructure.end();
}

