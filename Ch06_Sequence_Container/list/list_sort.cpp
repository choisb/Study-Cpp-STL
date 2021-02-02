// list�� ������ ���� ��� �Լ� sort()�� ����
// ������ ������ �� �ִ� �����̳ʴ� ������ �����̳ʵ�(vector, deque, list)
// vector�� deque�� �������� �ݺ��ڰ� �ֱ� ������ �˰����� sort()�� ����ؼ� ������ ���� ����.
// ����Ʈ�� ����� �ݺ����̱� ������ �˰����� sort()�� ����� �� ����.
// ���� ��ü���� sort()�Լ� ����.
// �����ڸ� ����ؼ� ����ڰ� ������ ������ ������ ���� �ִ�.
// ���⼭�� �Լ���ü ���.


#include <iostream>
#include <list>
using namespace std;
struct Greater
{
    bool operator () (int left, int right) const
    {
        return left > right;
    }
};

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

    cout << "sort();" << endl;

    List1.sort();       //list<int>::sort() list���� �������ִ� �⺻ sort���
    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

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

    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    cout << "sort(std::less<int>());" << endl;
    List2.sort(less<int>());    //std::less<int> �����ڸ� �̿��ؼ� ���� ����
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    cout << "sort(Greater());" << endl;
    List2.sort(Greater());      // ����� ���� �Լ���ü Greater() �����ڸ� �̿��� ���� ����
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    return 0;
}