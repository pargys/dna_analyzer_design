//
// Created by y on 6/30/20.
//

#include <fstream>
#include "file_reader.h"

void FileReader::read(std::string fileName){
    std::ifstream file;
    file.open(fileName.c_str());
    if(!file.is_open()){
        throw std::ifstream::failure("the file is close!!");
    }
    getline(file, m_str);
    file.close();
}
