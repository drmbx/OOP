#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <iomanip>

int main(int argc, char *argv[])
{
    std::string inputFileName = "C:\\programming\\OOP\\Lector_0b\\input.txt"; //argv[1];
    std::string outputFileName = "output.csv"; //argv[2];

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    std::map<std::string, int> words;
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            std::string cleanedWord;
            for (char c: word)
                if (std::isalnum(c))
                    cleanedWord += tolower(c);
            words[cleanedWord]++;
        }
    }
    inputFile.close();

    std::vector<std::pair<std::string, int>> sortedWords;

    for (const auto& pair : words)
        sortedWords.emplace_back(pair);

    // Сортировка в порядке убывания частоты
    std::sort(sortedWords.begin(), sortedWords.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    std::ofstream outputFile(outputFileName);
    outputFile << "Word,Frequency,Frequency (%)" << std::endl;
    for (const auto& pair : sortedWords) {
        int totalWords = std::accumulate(sortedWords.begin(), sortedWords.end(),
                                         0, [](int sum, const auto& p) {
                    return sum + p.second;
                });

        double frequencyPercent = static_cast<double>(pair.second) / totalWords * 100.0;

        outputFile << pair.first << "," << pair.second << "," << std::setprecision(2)
                   << std::fixed << frequencyPercent << std::endl;
    }

    outputFile.close();

    std::cout << "Word count data has been saved to " << outputFileName << std::endl;

    return 0;
}
