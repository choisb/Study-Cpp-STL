// set의 equal_range() 예제
// equal_range()는 lower_bound() / upper_bound() 반복자 쌍을 하나의 pair객체로 반환한다.

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

    auto iter_pair = Set.equal_range(30);
    cout << "*iter_pair.first: " << *iter_pair.first << endl;
    cout << "*iter_pair.second: " << *iter_pair.second << endl;

    iter_pair = Set.equal_range(55);
    if (iter_pair.first != iter_pair.second)
        cout << "55가 Set에 있음!" << endl;
    else
        cout << "55가 Set에 없음!" << endl;

    cout << "*iter_pair.first: " << *iter_pair.first << endl;
    cout << "*iter_pair.second: " << *iter_pair.second << endl;
    return 0;
}
// [출력 결과]
// 10 20 30 40 50 60 70 80
// * iter_pair.first: 30
// * iter_pair.second : 40
// 55가 Set에 없음!
// *iter_pair.first : 60
// * iter_pair.second : 60