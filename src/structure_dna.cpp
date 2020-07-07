//
// Created by y on 7/5/20.
//
#include "structure_dna.h"

void StructureDna::add(MetaDataDna* dna){
    m_idStructure.insert(std::pair<IdDna, MetaDataDna*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<NameDna, MetaDataDna*>(dna->getName(), dna));
}

