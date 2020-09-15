
#include "controller/system.h"
#include "view/screen_writer.h"
#include "view/keyboard_reader.h"

int main() {
    System s;
    KeyboardReader input;
    ScreenWriter output;
    s.start(input, output);
    return 0;
}
