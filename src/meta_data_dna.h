//
// Created by y on 7/5/20.
//

#ifndef SRC_META_DATA_DNA_H
#define SRC_META_DATA_DNA_H

#include "dna_sequence.h"
#include "name_dna.h"
#include "id_dna.h"
#include "status_dna.h"

class MetaDataDna{
public:
    MetaDataDna(const DnaSequence& dna, const NameDna& name, const StatusDna& status): m_dna(new DnaSequence(dna)), m_name(name), m_status(status), m_counter(0){++s_id;}
    ~MetaDataDna(){delete m_dna;}
    static IdDna getId(){return s_id;}
    const NameDna& getName()const {return m_name;}
    const DnaSequence& getDnaSeq()const {return *m_dna;}
    size_t getCounter()const {return m_counter;}
    void increaseCounter(){++m_counter;}

private:
    DnaSequence* m_dna;
    NameDna m_name;
    StatusDna m_status;
    static IdDna s_id;
    size_t m_counter;
};

#endif //SRC_META_DATA_DNA_H
