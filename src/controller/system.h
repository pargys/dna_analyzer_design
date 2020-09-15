//
// Created by y on 7/5/20.
//

#ifndef SRC_SYSTEM_H
#define SRC_SYSTEM_H

class IReader;
class IWriter;
class UI;

class System{
public:
    void start(UI& ui, IReader& input, IWriter& output);
};

#endif //SRC_SYSTEM_H
