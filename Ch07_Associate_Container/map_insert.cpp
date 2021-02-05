// map�� insert() ����
// map�� key�� value��(pair��ü)�� �����Ѵ�.
// key�� �����̳ʿ� �ߺ� ����� �� ����. �ߺ� ������ multimap�� ���
// map�� insert()�� set�� insert()�� �ٸ��� pair ��ü�� ���ڷ� �޾� �����Ѵ�.

// map�� insert()�Լ��� ��ȯ���� set�� insert()�Լ� ó�� ������ ������ ��������(pair ��ü)�̴�.
// ��ȯ�� pair��ü�� first: (������) ���� ������ ��ġ�� ����Ű�� �ݺ��� / (���н�) �̹� ����Ǿ��ִ� key�� ��ġ�� ����Ű�� �ݺ���
// ��ȯ�� pair��ü�� second: (������) true / (���н�) false

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // key, value ��� �������� �����̳� ����
    // �⺻ ���� ���� less
    map<int, int> Map;

    Map.insert(pair<int, int>(5, 100));    // �ӽ� pair ��ü ���� �� ����
    Map.insert(pair<int, int>(2, 100));
    Map.insert(pair<int, int>(8, 300));
    Map.insert(pair<int, int>(3, 400));
    Map.insert(pair<int, int>(1, 200));
    Map.insert(pair<int, int>(7, 400));

    pair<int, int> pr(9, 50);
    Map.insert(pr); // pair ��ü ���� �� ����

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // insert()�� ��ȯ�� Ȯ��

    auto rt = Map.insert(pair<int, int>(4, 500));


    if (rt.second == true)
        cout << rt.first->first << " ��(��) ���������� �����!" << endl;
    else
        cout << rt.first->first << " ��(��) �ߺ��Ǿ ���� ����!" << endl;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    rt = Map.insert(pair<int, int>(4, 500));

    if (rt.second == true)
        cout << rt.first->first << " ��(��) ���������� �����!" << endl;
    else
        cout << rt.first->first << " ��(��) �ߺ��Ǿ ���� ����!" << endl;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    return 0;
}
// [��� ���]
// (1, 200) (2, 100) (3, 400) (5, 100) (7, 400) (8, 300) (9, 50)
// 4 ��(��) ���������� �����!
// (1, 200) (2, 100) (3, 400) (4, 500) (5, 100) (7, 400) (8, 300) (9, 50)
// 4 ��(��) �ߺ��Ǿ ���� ����!
// (1, 200) (2, 100) (3, 400) (4, 500) (5, 100) (7, 400) (8, 300) (9, 50)