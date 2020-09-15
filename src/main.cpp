
#include "controller/system.h"
#include "view/screen_writer.h"
#include "view/keyboard_reader.h"
#include "view/terminal.h"

int main() {
    System system;
    Terminal terminal;
    KeyboardReader input;
    ScreenWriter output;
    system.start(terminal, input, output);
    return 0;
}
