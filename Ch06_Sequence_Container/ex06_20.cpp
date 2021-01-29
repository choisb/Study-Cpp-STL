#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> Numbers;

    for (int i = 0; i < 10; i++)
        Numbers.push_back((i + 1) * 10);

    auto iter = Numbers.begin();

    for (; iter != Numbers.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    iter = Numbers.begin() + 2;
    auto iter2 = Numbers.insert(iter, 500);
    cout << *iter2 << endl;

    for (auto num : Numbers)
        cout << num << ' ';
    cout << endl;

  
}