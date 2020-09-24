//
// Created by y on 7/5/20.
//
#include "parser.h"

void Parser::parseInput(std::string input){
    size_t pos;
    std::string param;
    char delimiter=' ';

    if ((pos=input.find(delimiter)) == std::string::npos){
        param = input.substr(0, pos);
        m_cmdName = param;
        return;
    }

    param = input.substr(0, pos);
    m_cmdName = param;
    input.erase(0, pos+1);

    while ((pos=input.find(delimiter)) != std::string::npos){
        param = input.substr(0, pos);
        m_params.push_back(param);
        input.erase(0, pos+1);
    }

    if (input != "") {
        m_params.push_back(input);
    }
}
