#pragma once
#include "ICypher.h"

class CaesarCypher : public ICypher {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& text, const std::string& key) override;
};

