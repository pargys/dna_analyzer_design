//
// Created by y on 7/5/20.
//

#ifndef SRC_META_DATA_DNA_H
#define SRC_META_DATA_DNA_H
#include "dna_sequence.h"
#include "name_dna.h"
#include "id_dna.h"
#include "status_dna.h"
#include "id_dna.h"
class MetaDataDna{
public:
    MetaDataDna(const DnaSequence& dna, const NameDna& name, const StatusDna& status): m_dna(dna), m_name(name), m_status(status){}
    IdDna static getId(){return ++s_id;}

private:
    DnaSequence m_dna;
    NameDna m_name;
    StatusDna m_status;
    static IdDna s_id;
};

#endif //SRC_META_DATA_DNA_H
