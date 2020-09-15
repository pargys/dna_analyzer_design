//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_FILE_READER_H
#define DNA_SEQUENCE_FILE_READER_H

#include <iosfwd>
#include "ireader.h"

class FileReader: public IReader{
public:
    FileReader(const std::string& fileName):m_filePath(fileName){}
    /*virtual*/void read();
    /*virtual*/const std::string& getStr() const{return m_str;}
    std::string getFileName();

private:
    std::string m_filePath;
    std::string m_str;
};

#endif //DNA_SEQUENCE_FILE_READER_H
