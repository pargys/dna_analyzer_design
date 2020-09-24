//
// Created by y on 7/5/20.
//

#ifndef SRC_SYSTEM_H
#define SRC_SYSTEM_H

#include "io_callback.h"

class IReader;
class IWriter;
class UI;
class Parser;
class StructureDna;

class System{
public:
    void start(UI& ui);
    void executeCmd(Parser& p, StructureDna& structure, const IOCallback<UI>& ioCallback);
};

#endif //SRC_SYSTEM_H
