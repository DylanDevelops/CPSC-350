#include "functions.hpp"

void bleep(std::string word, std::string& text) {
    std::string replacement(word.length(), '*');
    int pos = text.find(word);
    
    while (pos != std::string::npos) {
        text.replace(pos, word.length(), replacement);
        pos = text.find(word, pos + replacement.length());
    }
}