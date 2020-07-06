//
// Created by y on 7/5/20.
//

#ifndef SRC_NAME_DNA_H
#define SRC_NAME_DNA_H
#include <string>

class NameDna{
public:
    NameDna(const std::string& name = ""):m_name(name){}
    const std::string& getName()const {return m_name;}

private:
    std::string m_name;
};

bool operator<(const NameDna& name1, const NameDna& name2);

#endif //SRC_NAME_DNA_H
