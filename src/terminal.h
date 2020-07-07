//
// Created by y on 7/7/20.
//

#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H
class IReader;
class IWriter;

class Terminal{
public:
    void startApp(IReader* input, IWriter* output);
};

#endif //SRC_TERMINAL_H
