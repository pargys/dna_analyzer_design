//
// Created by y on 7/5/20.
//

#ifndef SRC_ID_DNA_H
#define SRC_ID_DNA_H
#include <cstdio>

class IdDna{
public:
    IdDna(size_t id = 0):m_id(id){}
    const IdDna operator++();
    size_t getId()const {return m_id;}

private:
    size_t m_id;
};

bool operator<(const IdDna& id1, const IdDna& id2);
#endif //SRC_ID_DNA_H
