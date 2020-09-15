//
// Created by y on 6/30/20.
//
#include "../view/file_writer.h"
#include <fstream>
FileWriter::FileWriter(std::string fileName):m_fileName(fileName){}

void FileWriter::write(std::string str) const{
    std::ofstream file;
    if(!file.is_open()){
        throw std::ifstream::failure("the file is close!!");
    }
    file<< str;
    file.close();
}

