#pragma once
#include <string>

// Інтерфейс для всіх алгоритмів шифрування (Принцип DIP)
class ICypher {
public:
    virtual ~ICypher() {}
    virtual std::string encrypt(const std::string& text, const std::string& key) = 0;
    virtual std::string decrypt(const std::string& text, const std::string& key) = 0;
}; 

