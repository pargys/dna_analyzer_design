//
// Created by y on 7/5/20.
//

#ifndef SRC_META_DATA_DNA_H
#define SRC_META_DATA_DNA_H

#include "dna_sequence.h"

class MetaDataDna{
public:
    MetaDataDna(const DnaSequence& dna, const std::string& name, const std::string& status): m_dna(new DnaSequence(dna)), m_name(name), m_status(status), m_counter(0){++s_id;}
    MetaDataDna(const MetaDataDna& other);
    ~MetaDataDna(){delete m_dna;
                    m_dna = NULL;}
    static size_t getId(){return s_id;}
    const std::string& getName()const {return m_name;}
    const DnaSequence* getDnaSeq()const {return m_dna;}
    size_t getCounter()const {return m_counter;}
    void increaseCounter(){++m_counter;}

private:
    DnaSequence* m_dna;
    std::string m_name;
    std::string m_status;
    static size_t s_id;
    size_t m_counter;
};

#endif //SRC_META_DATA_DNA_H
