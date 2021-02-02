// list의 조건자 버전의 unique() 예제
// 조건자 버전의 unique()는 인접한 두 원소를 인자로 받는 이항 조건자가 참이면 다음 원소를 제거한다.

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

    List1.unique(Predicate);
    cout << "unique(Predicate);" << endl;

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    return 0;

}