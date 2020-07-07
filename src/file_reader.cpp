//
// Created by y on 6/30/20.
//

#include <fstream>
#include "file_reader.h"

void FileReader::read(){
    std::ifstream file;
    file.open(m_fileName);
    if(!file.is_open()){
        throw std::ifstream::failure("the file is close!!");
    }
    getline(file, m_str);
    file.close();
}
