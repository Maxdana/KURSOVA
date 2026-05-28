#include "XorCypher.h"

std::string XorCypher::encrypt(const std::string& text, const std::string& key) {
    std::string result = text;
    for (size_t i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

std::string XorCypher::decrypt(const std::string& text, const std::string& key) {
    // XOR симетричний, тому метод такий самий
    return encrypt(text, key);
}
