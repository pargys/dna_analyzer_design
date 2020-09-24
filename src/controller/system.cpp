//
// Created by y on 7/5/20.
//

#include "system.h"
#include "../view/ui.h"
#include "i_command.h"
#include "create_cmd_factory.h"

void System::start(UI& ui){
    CreateCmdFactory::init();
    StructureDna structure;
    Callback<System> callback(*this, &System::executeCmd);
    ui.startApp(structure, callback);
    CreateCmdFactory::release();
}

void System::executeCmd(Parser &p, StructureDna& structure, const IOCallback<UI>& ioCallback) {
    ICommand* cmd = CreateCmdFactory::create(p);
    cmd->run(p, structure, ioCallback);
}
