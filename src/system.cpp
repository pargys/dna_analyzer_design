//
// Created by y on 7/5/20.
//
#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "create_cmd_factory.h"
#include "i_command.h"

void System::start(){
    KeyboardReader input;
    Parser p;
    while(true){
        input.read();
        p.parseInput(input.getStr());
        if(p.getCmdName() == "quit"){
            break;
        }
        ICommand* cmd = CreateCmdFactory::create(p.getCmdName());
        cmd->run(p.getParams());
    }
}
