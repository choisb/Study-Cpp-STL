#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    v.clear();
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    if (v.empty())
    {
        cout << "v에 원소가 없습니다. " << endl;
    }

    return 0;
}