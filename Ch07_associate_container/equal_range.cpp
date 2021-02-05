// set�� equal_range() ����
// equal_range()�� lower_bound() / upper_bound() �ݺ��� ���� �ϳ��� pair��ü�� ��ȯ�Ѵ�.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ lsee�� ��ĭ �����̳� ����

    Set.insert(50);
    Set.insert(10);
    Set.insert(30);
    Set.insert(20);
    Set.insert(40);
    Set.insert(60);
    Set.insert(80);
    Set.insert(70);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    auto iter_pair = Set.equal_range(30);
    cout << "*iter_pair.first: " << *iter_pair.first << endl;
    cout << "*iter_pair.second: " << *iter_pair.second << endl;

    iter_pair = Set.equal_range(55);
    if (iter_pair.first != iter_pair.second)
        cout << "55�� Set�� ����!" << endl;
    else
        cout << "55�� Set�� ����!" << endl;

    cout << "*iter_pair.first: " << *iter_pair.first << endl;
    cout << "*iter_pair.second: " << *iter_pair.second << endl;
    return 0;
}
// [��� ���]
// 10 20 30 40 50 60 70 80
// * iter_pair.first: 30
// * iter_pair.second : 40
// 55�� Set�� ����!
// *iter_pair.first : 60
// * iter_pair.second : 60