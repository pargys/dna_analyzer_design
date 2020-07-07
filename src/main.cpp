
#include "system.h"
#include "screen_writer.h"
#include "keyboard_reader.h"

int main() {
    System s;
    KeyboardReader input;
    ScreenWriter output;
    s.start(input, output);
    return 0;
}
