//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_FILE_READER_H
#define DNA_SEQUENCE_FILE_READER_H

#include <iosfwd>
#include "ireader.h"

class FileReader: public IReader{
public:
    void read(std::string fileName);
    /*virtual*/const std::string& getStr() const{return m_str;}

private:
    std::string m_str;
};

#endif //DNA_SEQUENCE_FILE_READER_H
