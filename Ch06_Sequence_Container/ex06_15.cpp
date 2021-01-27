#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(70);

    vector<int>::iterator iter = v1.begin() + 2;

    v1.insert(iter, 3, 100);

    for (auto v : v1)
        cout << v << " ";
    cout << endl;

    vector<int> v2;

    v2.push_back(111);
    v2.push_back(222);
    v2.push_back(333);
    v2.push_back(444);
    v2.push_back(555);
    v2.push_back(666);
    v2.push_back(777);

    iter = v2.begin() + 2;

    v2.insert(iter, v1.begin(), v1.end());

    for (auto v : v2)
        cout << v << " ";
    cout << endl;

    return 0;

}