//
// Created by y on 7/5/20.
//

#include <stdexcept>
#include "create_cmd_factory.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "save_cmd.h"
#include "len_cmd.h"
#include "del_cmd.h"
#include "rename_cmd.h"
#include "parser.h"

std::map<std::string, ICommand*> CreateCmdFactory::s_commands;

ICommand* CreateCmdFactory::create(const Parser& cmd){
    try{
        s_commands.at(cmd.getCmdName())->createCmd(cmd);
        return s_commands.at(cmd.getCmdName());
    }

    catch (const std::out_of_range& e){
        return NULL;
    }
}

void CreateCmdFactory::init(){
    s_commands.insert(std::pair<std::string, ICommand*> ("new", new NewCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("load", new LoadCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("dup", new DupCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("save", new SaveCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("len", new LenCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("del", new DelCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("rename", new RenameCmd()));
}

void CreateCmdFactory::release(){
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("dup");
    delete s_commands.at("save");
    delete s_commands.at("len");
    delete s_commands.at("del");
    delete s_commands.at("rename");
}

