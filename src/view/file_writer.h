//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_FILE_WRITER_H
#define DNA_SEQUENCE_FILE_WRITER_H
#include "iwriter.h"


class FileWriter: public IWriter{
public:
    FileWriter(std::string fileName);
    /*virtual*/void write(std::string str)const;

private:
    std::string m_fileName;
};

#endif //DNA_SEQUENCE_FILE_WRITER_H
