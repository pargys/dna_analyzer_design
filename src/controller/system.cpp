//
// Created by y on 7/5/20.
//
#include "system.h"
#include "../view/terminal.h"

void System::start(UI& ui, IReader& input, IWriter& output){
    StructureDna structure;
    ui.startApp(input, output, structure);
}
