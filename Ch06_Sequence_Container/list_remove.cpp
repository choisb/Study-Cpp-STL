// list의 remove() 예제
// remove는 erase처럼 해당 값의 노드만 제거하므로 속도가 빠르며 유일하게 list만이 remove 멤버 함수를 가짐.
// 반복자가 아닌 원소의 값으로 컨테이너의 원소를 제거해야 한다면 list 컨테이너를 선택하는 것이 좋음.

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

    List.remove(10);    // 10 원소의 노드를 모두 제거

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    return 0;

}