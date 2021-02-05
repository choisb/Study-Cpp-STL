// set의 find() 예제
// find()는 key(원소)를 검색하여 key를 가리키는 반복자를 반환.
// key가 없으면 끝 표시 반복자를 반환
// 때문에 find() 함수의 반환값을 end() 함수와 비교해 검색이 성공했는지 실패했는지 판단
// [주의]
// find()함수에서 원소를 탐색할때 "==" 연산자가 아닌 조건자를 활용한 탐색을 한다.
// 즉, !(a<b) && !(b>a) 인 경우는 같은 것이라고 간주하고 탐색을 한다.
// !s.key_comp()(a,b) && !s.key_comp()(b,a) 인경우 두 원소는 같은 것으로 간주.

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

    auto iter = Set.find(50);
    if (iter != Set.end())  // 찾는 원소 50이 존재하기 때문에 find(50)는 해당 값의 반복자 반환
        cout << *iter << "이(가) Set에 있다!" << endl;
    else
    {
        cout << " 50이 Set에 없다!" << endl;
    }

    return 0;
}
// [출력 결과]
// 10 20 30 40 50 60 70 80
// 50이(가) Set에 있다!