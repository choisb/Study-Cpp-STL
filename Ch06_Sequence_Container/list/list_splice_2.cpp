// list�� �پ��� splice() ����

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

    auto iter1 = List1.begin();  // List1���� ������ ������ ��ġ�� ������ �ݺ��� ����
    iter1++;    // 20
    iter1++;    // 30


    auto iter2 = List2.begin(); // List2���� �߶� �ݺ������� ������ �ݺ��� ����
    iter2++;
    iter2++;    // 300

    cout << endl;
    cout << "List1�� 3��° ��忡 List2�� iter2 ��� �ϳ��� �߶� ����" << endl;
    List1.splice(iter1, List2, iter2);  // List1�� 4��° ��忡 List2�� iter2 ��� �ϳ��� �߶� ����.
                                        // iter1�� ����Ű�� ���� ���Ե� ��� �ڷ� �̵�.
    cout << endl;


    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    iter2 = List2.begin();
    iter2++;        // 200
    iter2++;        // 400


    cout << endl;
    cout << "List1�� 3��° ��忡 List2�� [iter2, List.end()) ������ ������ �߶� ����" << endl;
    List1.splice(iter1, List2, iter2, List2.end());  // List1�� 3��° ��忡 List2�� [iter2, List.end()) ������ ������ �߶� ����.
                                                     // iter1�� ����Ű�� ���� [iter2, List.end()) ������ ���� �ڷ� �̵�.
    cout << endl;

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