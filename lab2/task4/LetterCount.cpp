#include "LetterCount.h"
#include <fstream>
#include <cctype>

LetterCount::LetterCount() {}

int LetterCount::countLetters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return -1; // Return -1 if file not found

    char ch;
    int count = 0;
    while (file.get(ch)) {
        if (std::isalpha(ch)) count++; // Count only letters
    }
    return count;
}

