// set�� insert() �����.
// set �����̳ʴ� ����(key)�� �����ϴ� ������ ��� �Լ� insert()�� �����Ѵ�.
// ���� ������ �����Ƿ� insert()�� ���� ���Ե� ���Ҵ� �ڵ� ���ĵȴ�. default: less ������
// ��� ����(key)�� �����ϴ�. ���� ������ �ߺ��� ����ؾ� �Ѵٸ� multiset�� ����ؾ�.
// insert()�� ��ȯ ���� pair<set<T>::iterator, bool>���� insert�� ����� �����Ѵ�.
// ��ȯ�� pair�� second ���� ���� ����, ������ ����� ��� �ִ�. ���� �ߺ��� ��� ���Ҹ� �������� �ʰ� false�� ��ȯ�Ѵ�.
// second�� true�� ��� first���� ������ ���Ҹ� ����Ű�� �ݺ����̸�,
// second�� false�� ��� �̹� ���Ե� ���Ҹ� ����Ű�� �ݺ��ڰ� ��ȯ�ȴ�.
// insert() ��� �Լ��� �̿��� ������ �α� �ð� ���⵵�� ������. 


#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ lsee�� ��ĭ �����̳� ����

    // pair<set<int>::iterator, bool> pr;

    auto pr = Set.insert(50); // ����(key) ����
    if (pr.second == true)
        cout << *pr.first << " ���� ����!" << endl;
    else
    {
        cout << *pr.first << " ��(��) �̹� �ֽ��ϴ�. ���� ����!" << endl;
    }

    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);
    Set.insert(110);
    Set.insert(100);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    pr = Set.insert(50); // �ߺ��� ���� ����. ����!

    if (pr.second == true)
        cout << *pr.first << " ���� ����!" << endl;
    else
    {
        cout << *pr.first << " ��(��) �̹� �ֽ��ϴ�. ���� ����!" << endl;
    }


    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;

}