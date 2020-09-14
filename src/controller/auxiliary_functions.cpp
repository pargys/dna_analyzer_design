//
// Created by y on 7/8/20.
//
#include "auxiliary_functions.h"
#include <sstream>

std::string numToString(size_t num){
    std::stringstream ss;
    ss<< num;
    return ss.str();
}

size_t stringToNum(std::string str){
    std::stringstream ss(str);
    size_t n;
    ss >>n;
    return n;
}