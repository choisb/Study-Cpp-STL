// list�� splice() ����
// �ϳ��� ����Ʈ ��ü�� ���� �ӵ��� �߶���� �� �ִ�.
// ����Ʈ���� �ݺ��ڰ� ����Ű�� ������ ��常�� �߶� ���̰ų� �ݺ��� �ϳ��� �������� �߶���̷���
// �ٸ� ������ splice() ��� �Լ� ���

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> List1;
    list<int> List2;

    List1.push_back(10);
    List1.push_back(20);
    List1.push_back(30);
    List1.push_back(40);
    List1.push_back(50);
    List1.push_back(60);

    List2.push_back(100);
    List2.push_back(200);
    List2.push_back(300);
    List2.push_back(400);
    List2.push_back(500);
    List2.push_back(600);

    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    auto iter = List1.begin();  // ������ ������ ��ġ�� ������ �ݺ��� ����
    iter++;
    iter++;                     

    List1.splice(iter, List2);  // List1�� 3��° ��忡 List2�� ��� �߶� ����.
                                // List1�� ���� 3��° ���� �߶� �ٿ��� List2�� �ڷ� �̵�.


    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    return 0;

}