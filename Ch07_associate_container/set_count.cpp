// set�� count() ����
// count() �� set �����̳ʿ� �ش� ���Ұ� ������� ��ȯ�Ѵ�.
// �ߺ��� ������� �ʴ� set �����̳ʿ����� count()�� �ʿ������� ������, 
// ��� ���� �����̳��� �������̽��� �����Ƿ� set�� count()�� ����
// ���� �ð��� �α� �ð� ���⵵�̴�.

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

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    cout << "���� 50�� ����: " << Set.count(50) << endl;    // ���� 50�� ����
    cout << "���� 100�� ����: " << Set.count(100) << endl;   // ���� 100�� ����

    return 0;
}
// [��� ���]
// 10 20 30 40 50
// ���� 50�� ���� : 1
// ���� 100�� ���� : 0