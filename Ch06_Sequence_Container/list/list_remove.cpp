// list�� remove() ����
// remove�� eraseó�� �ش� ���� ��常 �����ϹǷ� �ӵ��� ������ �����ϰ� list���� remove ��� �Լ��� ����.
// �ݺ��ڰ� �ƴ� ������ ������ �����̳��� ���Ҹ� �����ؾ� �Ѵٸ� list �����̳ʸ� �����ϴ� ���� ����.

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> List;

    List.push_back(10);
    List.push_back(20);
    List.push_back(10);
    List.push_back(30);
    List.push_back(10);
    List.push_back(40);
    List.push_back(10);
    List.push_back(50);
    List.push_back(60);

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    List.remove(10);    // 10 ������ ��带 ��� ����

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    return 0;

}