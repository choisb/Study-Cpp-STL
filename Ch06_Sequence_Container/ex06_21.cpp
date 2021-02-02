#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(60);

    for (auto l : lt)
        cout << l << " ";
    cout << endl;

    lt.push_back(100);
    lt.push_front(200);
    for (auto l : lt)
        cout << l << " ";
    cout << endl;

    return 0;
}