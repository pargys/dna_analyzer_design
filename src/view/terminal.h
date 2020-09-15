//
// Created by y on 7/7/20.
//

#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H

#include "../model/structure_dna.h"
#include "iwriter.h"

class IReader;

class Terminal{
public:
    void startApp(IReader& input, IWriter& output, StructureDna& structure);
};

#endif //SRC_TERMINAL_H