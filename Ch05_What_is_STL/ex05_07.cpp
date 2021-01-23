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

    // 정방향으로 출력하는 일반 반복자
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // 일반 반복자 iterator를 역방향 반복자 reverse_iterator로 변환
    reverse_iterator<vector<int>::iterator> riter (v.end());
    reverse_iterator<vector<int>::iterator> end_riter(v.begin());

    // 정방향 반복자 iter과 반대로 동작한다.
    for (; riter != end_riter; ++riter)
        cout << *riter << " ";
    cout << endl;

    return 0;
}