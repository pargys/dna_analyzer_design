//
// Created by y on 7/5/20.
//

#ifndef SRC_STATUS_DNA_H
#define SRC_STATUS_DNA_H
#include <string>

class StatusDna{
public:
    StatusDna(const std::string& status):m_status(status){}
private:
    std::string m_status;
};

#endif //SRC_STATUS_DNA_H
