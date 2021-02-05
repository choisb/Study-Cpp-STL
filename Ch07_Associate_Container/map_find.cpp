// map���� find �Լ���
// map������ find(), lower_bound(), upper_bound(), equal_range() �Լ��� �����Ѵ�.


#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> Map;

    // []�����ڸ� ���ؼ� �� ����
    Map[5] = 800;
    Map[3] = 800;
    Map[8] = 800;
    Map[4] = 800;
    Map[1] = 800;
    Map[7] = 800;
    Map[9] = 800;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // find() �Լ�
    auto iter = Map.find(5);
    if (iter != Map.end())
        cout << "key 5�� ���ε� value: " << iter->second << endl;

    // lower_bound(), upper_bound() �Լ�
    auto lower_iter = Map.lower_bound(4);
    auto upper_iter = Map.upper_bound(4);

    cout << "���� [lower_iter, upper_iter)�� ������: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    // equal_range() �Լ�
    auto iter_pair = Map.equal_range(7);
    cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    return 0;
}
// [��� ���]
// (1, 800) (3, 800) (4, 800) (5, 800) (7, 800) (8, 800) (9, 800)
// key 5�� ���ε� value : 800
// ����[lower_iter, upper_iter)�� ������ : (4, 800)
// ����[iter_pair.first, iter_pair.second)�� ������ : (7, 800)