// multiset�� insert() ����
// multiset�� set�� ���Ұ� �ߺ����� ���� �� �ٸ��� ��� �������̽��� �����ϰ� ����� �� �ִ�.
// �ٸ� �� ������ �������� �����Ѵ�.
// insert�� ��� set������ ���� �ߺ����� ���ؼ� ������ �������� ��� pair��ü�� �ι��� ������ ���и� ��ȯ�ߴ�.
// ������ multiset�� ��쿡�� ������ ������ ��ġ�� ����Ű�� �ݺ��ڰ� ��ȯ�ȴ�.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> Multiset;

    Multiset.insert(50);
    Multiset.insert(30);
    Multiset.insert(80);
    Multiset.insert(80);    // �ߺ�
    Multiset.insert(30);    // �ߺ�
    Multiset.insert(70);
    Multiset.insert(10);
    auto iter = Multiset.insert(30);

    cout << "iter�� ����: " << *iter << endl;

    for (auto ms : Multiset)
    {
        cout << ms << " ";
    }
    cout << endl;

    return 0;
}
// [��� ���]
// iter�� ���� : 30
// 10 30 30 30 50 70 80 80