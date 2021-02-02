// list�� remove_if() ����
// �����ڴ� bool ������ ��ȯ�ϴ� �Լ���(�Լ�, �Լ� ��ü, �Լ� ������)�� ����� �� �ִ�.


#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)  // ���� ������
{
    return 10 <= n && n <= 30;
}

int main()
{
    list<int> List;

    List.push_back(10);
    List.push_back(20);
    List.push_back(10);
    List.push_back(30);
    List.push_back(10);
    List.push_back(40);
    List.push_back(10);
    List.push_back(50);
    List.push_back(60);

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    List.remove_if(Predicate);    // 10 ~ 30 �� ���� ����

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    return 0;

}