//
// Created by y on 9/15/20.
//

#ifndef SRC_UI_H
#define SRC_UI_H

#include "../model/structure_dna.h"
#include "iwriter.h"

class UI{
public:
    virtual void startApp(IReader& input, IWriter& output, StructureDna& structure) = 0;
};

#endif //SRC_UI_H
