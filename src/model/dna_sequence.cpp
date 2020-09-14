//
// Created by y on 6/1/20.
//

#include "dna_sequence.h"
#include <list>
#include <fstream>

DnaSequence::DnaSequence(const IReader& sequence){
    initDna(sequence.getStr().c_str());
}

DnaSequence::DnaSequence(const char* sequence) {
    initDna(sequence);
}

DnaSequence::DnaSequence(const std::string& sequence) {
    initDna(sequence.c_str());
}

DnaSequence::DnaSequence(const DnaSequence& dnaSequence){
    initDna(dnaSequence.getDna());
}

DnaSequence::DnaSequence(size_t length):m_length(length) {
    m_dna = new Nucleotid [length+1];
}

const DnaSequence& DnaSequence::operator=(const DnaSequence& dnaSequence){
    if(this == &dnaSequence)
        return *this;
    delete[] m_dna;
    m_dna = NULL;
    initDna(dnaSequence.getDna());
    return *this;
}

DnaSequence::~DnaSequence(){
    delete[]m_dna;
    m_dna = NULL;
}

std::ostream& operator<<(std::ostream &out, const DnaSequence& dnaSequence){
    return out << dnaSequence.getDna()<< std::endl;
}

DnaSequence::Nucleotid& DnaSequence::operator[](size_t i) {
    if(i>=0 && i<length())
    {
        return m_dna[i];
    }
    throw std::out_of_range("out_of_range");
}

const DnaSequence::Nucleotid& DnaSequence::Nucleotid::operator=(char c) {
    if(c == 'A' || c == 'G' || c == 'C' || c == 'T'){
        m_c = c;
        return *this;
    }
    throw std::invalid_argument("invalid dna sequence");
}

char DnaSequence::Nucleotid::getC() {
    return m_c;
}

size_t DnaSequence::length() const{
    return m_length;
}

const char* DnaSequence::getDna() const{
    return (char*)m_dna;
}

bool operator==(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2) {
    return strcmp(dnaSequence1.getDna(), dnaSequence2.getDna()) == 0;
}

bool operator!=(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2) {
    return strcmp(dnaSequence1.getDna(), dnaSequence2.getDna()) != 0;
}

void DnaSequence::initDna(const char* sequence) {
    if(!is_valid(sequence))
        throw std::invalid_argument("invalid dna sequence");
    m_length = strlen(sequence);
    m_dna = new Nucleotid [m_length+1] ;
    for(size_t i=0; i<m_length; i++)
    {
        m_dna[i] = sequence[i];
    }
}

bool DnaSequence::is_valid(const char* sequence) {
    if(sequence!=NULL && sequence!= "" && strspn(sequence, "ACGT") == strlen(sequence))
        return true;
    return false;
}

DnaSequence DnaSequence::getSlice(size_t start, size_t end) const{
    if(end>m_length)
        end = m_length+1;
    DnaSequence dnaSequence(end-start);
    for(size_t i=start, j=0; i<end; ++i, j++)
    {
        dnaSequence[j] = m_dna[i];
    }
    return dnaSequence;
}

DnaSequence DnaSequence::getPairedStrand() const {
    DnaSequence pairedStrand(m_length);
    for(size_t i=0, j=m_length-1; i<m_length; i++, j--)
    {
        pairedStrand[i] = m_dna[j].getMatchNucleotid();
    }
    return pairedStrand;
}

char DnaSequence::Nucleotid::getMatchNucleotid() const{
    if(m_c == 'A')
        return 'T';
    if(m_c == 'T')
        return 'A';
    if(m_c == 'G')
        return 'C';
    return 'G';
}

size_t DnaSequence::find(const DnaSequence& dnaSequence, size_t index) const{
    std::string s = getDna();
    size_t offset = s.find(dnaSequence.getDna(), index);
    if(offset == std::string::npos)
        return m_length;
    return offset;
}

size_t DnaSequence::count(const DnaSequence &dnaSequence) const {
    size_t count = 0;
    size_t index = find(dnaSequence);
    while(index!= m_length){
        count ++;
        index = find(dnaSequence, index+1);
    }
    return count;
}

std::list<size_t> DnaSequence::findAll(const DnaSequence &dnaSequence)const {
    std::list<size_t> indexes;
    size_t index = find(dnaSequence);
    while(index!= m_length){
        indexes.push_back(index);
        index = find(dnaSequence, index+1);
    }
    return indexes;
}

size_t min(size_t index1, size_t index2, size_t index3) {
    index1 = index1 <= index2 ? index1: index2;
    index1 = index1 <= index3 ? index1: index3;
    return index1;
}

std::list<DnaSequence> DnaSequence::allConsensusSequences() const {
    std::list<DnaSequence> _list;
    std::list<size_t> startCodonIndexes = findAll("ATG");
    size_t endCodon1Index, endCodon2Index, endCodon3Index, end;
    for(std::list<size_t>::iterator i=startCodonIndexes.begin();i!=startCodonIndexes.end();++i)
    {
        endCodon1Index = find("TAG", *i);
        if((endCodon1Index-*i)%3){
            endCodon1Index = m_length;
        }
        endCodon2Index = find("TAA", *i);
        if((endCodon2Index-*i)%3){
            endCodon2Index = m_length;
        }
        endCodon3Index = find("TGA", *i);
        if((endCodon3Index-*i)%3){
            endCodon3Index = m_length;
        }
        end = min(endCodon1Index, endCodon2Index, endCodon3Index);
        if(end != m_length){
            _list.push_back(getSlice(*i, end+3));
        }
    }
    return _list;
}
