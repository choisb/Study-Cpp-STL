// set의 조건자를 greater로 바꾸는 예제

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int, greater<int>> Set; // 정수 원소를 저장하는 기본 정렬 기준을 greater 조건자로 바꾼 컨테이너 생성


    Set.insert(50); // 원소(key) 삽입
    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// 90 80 70 50 30 20 10

