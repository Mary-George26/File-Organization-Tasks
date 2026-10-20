#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile("welcome.txt");

    if (!outfile.is_open()){
        cout << "Error: File is not open!";
    }
    else {
        cout << "File is open successfully.";
    }

    outfile<<"Hello Everybody";

    outfile.close();

   fstream file("welcome.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 0;
    }

    cout << "Initial put position: " << file.tellp() << endl;

    file.seekp(11);

    cout << "Put position after seekp(11): " << file.tellp() << endl;

    file<<"one ";

    file.close();

    return 0;
}
