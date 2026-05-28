#include "Menu.h"
#include "CaesarCypher.h"
#include "XorCypher.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip> // Для гарного виводу HEX

void Menu::showMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      ІНФОРМАЦІЙНА СИСТЕМА ШИФРУВАННЯ    " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Використати Шифр Цезаря (цифровий зсув)" << std::endl;
    std::cout << "2. Використати XOR Шифр (текстовий ключ)" << std::endl;
    std::cout << "0. Вихід" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Ваш вибір: ";
}

// Допоміжна функція для безпечного виводу "битого" тексту
void safePrint(const std::string& label, const std::string& text, bool isXor) {
    std::cout << label << ": ";
    if (!isXor) {
        // Для Цезаря виводимо як звичайний текст
        std::cout << text << std::endl;
    }
    else {
        // Для XOR виводимо коди символів, щоб не "ламати" консоль
        for (unsigned char c : text) {
            if (c < 32 || c == 127) {
                // Якщо символ керуючий (невидимий), виводимо його код у дужках
                std::cout << "[" << std::hex << std::uppercase << (int)c << "]" << std::dec;
            }
            else {
                // Якщо символ друкований, виводимо як є
                std::cout << c;
            }
        }
        std::cout << " (HEX: ";
        for (unsigned char c : text) std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
        std::cout << std::dec << ")" << std::endl;
    }
}

void Menu::handleCipherSelection(int type) {
    std::string text, key;

    if (type == 1) {
        manager.setStrategy(std::make_unique<CaesarCypher>());
        std::cout << "\n[КРОК 1] Ви обрали Шифр Цезаря." << std::endl;
        std::cout << "Введіть текст: ";
        std::getline(std::cin, text);
        std::cout << "Введіть КЛЮЧ (число): ";
        std::getline(std::cin, key);
    }
    else {
        manager.setStrategy(std::make_unique<XorCypher>());
        std::cout << "\n[КРОК 1] Ви обрали XOR Шифр." << std::endl;
        std::cout << "Введіть текст: ";
        std::getline(std::cin, text);
        std::cout << "Введіть КЛЮЧ (слово): ";
        std::getline(std::cin, key);
    }

    manager.setData(text, key);

    // --- ШИФРУВАННЯ ---
    std::cout << "\n--- ПРОЦЕС ШИФРУВАННЯ ---" << std::endl;
    std::cout << "ОРИГІНАЛ: " << text << std::endl;

    std::string encryptedResult = manager.executeEncryption();
    safePrint("ЗАШИФРОВАНО", encryptedResult, (type == 2));

    // --- РОЗШИФРУВАННЯ ---
    char subChoice;
    std::cout << "\nБажаєте розшифрувати цей результат? (y/n): ";
    std::cin >> subChoice;
    std::cin.ignore();

    if (subChoice == 'y' || subChoice == 'Y') {
        manager.setData(encryptedResult, key);
        std::string decryptedText = manager.executeDecryption();

        std::cout << "\n--- ПРОЦЕС РОЗШИФРУВАННЯ ---" << std::endl;
        safePrint("ВХІДНІ ДАНІ", encryptedResult, (type == 2));
        std::cout << "РЕЗУЛЬТАТ (Plaintext): " << decryptedText << std::endl;
    }

    std::cout << "\nНатисніть Enter для повернення...";
    std::cin.get();
}

void Menu::run() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore();

        if (choice == 1 || choice == 2) {
            handleCipherSelection(choice);
        }
    } while (choice != 0);
}
