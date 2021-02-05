// set의 insert() 사용방법.
// set 컨테이너는 원소(key)를 제공하는 유일한 멤버 함수 insert()를 제공한다.
// 정렬 기준이 있으므로 insert()에 의해 삽입된 원소는 자동 정렬된다. default: less 조건자
// 모든 원소(key)는 유일하다. 만약 원소의 중복을 허용해야 한다면 multiset을 사용해야.
// insert()의 반환 값은 pair<set<T>::iterator, bool>으로 insert의 결과를 저장한다.
// 반환된 pair의 second 값은 삽입 성공, 실패의 결과를 담고 있다. 값이 중복될 경우 원소를 삽입하지 않고 false를 반환한다.
// second가 true일 경우 first에는 삽입한 원소를 가리키는 반복자이며,
// second가 false일 경우 이미 삽입된 원소를 가리키는 반복자가 반환된다.
// insert() 멤버 함수를 이용한 삽입은 로그 시간 복잡도를 가진다. 


#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // 정수 원소를 저장하는 기본 정렬 기준이 lsee인 빈칸 컨테이너 생성

    // pair<set<int>::iterator, bool> pr;

    auto pr = Set.insert(50); // 원소(key) 삽입
    if (pr.second == true)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
    {
        cout << *pr.first << " 이(가) 이미 있습니다. 삽입 실패!" << endl;
    }

    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);
    Set.insert(110);
    Set.insert(100);

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    pr = Set.insert(50); // 중복된 원소 삽입. 실패!

    if (pr.second == true)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
    {
        cout << *pr.first << " 이(가) 이미 있습니다. 삽입 실패!" << endl;
    }


    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;

}