// list의 remove_if() 예제
// 조건자는 bool 형식을 반환하는 함수류(함수, 함수 객체, 함수 포인터)를 사용할 수 있다.


#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)  // 단항 조건자
{
    return 10 <= n && n <= 30;
}

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

    List.remove_if(Predicate);    // 10 ~ 30 의 원소 삭제

    for (auto l : List)
        cout << l << " ";
    cout << endl;

    return 0;

}