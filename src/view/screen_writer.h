//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_SCREEN_WRITER_H
#define DNA_SEQUENCE_SCREEN_WRITER_H

#include "iwriter.h"

class ScreenWriter: public IWriter{
public:
    /*virtual*/void write(std::string str)const;
};

#endif //DNA_SEQUENCE_SCREEN_WRITER_H
