//
// Created by y on 6/1/20.
//

#ifndef DNA_SEQUENCE_DNA_SEQUENCE_H
#define DNA_SEQUENCE_DNA_SEQUENCE_H

#include <cstring>
#include <iostream>
#include "string.h"
#include <list>
#include "../view/ireader.h"

class DnaSequence{
private:
    class Nucleotid{
    public:
        Nucleotid(const char c): m_c(c){}
        Nucleotid():m_c('\0'){}
        const Nucleotid& operator=(char c);
        char getC();
        operator char(){return m_c;}
        char getMatchNucleotid() const;
    private:
        char m_c;
    };
    typedef Nucleotid Nucleotid;

    Nucleotid* m_dna;
    size_t m_length;
    void initDna(const char* sequence);
    bool is_valid(const char* sequence);
    DnaSequence(size_t length);

public:
    DnaSequence(const char* sequence);
    DnaSequence(const std::string& sequence);
    DnaSequence(const DnaSequence& dnaSequence);
    DnaSequence(const IReader& sequence);

    ~DnaSequence();
    const DnaSequence& operator=(const DnaSequence& dnaSequence);
    size_t length() const;
    const char* getDna() const;
    Nucleotid& operator[](size_t i);

    DnaSequence getSlice(size_t start, size_t end) const;
    DnaSequence getPairedStrand() const;
    size_t find(const DnaSequence& dnaSequence, size_t index = 0) const;
    size_t count(const DnaSequence& dnaSequence) const;
    std::list<size_t> findAll(const DnaSequence& dnaSequence) const;
    std::list<DnaSequence> allConsensusSequences() const;
};

bool operator==(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);
bool operator!=(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);
std::ostream& operator<<(std::ostream &out, const DnaSequence& dnaSequence);

#endif //DNA_SEQUENCE_DNA_SEQUENCE_H
