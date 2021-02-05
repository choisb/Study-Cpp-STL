// set의 insert() 다양한 버전 존재
// 삽입할 구간의 쌍을 지정하는 버전의 insert()제공
// 삽입할 위치를 지정하는 버전 제공
// 만약 삽입 위치가 정렬순서와 맞다면 바로 삽입되지만 아니라면 로그 시간이 걸린다.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> Set; // 정수 원소를 저장하는 기본 정렬 기준이 lsee인 빈칸 컨테이너 생성

    // pair<set<int>::iterator, bool> pr;

    Set.insert(50); // 원소(key) 삽입
    Set.insert(30);
    Set.insert(80);
    Set.insert(70);
    Set.insert(10);
    Set.insert(20);
    Set.insert(20);
    Set.insert(90);
    auto pr = Set.insert(100);
    
    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;

    Set.insert(pr.first, 95);   // 100 원소의 반복자에서 검색 시작 후 빠르게 삽입

    for (auto s : Set)
    {
        cout << s << " ";
    }
    cout << endl;


    return 0;

}