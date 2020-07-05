//
// Created by y on 7/5/20.
//

#ifndef SRC_PARSER_H
#define SRC_PARSER_H
#include <vector>
#include <string>

class Parser{
public:
    void parseInput(std::string input);
    const std::string& getCmdName()const {return m_cmdName;}
    const std::vector<std::string>& getParams()const {return m_params;}

private:
    std::string m_cmdName;
    std::vector<std::string> m_params;
};

#endif //SRC_PARSER_H
