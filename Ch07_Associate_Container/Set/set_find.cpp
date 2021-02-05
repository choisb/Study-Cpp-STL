// set�� find() ����
// find()�� key(����)�� �˻��Ͽ� key�� ����Ű�� �ݺ��ڸ� ��ȯ.
// key�� ������ �� ǥ�� �ݺ��ڸ� ��ȯ
// ������ find() �Լ��� ��ȯ���� end() �Լ��� ���� �˻��� �����ߴ��� �����ߴ��� �Ǵ�
// [����]
// find()�Լ����� ���Ҹ� Ž���Ҷ� "==" �����ڰ� �ƴ� �����ڸ� Ȱ���� Ž���� �Ѵ�.
// ��, !(a<b) && !(b>a) �� ���� ���� ���̶�� �����ϰ� Ž���� �Ѵ�.
// !s.key_comp()(a,b) && !s.key_comp()(b,a) �ΰ�� �� ���Ҵ� ���� ������ ����.

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

    auto iter = Set.find(50);
    if (iter != Set.end())  // ã�� ���� 50�� �����ϱ� ������ find(50)�� �ش� ���� �ݺ��� ��ȯ
        cout << *iter << "��(��) Set�� �ִ�!" << endl;
    else
    {
        cout << " 50�� Set�� ����!" << endl;
    }

    return 0;
}
// [��� ���]
// 10 20 30 40 50 60 70 80
// 50��(��) Set�� �ִ�!