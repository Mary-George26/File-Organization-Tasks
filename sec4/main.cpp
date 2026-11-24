#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    struct Person {
    string name;
    int age;
    };

    int numOfPersons;

    cout << "How many persons do you want to add? ";
    cin >> numOfPersons;

    ofstream outFile("persons.txt");

    if (!outFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string name;
    int age;

    for (int i = 0; i < numOfPersons; i++)
    {
        cout << "\nPerson " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        outFile << name << " " << age << endl;
    }

    outFile.close();

    cout << "\nData saved successfully." << endl;

    //----------------

 ifstream inFile("persons.txt");

    if (!inFile)
    {
        cout << "Error opening persons.txt" << endl;
        return 1;
    }

    vector<Person> persons;
    Person p;

    while (inFile >> p.name >> p.age)
    {
        persons.push_back(p);
    }

    inFile.close();

    if (persons.size() == 0)
    {
        cout << "No persons found." << endl;
        return 0;
    }

    Person youngest = persons[0];
    Person oldest = persons[0];

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < youngest.age)
        {
            youngest = persons[i];
        }

        if (persons[i].age > oldest.age)
        {
            oldest = persons[i];
        }
    }

    ofstream resultFile("results.txt");

    if (!resultFile)
    {
        cout << "Error opening results.txt" << endl;
        return 1;
    }

    resultFile << "Youngest Person:\n";
    resultFile << youngest.name << " " << youngest.age << endl;

    resultFile << "\nOldest Person:\n";
    resultFile << oldest.name << " " << oldest.age << endl;

    resultFile.close();

    cout << "Results saved successfully." << endl;

    return 0;
}
