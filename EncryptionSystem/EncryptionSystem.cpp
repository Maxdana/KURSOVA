#include "Menu.h"
#include <iostream>

int main() {
    // Налаштування кодування для підтримки української мови в консолі
    setlocale(LC_ALL, "Ukrainian");

    Menu app;
    app.run();

    return 0;
}
