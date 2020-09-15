//
// Created by y on 6/30/20.
//

#ifndef DNA_SEQUENCE_KEYBOARD_READER_H
#define DNA_SEQUENCE_KEYBOARD_READER_H

#include <string>
#include "ireader.h"

class KeyboardReader: public IReader{
public:
    void read();
    const std::string& getStr() const{return m_str;}

private:
    std::string m_str;
};

#endif //DNA_SEQUENCE_KEYBOARD_READER_H
