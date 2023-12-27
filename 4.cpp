#include <bits/stdc++.h>
#include <unicode/unistr.h>

std::string capitalizeWord(const std::string& word) {
    icu::UnicodeString uword = icu::UnicodeString::fromUTF8(word);
    uword.toTitle(nullptr);
    std::string capitalizedWord;
    uword.toUTF8String(capitalizedWord);
    return capitalizedWord;
}


signed main(int argc, char** argv) {
    std::string inputFileName, outputFileName;

    std::cout << "Введите имя файла с текстом: ";
    std::cin >> inputFileName;

    std::cout << "Введите имя файла для сохранения модифицированного текста: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка. Не удалось открыть файл: " << inputFileName << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка. Не удалось создать файл: " << outputFileName << std::endl;
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            outputFile << capitalizeWord(word) << ' ';
        }

        outputFile << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Модифицированный текст сохранен в файле: " << outputFileName << std::endl;

    return 0;
}
