//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_IWRITER_H
#define DNA_SEQUENCE_IWRITER_H
#include <string>

class IWriter{
public:
    virtual ~IWriter(){}
    virtual void write(std::string str) const = 0;
};

#endif //DNA_SEQUENCE_IWRITER_H
