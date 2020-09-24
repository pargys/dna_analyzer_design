//
// Created by y on 9/15/20.
//

#ifndef SRC_UI_H
#define SRC_UI_H

#include "../model/structure_dna.h"
#include "iwriter.h"
#include "../controller/callback.h"
#include "../controller/system.h"

class UI{
public:
    UI(IReader& input, IWriter& output) : m_input(input), m_output(output){}
    virtual void startApp(StructureDna& structure, Callback<System>& callback) = 0;
    virtual void write(const std::string&) const = 0;
    virtual const std::string & read() const = 0;

protected:
    IReader& m_input;
    IWriter& m_output;
};

#endif //SRC_UI_H
