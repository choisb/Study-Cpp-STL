// set의 count() 예제
// count() 는 set 컨테이너에 해당 원소가 몇개인지를 반환한다.
// 중복을 허용하지 않는 set 컨테이너에서는 count()는 필요하지는 않지만, 
// 모든 연관 컨테이너의 인터페이스가 같으므로 set도 count()를 제공
// 실행 시간은 로그 시간 복잡도이다.

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

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    cout << "원소 50의 개수: " << Set.count(50) << endl;    // 원소 50의 개수
    cout << "원소 100의 개수: " << Set.count(100) << endl;   // 원소 100의 개수

    return 0;
}
// [출력 결과]
// 10 20 30 40 50
// 원소 50의 개수 : 1
// 원소 100의 개수 : 0