//
// Created by y on 7/5/20.
//

#include <stdexcept>
#include "create_cmd_factory.h"
#include "parser.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "save_cmd.h"
#include "len_cmd.h"
#include "del_cmd.h"
#include "rename_cmd.h"
#include "find_cmd.h"
#include "count_cmd.h"
#include "enter_cmd.h"


std::map<std::string, ICommand*> CreateCmdFactory::s_commands;

ICommand* CreateCmdFactory::create(const Parser& cmd){
    try{
        s_commands.at(cmd.getCmdName())->createCmd(cmd);
        return s_commands.at(cmd.getCmdName());
    }

    catch (const std::out_of_range& e){
        throw std::invalid_argument("command not found. press help to see available commands");
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
    s_commands.insert(std::pair<std::string, ICommand*> ("find", new FindCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("count", new CountCmd()));
    s_commands.insert(std::pair<std::string, ICommand*> ("", new EnterCmd()));

}

void CreateCmdFactory::release(){
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("dup");
    delete s_commands.at("save");
    delete s_commands.at("len");
    delete s_commands.at("del");
    delete s_commands.at("rename");
    delete s_commands.at("find");
    delete s_commands.at("count");
    delete s_commands.at("");
}

