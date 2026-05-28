#include "CaesarCypher.h"

std::string CaesarCypher::encrypt(const std::string& text, const std::string& key) {
    int shift = 0;
    try {
        shift = std::stoi(key);
    }
    catch (...) {
        return "Помилка: Ключ для Цезаря має бути числом!";
    }

    std::string result = text;

    for (size_t i = 0; i < result.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(result[i]);

        // 1. Обробка англійських літер (A-Z)
        if (c >= 'A' && c <= 'Z') {
            result[i] = (c - 'A' + (shift % 26) + 26) % 26 + 'A';
        }
        // 2. Обробка англійських літер (a-z)
        else if (c >= 'a' && c <= 'z') {
            result[i] = (c - 'a' + (shift % 26) + 26) % 26 + 'a';
        }
        // 3. Обробка українських/кириличних літер (А-Я) - коди 192-223
        else if (c >= 192 && c <= 223) {
            result[i] = (c - 192 + (shift % 32) + 32) % 32 + 192;
        }
        // 4. Обробка українських/кириличних літер (а-я) - коди 224-255
        else if (c >= 224 && c <= 255) {
            result[i] = (c - 224 + (shift % 32) + 32) % 32 + 224;
        }
        // Інші символи (пробіли, цифри, розділові знаки) залишаються без змін
    }

    return result;
}

std::string CaesarCypher::decrypt(const std::string& text, const std::string& key) {
    int shift = 0;
    try {
        shift = std::stoi(key);
    }
    catch (...) {
        return "Помилка: Ключ має бути числом!";
    }

    // Для дешифрування передаємо від'ємний зсув
    return encrypt(text, std::to_string(-shift));
}

