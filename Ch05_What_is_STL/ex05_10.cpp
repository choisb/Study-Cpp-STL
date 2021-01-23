#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    // vector<typename T, typename Alloc = allocator<T>>
    vector<int, allocator<int>> v;     // vector<int> 와 같음

    v.push_back(10);
    cout << *v.begin() << endl;

    // set <typename T, typename Pred = less<T>, typename Alloc = allocator<T>>
    set<int, less<int>, allocator<int>> s;     // set<int> 와 같음

    s.insert(10);
    cout << *s.begin() << endl;

    return 0;
}