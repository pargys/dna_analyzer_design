//
// Created by y on 7/7/20.
//
#include "terminal.h"
#include "../controller/parser.h"
#include "../controller/create_cmd_factory.h"
#include "../controller/i_command.h"

void Terminal::startApp(IReader& input, IWriter& output, StructureDna& structure){
    CreateCmdFactory::init();

    while (true){
        Parser p;
        output.write("> cmd >>>");
        input.read();
        p.parseInput(input.getStr());

        if (p.getCmdName() == "quit"){
            break;
        }

        try {
            ICommand* cmd = CreateCmdFactory::create(p);
            cmd->run(p, structure, output, input);
        }

        catch (const std::exception& e){
            output.write(e.what());
        }
    }
    CreateCmdFactory::release();
}
