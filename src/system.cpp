//
// Created by y on 7/5/20.
//
#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "create_cmd_factory.h"
#include "i_command.h"
#include "screen_writer.h"

void System::start(){
    while(true){
        KeyboardReader input;
        Parser p;
        ScreenWriter writer;
        input.read();
        p.parseInput(input.getStr());
        if(p.getCmdName() == "quit"){
            break;
        }
        ICommand* cmd = CreateCmdFactory::create(p);
        cmd->run(p);
        cmd->print(&writer);
    }
}
