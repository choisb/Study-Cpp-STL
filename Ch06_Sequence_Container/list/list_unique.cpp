// list의 unique() 예제
// unique() 함수는 인접한 원소를 유일하게 만든다.
// 모든 원소를 유일하게 만들기 위해서는 sort후 unique()를 사용한다.


#include <iostream>
#include <list>
using namespace std;

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

    List1.unique();
    cout << "unique();" << endl;

    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;


    list<int> List2;

    List2.push_back(10);
    List2.push_back(40);
    List2.push_back(40);
    List2.push_back(40);
    List2.push_back(30);
    List2.push_back(20);
    List2.push_back(20);
    List2.push_back(20);
    List2.push_back(40);
    List2.push_back(20);
    List2.push_back(50);
    List2.push_back(40);
    List2.push_back(60);

    cout << endl;
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    List2.sort();
    cout << "sort();" << endl;


    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    List2.unique();
    cout << "unique();" << endl;


    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;
    return 0;

}