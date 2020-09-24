//
// Created by y on 7/7/20.
//
#include "terminal.h"
#include "../controller/parser.h"
#include "../controller/create_cmd_factory.h"


void Terminal::startApp(StructureDna& structure, Callback<System>& callback){
    IOCallback<UI> ioCallback(*this, &UI::read, &UI::write);
    while (true){
        Parser p;
        write("> cmd >>> ");
        std::string input = read();
        p.parseInput(input);

        if (p.getCmdName() == "quit"){
            break;
        }

        try {
            callback(p, structure, ioCallback);
        }

        catch (const std::exception& e){
            write(e.what());
            write("\n");
        }
    }
}

void Terminal::write(const std::string& output) const {
    m_output.write(output);
}

const std::string& Terminal::read() const {
    m_input.read();
    return m_input.getStr();
}