//
// Created by y on 7/7/20.
//
#include "terminal.h"
#include "parser.h"
#include "create_cmd_factory.h"
#include "i_command.h"

void Terminal::startApp(IReader& input, IWriter& output, StructureDna& structure){
    while(true){
        Parser p;
        input.read();
        p.parseInput(input.getStr());
        if(p.getCmdName() == "quit"){
            break;
        }
        ICommand* cmd = CreateCmdFactory::create(p);
        cmd->run(p, structure, output);
    }
}
