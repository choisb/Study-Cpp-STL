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
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    
    cout << endl;

    for (auto vec : v)
        cout << vec << endl;

    cout << endl;

    cout << "size: "<<v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "max_size: " << v.max_size() << endl;

    return 0;
}