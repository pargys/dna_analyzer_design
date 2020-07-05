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
private:
    DnaSequence dna;
    NameDna name;
    IdDna id;
    StatusDna status;
};

#endif //SRC_META_DATA_DNA_H
