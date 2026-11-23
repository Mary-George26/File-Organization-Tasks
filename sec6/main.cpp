#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error creating grades.txt\n";
        return 1;
    }

    cout << "Enter 5 integer grades:\n";
    for (int i = 0; i < 5; i++) {
        int g;
        cin >> g;
        outFile << g << "\n";
    }
    outFile.close();

    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error opening grades.txt for reading\n";
        return 1;
    }

    cout << "\nGrades in file:\n";
    int grade;
    while (inFile >> grade) {
        cout << grade << "\n";
    }
    inFile.close();

    int gradeToDelete;
    cout << "\nEnter a grade to delete: ";
    cin >> gradeToDelete;

    ifstream inForDelete("grades.txt");
    ofstream tempFile("temp.txt");

    if (!inForDelete || !tempFile) {
        cout << "Error opening files for deletion\n";
        return 1;
    }

    bool found = false;
    while (inForDelete >> grade) {
        if (grade != gradeToDelete) {
            tempFile << grade << "\n";
        } else {
            found = true;
        }
    }

    inForDelete.close();
    tempFile.close();

    if (remove("grades.txt") != 0 || rename("temp.txt", "grades.txt") != 0) {
        cout << "Error replacing the original file!\n";
        return 1;
    }

    if (found) {
        cout << "Grade deleted and grades.txt updated successfully!\n";
    } else {
        cout << "Grade not found, file updated without changes.\n";
    }

    return 0;
}
