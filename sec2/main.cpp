#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string a,b,c;

    ifstream in("fruit.txt");
    in >> a >> b >> c;
    in.close();

    ofstream out;
    out.open("fruit.txt",ios::app);
    out<<"\nFresh Fruits";
    out.close();

    return 0;
}
