//
// Created by y on 7/5/20.
//
#include "parser.h"

void Parser::parseInput(std::string& input){
    size_t pos=0;
    std::string param, delimiter=" ";

    if((pos=input.find(delimiter)) == std::string::npos){
        param = input.substr(0, pos);
        m_cmdName = param;
        return;
    }

    param = input.substr(0, pos);
    m_cmdName = param;
    input.erase(0, pos+delimiter.length());

    while((pos=input.find(delimiter)) != std::string::npos){
        param = input.substr(0, pos);
        m_params.push_back(param);
        input.erase(0, pos+delimiter.length());
    }
    m_params.push_back(param);
}
