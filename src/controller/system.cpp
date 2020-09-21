//
// Created by y on 7/5/20.
//

#include "system.h"
#include "../view/terminal.h"
#include "i_command.h"
#include "create_cmd_factory.h"

void System::start(UI& ui, IReader& input, IWriter& output){
    CreateCmdFactory::init();
    StructureDna structure;
    Callback<System> callback(*this, &System::executeCmd);
    ui.startApp(input, output, structure, callback);
    CreateCmdFactory::release();
}

void System::executeCmd(Parser &p, StructureDna& structure, IWriter& output, IReader& input) {
    ICommand* cmd = CreateCmdFactory::create(p);
    cmd->run(p, structure, output, input);
}
