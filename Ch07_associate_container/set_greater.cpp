// set�� �����ڸ� greater�� �ٲٴ� ����

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int, greater<int>> Set; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ greater �����ڷ� �ٲ� �����̳� ����


    Set.insert(50); // ����(key) ����
    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
// [��� ���]
// 90 80 70 50 30 20 10

