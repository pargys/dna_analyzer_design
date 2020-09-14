//
// Created by y on 7/5/20.
//

#ifndef SRC_SYSTEM_H
#define SRC_SYSTEM_H

class IReader;
class IWriter;

class System{
public:
    void start(IReader& input, IWriter& output);
};

#endif //SRC_SYSTEM_H
