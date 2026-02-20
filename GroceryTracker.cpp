#include "GroceryTracker.h"

#include <algorithm>
#include <cctype>
#include <fstream>   // ✅ REQUIRED for ifstream/ofstream
#include <iostream>

std::string GroceryTracker::NormalizeItem(const std::string& s) {
    std::string out = s;

    std::transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

    return out;
}

bool GroceryTracker::LoadInputFile(const std::string& inputFileName) {
    std::ifstream inFile(inputFileName);

    if (!inFile.is_open()) {
        return false;
    }

    m_itemFrequencies.clear();

    std::string item;
    while (inFile >> item) {
        const std::string normalized = NormalizeItem(item);
        m_itemFrequencies[normalized] += 1;
    }

    inFile.close();
    return true;
}

bool GroceryTracker::WriteBackupFile(const std::string& outputFileName) const {
    std::ofstream outFile(outputFileName);

    if (!outFile.is_open()) {
        return false;
    }

    for (const auto& pair : m_itemFrequencies) {
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile.close();
    return true;
}

int GroceryTracker::GetItemFrequency(const std::string& itemName) const {
    const std::string key = NormalizeItem(itemName);

    auto it = m_itemFrequencies.find(key);
    if (it == m_itemFrequencies.end()) {
        return 0;
    }
    return it->second;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : m_itemFrequencies) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

void GroceryTracker::PrintHistogram(char symbol) const {
    for (const auto& pair : m_itemFrequencies) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << symbol;
        }
        std::cout << "\n";
    }
}
