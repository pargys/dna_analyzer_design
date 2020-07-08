//
// Created by y on 7/5/20.
//
#include "structure_dna.h"

void StructureDna::add(MetaDataDna* dna){
    m_idStructure.insert(std::pair<IdDna, MetaDataDna*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<NameDna, MetaDataDna*>(dna->getName(), dna));
}

MetaDataDna &StructureDna::find(const IdDna& id){
    return *(m_idStructure.find(id)->second);
}

MetaDataDna &StructureDna::find(const NameDna& name){
    return *(m_nameStructure.find(name)->second);
}

bool StructureDna::isExist(const IdDna& id) const{
    return m_idStructure.find(id) != m_idStructure.end();
}

bool StructureDna::isExist(const NameDna& name) const{
    return m_nameStructure.find(name) != m_nameStructure.end();
}

