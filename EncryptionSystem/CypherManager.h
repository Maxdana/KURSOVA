#pragma once
#include "ICypher.h"
#include <memory>

class CypherManager {
private:
    std::unique_ptr<ICypher> currentStrategy;
    std::string data;
    std::string key;

public:
    void setStrategy(std::unique_ptr<ICypher> strategy);
    void setData(const std::string& text, const std::string& k);
    std::string executeEncryption();
    std::string executeDecryption();
    bool hasStrategy() const;
};
