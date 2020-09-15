//
// Created by y on 6/30/20.
//

#include <fstream>
#include "file_reader.h"
#include <sstream>

void FileReader::read(){
    std::ifstream file;
    file.open(m_filePath.c_str());

    if (!file.is_open()){
        throw std::ifstream::failure("the file is close!");
    }
    getline(file, m_str);
    file.close();
}

std::string FileReader::getFileName(){
    std::string splitName = m_filePath;

    while (splitName.find('/') != std::string::npos){
        splitName = splitName.substr(splitName.find('/') + 1);
    }
    std::stringstream s_stream(splitName);
    std::string substr;
    getline(s_stream, substr, '.');
    return substr;
}
