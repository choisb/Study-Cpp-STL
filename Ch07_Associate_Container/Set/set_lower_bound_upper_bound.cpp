// set의 lower_bound() / upper_bound() 예제
// lower_bound()와 upper_bound()는 찾은 key를 순차열 구간으로 반환하는 멤버 함수
// 사실 중복 key를 갖지 않는 set에서 두 멤버 함수는 큰 의미가 있지는 않음.

// lower_bound()는 찾은 원소의 시작 반복자를 반환
// upper_bound()는 찾은 원소의 다음 원소를 반환
// 찾는 원소없다면 두 반환값은 서로 같은 반복자를 반환함. 
// 이를 활용해서 탐색 실패여부를 판단 할 수 있다.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // 정수 원소를 저장하는 기본 정렬 기준이 lsee인 빈칸 컨테이너 생성

    Set.insert(50);
    Set.insert(10);
    Set.insert(30);
    Set.insert(20);
    Set.insert(40);
    Set.insert(60);
    Set.insert(80);
    Set.insert(70);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    auto iter_lower = Set.lower_bound(30);
    auto iter_upper = Set.upper_bound(30);


    if (iter_lower != iter_upper)
        cout << "30이 Set에 있음!" << endl;
    else
        cout << "30이 Set에 없음!" << endl;

    cout << "iter_lower: " << *iter_lower << endl;
    cout << "iter_upper: " << *iter_upper << endl;


    iter_lower = Set.lower_bound(55);
    iter_upper = Set.upper_bound(55);
    
    if (iter_lower != iter_upper)
        cout << "55가 Set에 있음!" << endl;
    else {
        cout << "55가 Set에 없음!" << endl;
    }

    cout << "iter_lower: " << *iter_lower << endl;
    cout << "iter_upper: " << *iter_upper << endl;

    return 0;
}
// [출력 결과]
// 10 20 30 40 50 60 70 80
// 30이 Set에 있음!
// iter_lower: 30
// iter_upper : 40
// 55가 Set에 없음!
// iter_lower : 60
// iter_upper : 60