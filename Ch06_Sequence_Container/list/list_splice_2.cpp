// list의 다양한 splice() 예제

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

    auto iter1 = List1.begin();  // List1에서 리스를 삽입할 위치를 지정할 반복자 선언
    iter1++;    // 20
    iter1++;    // 30


    auto iter2 = List2.begin(); // List2에서 잘라낼 반복구간을 설정할 반복자 선언
    iter2++;
    iter2++;    // 300

    cout << endl;
    cout << "List1의 3번째 노드에 List2의 iter2 노드 하나를 잘라 넣음" << endl;
    List1.splice(iter1, List2, iter2);  // List1의 4번째 노드에 List2의 iter2 노드 하나를 잘라 넣음.
                                        // iter1이 가리키는 노드는 삽입된 노드 뒤로 이동.
    cout << endl;


    cout << "List 1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

    cout << "List 2: ";

    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    iter2 = List2.begin();
    iter2++;        // 200
    iter2++;        // 400


    cout << endl;
    cout << "List1의 3번째 노드에 List2의 [iter2, List.end()) 순차열 구간을 잘라 붙임" << endl;
    List1.splice(iter1, List2, iter2, List2.end());  // List1의 3번째 노드에 List2의 [iter2, List.end()) 순차열 구간을 잘라 붙임.
                                                     // iter1이 가리키는 노드는 [iter2, List.end()) 순차열 노드들 뒤로 이동.
    cout << endl;

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