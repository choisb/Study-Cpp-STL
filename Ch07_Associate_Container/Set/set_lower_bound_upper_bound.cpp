// set�� lower_bound() / upper_bound() ����
// lower_bound()�� upper_bound()�� ã�� key�� ������ �������� ��ȯ�ϴ� ��� �Լ�
// ��� �ߺ� key�� ���� �ʴ� set���� �� ��� �Լ��� ū �ǹ̰� ������ ����.

// lower_bound()�� ã�� ������ ���� �ݺ��ڸ� ��ȯ
// upper_bound()�� ã�� ������ ���� ���Ҹ� ��ȯ
// ã�� ���Ҿ��ٸ� �� ��ȯ���� ���� ���� �ݺ��ڸ� ��ȯ��. 
// �̸� Ȱ���ؼ� Ž�� ���п��θ� �Ǵ� �� �� �ִ�.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ lsee�� ��ĭ �����̳� ����

    Set.insert(50);
    Set.insert(10);
    Set.insert(30);
    Set.insert(20);
    Set.insert(40);
    Set.insert(60);
    Set.insert(80);
    Set.insert(70);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    auto iter_lower = Set.lower_bound(30);
    auto iter_upper = Set.upper_bound(30);


    if (iter_lower != iter_upper)
        cout << "30�� Set�� ����!" << endl;
    else
        cout << "30�� Set�� ����!" << endl;

    cout << "iter_lower: " << *iter_lower << endl;
    cout << "iter_upper: " << *iter_upper << endl;


    iter_lower = Set.lower_bound(55);
    iter_upper = Set.upper_bound(55);
    
    if (iter_lower != iter_upper)
        cout << "55�� Set�� ����!" << endl;
    else {
        cout << "55�� Set�� ����!" << endl;
    }

    cout << "iter_lower: " << *iter_lower << endl;
    cout << "iter_upper: " << *iter_upper << endl;

    return 0;
}
// [��� ���]
// 10 20 30 40 50 60 70 80
// 30�� Set�� ����!
// iter_lower: 30
// iter_upper : 40
// 55�� Set�� ����!
// iter_lower : 60
// iter_upper : 60