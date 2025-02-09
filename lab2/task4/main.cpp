#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"
using namespace std;

int main() {
    std::string filename = "sample.txt"; 

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    int letters = letterCounter.countLetters(filename);
    int words = wordCounter.countWords(filename);
    int lines = lineCounter.countLines(filename);

    if (letters == -1 || words == -1 || lines == -1) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    cout << "File: " << filename << std::endl;
    cout << "Letters: " << letters << std::endl;
    cout << "Words: " << words << std::endl;
    cout << "Lines: " << lines << std::endl;

    return 0;
}

