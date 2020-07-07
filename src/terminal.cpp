//
// Created by y on 7/7/20.
//
#include "terminal.h"
#include "parser.h"
#include "create_cmd_factory.h"
#include "i_command.h"
#include "ireader.h"

void Terminal::startApp(IReader* input, IWriter* output){
    while(true){
        Parser p;
        input->read();
        p.parseInput(input->getStr());
        if(p.getCmdName() == "quit"){
            break;
        }
        ICommand* cmd = CreateCmdFactory::create(p);
        cmd->run(p);
        cmd->print(output);
    }
}
