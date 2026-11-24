#include <iostream>
#include <fstream>
#include <algorithm>   
#include <vector>
#include <string> 
using namespace std;

int main()
{
    ifstream input("names.txt"); 
    if (!input.is_open())
    {
        cout << "Error: Could not open names.txt" << endl;
        return 1;
    }

    string line;         
    vector<string> names;

    while (getline(input, line))
    {
        if (!line.empty()) 
        {
            names.push_back(line);  
        }
    }

    sort(names.begin(), names.end());

    input.close();

    ofstream output("sorted_names.txt");
    if (!output.is_open())
    {
        cout << "Error: Could not create sort_names.txt" << endl;
        return 1;
    }

    cout << "Names sorted Successfully" << endl;

    for (int i = 0; i < names.size(); i++)
    {
        output << names[i] << endl; 
        cout << names[i] << endl;
    }

    output.close();

    return 0;
}
