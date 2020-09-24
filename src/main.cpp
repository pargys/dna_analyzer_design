
#include "controller/system.h"
#include "view/screen_writer.h"
#include "view/keyboard_reader.h"
#include "view/terminal.h"

int main() {
    System system;
    KeyboardReader input;
    ScreenWriter output;
    Terminal terminal(input, output);
    system.start(terminal);
    return 0;
}
