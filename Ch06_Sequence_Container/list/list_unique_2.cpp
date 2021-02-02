// list�� ������ ������ unique() ����
// ������ ������ unique()�� ������ �� ���Ҹ� ���ڷ� �޴� ���� �����ڰ� ���̸� ���� ���Ҹ� �����Ѵ�.

#include <iostream>
#include <list>
using namespace std;

// �ڿ� ���� ���� ���ų� ������� ���� ��� ����
bool Predicate(int first, int second)
{
    cout << "Predicate: " << first << ", " << second << endl;
    return second - first <= 0; 
}

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

    List1.unique(Predicate);
    cout << "unique(Predicate);" << endl;

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    return 0;

}