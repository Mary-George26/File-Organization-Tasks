#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string names[100];
    int n = 0;

    ifstream in("names.txt");
    while (getline(in, names[n])) {
        if (!names[n].empty()) {
            n++;
        }
    }
    in.close();

    sort(names, names + n);

    ofstream out("sorted_names.txt");
    for (int i = 0; i < n; i++) {
        out << names[i] << endl;
        cout << names[i] << endl;
    }
    out.close();

    return 0;
}
