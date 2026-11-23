#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("person.txt");
    for (int i = 0; i < n; i++) {
        string name;
        int age;

        cout << "Enter name for person " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter age for person " << i + 1 << ": ";
        cin >> age;

        outFile << name << "|" << age << "\n";
    }
    outFile.close();

    ifstream inFile("person.txt");
    vector<Person> people;
    string line;

    while (getline(inFile, line)) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            Person temp;
            temp.name = line.substr(0, pos);
            temp.age = stoi(line.substr(pos + 1));
            people.push_back(temp);
        }
    }
    inFile.close();

    if (!people.empty()) {
        Person youngest = people[0];
        Person oldest = people[0];

        for (size_t i = 1; i < people.size(); i++) {
            if (people[i].age < youngest.age) youngest = people[i];
            if (people[i].age > oldest.age)  oldest = people[i];
        }

        ofstream resFile("results.txt");
        resFile << "Youngest: " << youngest.name << " (" << youngest.age << ")\n";
        resFile << "Oldest: " << oldest.name << " (" << oldest.age << ")\n";
        resFile.close();
    }

    cout << "Done! Check results.txt\n";
    return 0;
}
