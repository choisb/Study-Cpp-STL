//multiset�� Ž������ �Լ���
// find(), count(), lower_bound(), upper_bound(), equal_range()�� �����Ѵ�.
// find() �ش� ������ �ݺ��� ��ȯ, �ߺ� ���Ұ� �ִٸ� ù��° ������ �ݺ��� ��ȯ
// count() �ش� ������ ���� ��ȯ
// lower_bound() �ش� ������ ���� �ݺ��� ��ȯ
// upper_bound() �ش� ������ �������� ���� �ݺ��� ��ȯ
// equal_range() �ش� ������ ������ pair ��ü�� ��ȯ. lower_bound()�� upper_bound()�� ����ִ�.

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

    for (auto ms : Multiset)
    {
        cout << ms << " ";
    }
    cout << endl;

    cout << "30�� ������ ����: " << Multiset.count(30) << endl;

    auto iter = Multiset.find(30); // 30 ù��° ������ �ݺ���
    cout << "iter: " << *iter << endl;

    auto lower_iter = Multiset.lower_bound(30);     // 30 �������� ���� �ݺ���
    auto upper_iter = Multiset.upper_bound(30);     // 30 �������� �� �ݺ���

    cout << "lower_iter: " << *lower_iter << endl;
    cout << "upper_iter: " << *upper_iter << endl;

    cout << "���� [lower_iter, upper_iter)�� ������: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    auto iter_pair = Multiset.equal_range(80);
    cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
// [��� ���]
// 10 30 30 50 70 80 80
// 30�� ������ ���� : 2
// iter : 30
// lower_iter : 30
// upper_iter : 50
// ����[lower_iter, upper_iter)�� ������ : 30 30
// ����[iter_pair.first, iter_pair.second)�� ������ : 80 80