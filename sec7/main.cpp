#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error: Unable to create students.txt\n";
        return 1;
    }
    outFile << "Hadeer Mahmoud\n";
    outFile << "Youssef Ali\n";
    outFile << "Ahmed Mostafa\n";
    outFile << "Esraa Ebrahim\n";
    outFile.close();

    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "Error: Unable to open students.txt\n";
        return 1;
    }

    vector<string> names;
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            names.push_back(line);
        }
    }
    inFile.close();

    sort(names.begin(), names.end());

    cout << "Ascending order:\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << "\n";
    }

    return 0;
}
