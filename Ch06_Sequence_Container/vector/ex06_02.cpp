#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.reserve(9);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(10);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(20);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(30);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(40);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(50);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(60);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(70);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(80);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(90);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(100);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(110);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(120);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(130);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(140);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(150);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(160);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(170);

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;

    return 0;
}