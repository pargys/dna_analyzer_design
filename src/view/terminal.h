//
// Created by y on 7/7/20.
//

#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H

#include "iwriter.h"
#include "ui.h"

class IReader;

class Terminal: public UI{
public:
    Terminal(IReader& input, IWriter& output) : UI(input, output) {}
    /*virtual*/ void startApp(StructureDna& structure, Callback<System>& callback);
    /*virtual*/ void write(const std::string& output) const;
    /*virtual*/ const std::string& read() const;
};

#endif //SRC_TERMINAL_H
