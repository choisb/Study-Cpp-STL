// list는 정렬을 위한 멤버 함수 sort()를 제공
// 정렬을 수행할 수 있는 컨테이너는 시퀀스 컨테이너들(vector, deque, list)
// vector와 deque는 임의접근 반복자가 있기 때문에 알고리즘의 sort()를 사용해서 빠르게 정렬 가능.
// 리스트는 양방향 반복자이기 때문에 알고리즘의 sort()를 사용할 수 없다.
// 따라서 자체적인 sort()함수 제공.
// 조건자를 사용해서 사용자가 정렬의 기준을 결정할 수도 있다.
// 여기서는 함수객체 사용.


#include <iostream>
#include <list>
using namespace std;
struct Greater
{
    bool operator () (int left, int right) const
    {
        return left > right;
    }
};

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

    cout << "sort();" << endl;

    List1.sort();       //list<int>::sort() list에서 제공해주는 기본 sort사용
    cout << "List1: ";
    for (auto l : List1)
        cout << l << " ";
    cout << endl;

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

    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    cout << "sort(std::less<int>());" << endl;
    List2.sort(less<int>());    //std::less<int> 조건자를 이용해서 원소 정렬
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    cout << "sort(Greater());" << endl;
    List2.sort(Greater());      // 사용자 정의 함수객체 Greater() 조건자를 이용해 원소 정렬
    cout << "List2: ";
    for (auto l : List2)
        cout << l << " ";
    cout << endl;

    return 0;
}