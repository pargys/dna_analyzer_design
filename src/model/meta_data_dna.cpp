//
// Created by y on 7/5/20.
//

#include "meta_data_dna.h"

size_t MetaDataDna::s_last_id = 1;

MetaDataDna::MetaDataDna(const MetaDataDna& other){
    m_id = other.m_id;
    m_dna = new DnaSequence(*(other.m_dna));
    m_name = other.m_name;
    m_status = other.m_status;
    m_counter = 0;
}

void MetaDataDna::setName(const std::string &newName) {
    m_name = newName;
}
