//
// Created by y on 6/30/20.
//

#include <iostream>
#include "keyboard_reader.h"
void KeyboardReader::read(){
    std::cout<< "> cmd >>>"<< std::endl;
    std::getline(std::cin, m_str, '\n');
}
