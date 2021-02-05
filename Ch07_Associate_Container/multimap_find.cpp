// multimap�� find() ���� ����
// multimap�� find(), count(), lower_bound(), upper_bound(), equal_range()�� �����Ѵ�.

#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> Multimap;

    Multimap.insert(pair<int, int>(5, 100));
    Multimap.insert(pair<int, int>(1, 200));
    Multimap.insert(pair<int, int>(2, 300));
    Multimap.insert(pair<int, int>(4, 400));
    Multimap.insert(pair<int, int>(6, 500));
    Multimap.insert(pair<int, int>(3, 600));

    // �ߺ� ������ �Է�
    Multimap.insert(pair<int, int>(1, 20));
    Multimap.insert(pair<int, int>(1, 30));
    Multimap.insert(pair<int, int>(2, 40));

    for (auto m : Multimap)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // count() : �ش� ������ ���� ��ȯ
    cout << "key�� 1�� ������ ����" << Multimap.count(1) << endl;

    // find() : �ش� ������ ù ��° �ݺ��� ��ȯ
    auto iter = Multimap.find(1);
    if (iter != Multimap.end())
        cout << "ù ��° key 1�� ���ε� value: " << iter->second << endl;

    //lower_bound(), upper_bound() : �ش� ������ ù ��° �ݺ��ڿ� ������ ���� ������ �ݺ��ڸ� ���� ��ȯ
    auto lower_iter = Multimap.lower_bound(1);
    auto upper_iter = Multimap.upper_bound(1);

    cout << "���� [lower_iter, upper_iter)�� ������: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    // equal_range() �Լ�
    auto iter_pair = Multimap.equal_range(1);
    cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    return 0;
}
// [��� ���]
// (1, 200) (1, 20) (1, 30) (2, 300) (2, 40) (3, 600) (4, 400) (5, 100) (6, 500)
// key�� 1�� ������ ����3
// ù ��° key 1�� ���ε� value : 200
// ����[lower_iter, upper_iter)�� ������ : (1, 200) (1, 20) (1, 30)
// ����[iter_pair.first, iter_pair.second)�� ������ : (1, 200) (1, 20) (1, 30)