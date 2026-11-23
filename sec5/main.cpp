#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("students.txt", ios::app);
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        char name[20];
        int id;
        float grade;
        char delim = '$';

        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " " << delim << "\n";

        cout << "Add another record? (y/n): ";
        cin >> choice;
    }

    file.close();
    cout << "Records saved to students.txt\n";
    return 0;
}
