// list�� merge()
// merge()�� ���ĵ� lst�� �ϳ��� ���ĵ� list�� �պ��ϴ� �Լ�
// ������ �� list�� **�ݵ��** ���ĵǾ� �־�� �Ѵ�.
// ���� ������ ����ڰ� �����ڷ� ���� ���� �ִ�.
// �ٸ� ���ı����� Ʋ�Ȱų�, ���ĵ� ���� �ʴٸ�, merge()��� �Լ��� �����ϸ� ���� �߻�

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

    list<int> List2;

    List2.push_back(10);
    List2.push_back(40);
    List2.push_back(40);
    List2.push_back(20);
    List2.push_back(20);
    List2.push_back(90);
    List2.push_back(10);
    List2.push_back(40);
    List2.push_back(50);
    List2.push_back(10);
    List2.push_back(40);
    List2.push_back(60);
    List2.push_back(80);

    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    // �� ����Ʈ�� ���ĵǾ� ���� �ʱ⶧���� ���� �߻�
    //List1.merge(List2);

    cout << endl;
    cout << "List1.sort();" << endl;
    cout << "List2.sort();" << endl;
    cout << "List1.merge(List2);" << endl;
    cout << endl;

    List1.sort();
    List2.sort();

    List1.merge(List2);

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;
    return 0;
}