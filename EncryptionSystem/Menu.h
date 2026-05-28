#pragma once
#include "CypherManager.h"

class Menu {
private:
    CypherManager manager;
    void showMenu();
    // Допоміжний метод для зручного введення даних
    void handleCipherSelection(int type);

public:
    void run();
};
