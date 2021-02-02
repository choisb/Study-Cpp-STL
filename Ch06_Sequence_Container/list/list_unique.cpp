// list�� unique() ����
// unique() �Լ��� ������ ���Ҹ� �����ϰ� �����.
// ��� ���Ҹ� �����ϰ� ����� ���ؼ��� sort�� unique()�� ����Ѵ�.


#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> List1;

    List1.push_back(10);
    List1.push_back(40);
    List1.push_back(40);
    List1.push_back(40);
    List1.push_back(30);
    List1.push_back(20);
    List1.push_back(20);
    List1.push_back(20);
    List1.push_back(40);
    List1.push_back(20);
    List1.push_back(50);
    List1.push_back(40);
    List1.push_back(60);

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    List1.unique();
    cout << "unique();" << endl;

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;


    list<int> List2;

    List2.push_back(10);
    List2.push_back(40);
    List2.push_back(40);
    List2.push_back(40);
    List2.push_back(30);
    List2.push_back(20);
    List2.push_back(20);
    List2.push_back(20);
    List2.push_back(40);
    List2.push_back(20);
    List2.push_back(50);
    List2.push_back(40);
    List2.push_back(60);

    cout << endl;
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    List2.sort();
    cout << "sort();" << endl;


    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    List2.unique();
    cout << "unique();" << endl;


    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;
    return 0;

}