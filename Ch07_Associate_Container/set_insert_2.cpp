// set�� insert() �پ��� ���� ����
// ������ ������ ���� �����ϴ� ������ insert()����
// ������ ��ġ�� �����ϴ� ���� ����
// ���� ���� ��ġ�� ���ļ����� �´ٸ� �ٷ� ���Ե����� �ƴ϶�� �α� �ð��� �ɸ���.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ lsee�� ��ĭ �����̳� ����

    // pair<set<int>::iterator, bool> pr;

    Set.insert(50); // ����(key) ����
    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);
    auto pr = Set.insert(100);
    
    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    Set.insert(pr.first, 95);   // 100 ������ �ݺ��ڿ��� �˻� ���� �� ������ ����

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;


    return 0;

}