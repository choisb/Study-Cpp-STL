// list의 merge()
// merge()은 정렬된 lst를 하나의 정렬된 list로 합병하는 함수
// 때문에 두 list는 **반드시** 정렬되어 있어야 한다.
// 정렬 기준을 사용자가 조건자로 정할 수도 있다.
// 다만 정렬기준이 틀렸거나, 정렬돼 있지 않다면, merge()멤버 함수는 실패하며 오류 발생

#include <iostream>
#include <list>
using namespace std;

// 뒤에 오는 수가 같거나 작을경우 현재 노드 삭제
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

    // 두 리스트가 정렬되어 있지 않기때문에 에러 발생
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