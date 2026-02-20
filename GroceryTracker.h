#ifndef CORNER_GROCER_GROCERY_TRACKER_H_
#define CORNER_GROCER_GROCERY_TRACKER_H_

#include <map>
#include <string>

class GroceryTracker {
public:
    GroceryTracker() = default;

    bool LoadInputFile(const std::string& inputFileName);
    bool WriteBackupFile(const std::string& outputFileName) const;

    int GetItemFrequency(const std::string& itemName) const;

    void PrintAllFrequencies() const;
    void PrintHistogram(char symbol = '*') const;

private:
    std::map<std::string, int> m_itemFrequencies;

    static std::string NormalizeItem(const std::string& s);
};

#endif
