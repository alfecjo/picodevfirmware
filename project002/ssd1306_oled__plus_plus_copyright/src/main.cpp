#include <stdio.h>
#include "ContadorApp.hpp"

int main() {
    stdio_init_all();

    ContadorApp app(5, 6); // GPIOs dos botões A e B
    app.init();

    while (true) {
        tight_loop_contents();
    }

    return 0;
}
