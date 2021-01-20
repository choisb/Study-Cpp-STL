#include <iostream>
#include <functional> // less<> ���
using namespace std;

typedef less<int> Less;

int main()
{
    Less l;

    cout << l(10, 20) << endl; // l ��ü�� �Ͻ��� �Լ� ȣ��
    cout << l(20, 10) << endl; // l ��ü�� �Ͻ��� �Լ� ȣ��
    cout << l.operator()(10, 20) << endl; // l ��ü�� ����� �Լ� ȣ��
    cout << endl;

    cout << Less()(10, 20) << endl; // �ӽ� ��ü�� �Ͻ��� �Լ� ȣ��
    cout << Less()(20, 10) << endl; // �ӽ� ��ü�� �Ͻ��� �Լ� ȣ��
    cout << Less().operator()(10, 20) << endl; // �ӽ� ��ü�� ����� �Լ� ȣ��

    return 0;
}