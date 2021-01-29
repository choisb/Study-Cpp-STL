#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    try
    {
        v.at(10) = 5000;    // throw out of range ¿¹¿Ü
        v.at(0) = 1000;
        //v[10] == 1000;
    }
    catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;

    return 0;
}