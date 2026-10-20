#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string student_name,ID,Grade;

    ofstream myfile ("Student.txt");

    if(!myfile.is_open()){
        cout<<"Error: File is not open!\n";
    }
    else{
        cout<<"File is open successfully.\n";
    }

    cout<<"\nEnter the Full Name:\n";
    getline(cin,student_name);
    myfile<<student_name<<"     ";

    cout<<"\nEnter the ID:\n";
    cin>>ID;
    myfile<<ID<<"     ";

    cout<<"\nEnter the Grade:\n";
    cin>>Grade;
    myfile<<Grade<<"     ";

    myfile.close();

    return 0;
}
