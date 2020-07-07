//
// Created by y on 7/5/20.
//
#include "system.h"
//#include "ireader.h"
#include "parser.h"
#include "create_cmd_factory.h"
#include "i_command.h"
#include "screen_writer.h"
#include "terminal.h"

void System::start(IReader* input, IWriter* output){
    Terminal terminal;
    terminal.startApp(input, output);
}
