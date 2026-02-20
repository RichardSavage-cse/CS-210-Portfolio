#include "GroceryTracker.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

static void PrintMenu() {
    cout << "\n=============================\n";
    cout << "Corner Grocer - Item Tracker\n";
    cout << "=============================\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

static int ReadMenuChoice() {
    int choice;

    while (true) {
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of line
            return choice;
        }

        cout << "Invalid choice. Enter a number 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string backupFileName = "frequency.dat";

    GroceryTracker tracker;

    // Load input at startup
    if (!tracker.LoadInputFile(inputFileName)) {
        cout << "ERROR: Could not open input file: " << inputFileName << "\n";
        cout << "Make sure the .txt file is in the same folder as your program.\n";
        return 1;
    }

    // Create backup at startup (no user intervention)
    if (!tracker.WriteBackupFile(backupFileName)) {
        cout << "WARNING: Could not create backup file: " << backupFileName << "\n";
    }

    while (true) {
        PrintMenu();
        int choice = ReadMenuChoice();

        if (choice == 1) {
            cout << "Enter item name to search: ";
            string item;
            getline(cin, item);

            int freq = tracker.GetItemFrequency(item);
            cout << item << " " << freq << "\n";
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram('*');
        }
        else { // 4
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
