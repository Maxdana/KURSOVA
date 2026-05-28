#include "CypherManager.h"

void CypherManager::setStrategy(std::unique_ptr<ICypher> strategy) {
    currentStrategy = std::move(strategy);
}

void CypherManager::setData(const std::string& text, const std::string& k) {
    data = text;
    key = k;
}

std::string CypherManager::executeEncryption() {
    if (currentStrategy) return currentStrategy->encrypt(data, key);
    return "Помилка: Алгоритм не обрано!";
}

std::string CypherManager::executeDecryption() {
    if (currentStrategy) return currentStrategy->decrypt(data, key);
    return "Помилка: Алгоритм не обрано!";
}

bool CypherManager::hasStrategy() const {
    return currentStrategy != nullptr;
}
