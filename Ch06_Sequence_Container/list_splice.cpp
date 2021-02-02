// list의 splice() 예제
// 하나의 리스트 전체를 빠른 속도로 잘라붙일 수 있다.
// 리스트에서 반복자가 가리키는 원소의 노드만을 잘라 붙이거나 반복자 하나의 순차열을 잘라붙이려면
// 다른 버전의 splice() 멤버 함수 사용

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> List1;
    list<int> List2;

    List1.push_back(10);
    List1.push_back(20);
    List1.push_back(30);
    List1.push_back(40);
    List1.push_back(50);
    List1.push_back(60);

    List2.push_back(100);
    List2.push_back(200);
    List2.push_back(300);
    List2.push_back(400);
    List2.push_back(500);
    List2.push_back(600);

    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    auto iter = List1.begin();  // 리스를 삽입할 위치를 지정할 반복자 선언
    iter++;
    iter++;                     

    List1.splice(iter, List2);  // List1의 3번째 노드에 List2를 모두 잘라 넣음.
                                // List1의 원래 3번째 노드는 잘라 붙여진 List2의 뒤로 이동.


    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    return 0;

}