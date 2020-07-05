//
// Created by y on 7/5/20.
//

#ifndef SRC_NAME_DNA_H
#define SRC_NAME_DNA_H
#include <string>

class NameDna{
public:
    const std::string& getDna()const {return m_name;}

private:
    std::string m_name;
};

#endif //SRC_NAME_DNA_H
