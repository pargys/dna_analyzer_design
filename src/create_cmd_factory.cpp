//
// Created by y on 7/5/20.
//

#include <stdexcept>
#include "create_cmd_factory.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "parser.h"

ICommand* CreateCmdFactory::create(const Parser& cmd){
    try{
        s_commands.at(cmd.getCmdName())->createCmd(cmd);
        return s_commands.at(cmd.getCmdName());
    }
    catch (const std::out_of_range& e){
        return NULL;
    }
//    if(cmd.getCmdName() == "new"){
//        return new NewCmd(cmd);
//    }
//    if(cmd.getCmdName() == "load"){
//        return new LoadCmd(cmd);
//    }
//    if(cmd.getCmdName() == "dup"){
//        return new DupCmd(cmd);
//    }
//    return NULL;
}

std::map<std::string, ICommand*> CreateCmdFactory::s_commands = CreateCmdFactory::init();

std::map<std::string, ICommand*> CreateCmdFactory::init(){
    std::map<std::string, ICommand*> temp;
    temp.insert(std::pair<std::string, ICommand*> ("new", new NewCmd()));
    temp.insert(std::pair<std::string, ICommand*> ("load", new LoadCmd()));
    temp.insert(std::pair<std::string, ICommand*> ("dup", new DupCmd()));
    return temp;
}

void CreateCmdFactory::release(){
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("dup");
}

