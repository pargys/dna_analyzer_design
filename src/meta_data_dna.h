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
    MetaDataDna(const DnaSequence& dna, const NameDna& name, const StatusDna& status): m_dna(dna), m_name(name), m_status(status){++s_id;}
    static IdDna getId(){return s_id;}
    const NameDna& getName()const {return m_name;}
    const DnaSequence& getDnaSeq()const {return m_dna;}

private:
    DnaSequence m_dna;
    NameDna m_name;
    StatusDna m_status;
    static IdDna s_id;
};

#endif //SRC_META_DATA_DNA_H
