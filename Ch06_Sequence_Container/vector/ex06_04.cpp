#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1(5);
    for (auto v : v1)
        cout << v << " ";
    cout << endl;

    vector<int> v2(5, 0);
    for (auto v : v2)
        cout << v << " ";
    cout << endl;

    vector<int> v3(5, 10);
    for (auto v : v3)
        cout << v << " ";
    cout << endl;

    return 0;
}