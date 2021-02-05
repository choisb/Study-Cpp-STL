// multiset의 insert() 예제
// multiset과 set은 원소가 중복가능 여부 만 다르고 모든 인터페이스는 동일하게 사용할 수 있다.
// 다만 몇 가지의 차이점이 존재한다.
// insert의 경우 set에서는 원소 중복으로 인해서 삽입이 실패했을 경우 pair객체의 두번재 값으로 실패를 반환했다.
// 하지만 multiset의 경우에는 저장한 원소의 위치를 가리키는 반복자가 반환된다.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> Multiset;

    Multiset.insert(50);
    Multiset.insert(30);
    Multiset.insert(80);
    Multiset.insert(80);    // 중복
    Multiset.insert(30);    // 중복
    Multiset.insert(70);
    Multiset.insert(10);
    auto iter = Multiset.insert(30);

    cout << "iter의 원소: " << *iter << endl;

    for (auto ms : Multiset)
    {
        cout << ms << " ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// iter의 원소 : 30
// 10 30 30 30 50 70 80 80