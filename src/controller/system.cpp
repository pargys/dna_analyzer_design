//
// Created by y on 7/5/20.
//
#include "system.h"
#include "terminal.h"
#include "structure_dna.h"

void System::start(IReader& input, IWriter& output){
    StructureDna structure;
    Terminal terminal;
    terminal.startApp(input, output, structure);
}
