#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10, 1);    // �ʱ갪 1�� 5�� ���Ҹ� ���� �����̳� ����

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;


    v.assign(5, 2); // 5���� ���Ұ��� 2�� �Ҵ�

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;


    return 0;
}