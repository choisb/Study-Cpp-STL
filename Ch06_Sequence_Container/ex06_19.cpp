#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> deques;
    for (int i = 0; i < 10; ++i) {
        deques.push_back((i + 1) * 10);
        cout << "size: " << deques.size() << endl;
    }

    for (auto dq : deques)
        cout << dq << ' ';
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        deques.push_front((i + 1));
        cout << "size: " << deques.size() << endl;
    }

    for (auto dq : deques)
        cout << dq << ' ';
    cout << endl;
    cout << endl;

    return 0;
}