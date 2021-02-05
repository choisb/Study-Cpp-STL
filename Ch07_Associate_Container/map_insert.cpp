// map의 insert() 예제
// map은 key와 value쌍(pair객체)를 저장한다.
// key는 컨테이너에 중복 저장될 수 없다. 중복 저장은 multimap을 사용
// map의 insert()는 set의 insert()와 다르게 pair 객체를 인자로 받아 저장한다.

// map의 insert()함수의 반환값은 set의 insert()함수 처럼 데이터 삽입의 성공여부(pair 객체)이다.
// 반환된 pair객체의 first: (성공시) 저장 원소의 위치를 가리키는 반복자 / (실패시) 이미 저장되어있는 key의 위치를 가리키는 반복자
// 반환된 pair객체의 second: (성공시) true / (실패시) false

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // key, value 모두 정수형인 컨테이너 생성
    // 기본 정렬 기준 less
    map<int, int> Map;

    Map.insert(pair<int, int>(5, 100));    // 임시 pair 객체 생성 후 저장
    Map.insert(pair<int, int>(2, 100));
    Map.insert(pair<int, int>(8, 300));
    Map.insert(pair<int, int>(3, 400));
    Map.insert(pair<int, int>(1, 200));
    Map.insert(pair<int, int>(7, 400));

    pair<int, int> pr(9, 50);
    Map.insert(pr); // pair 객체 생성 후 저장

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // insert()의 반환값 확인

    auto rt = Map.insert(pair<int, int>(4, 500));


    if (rt.second == true)
        cout << rt.first->first << " 이(가) 정상적으로 저장됨!" << endl;
    else
        cout << rt.first->first << " 이(가) 중복되어서 저장 실패!" << endl;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    rt = Map.insert(pair<int, int>(4, 500));

    if (rt.second == true)
        cout << rt.first->first << " 이(가) 정상적으로 저장됨!" << endl;
    else
        cout << rt.first->first << " 이(가) 중복되어서 저장 실패!" << endl;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// (1, 200) (2, 100) (3, 400) (5, 100) (7, 400) (8, 300) (9, 50)
// 4 이(가) 정상적으로 저장됨!
// (1, 200) (2, 100) (3, 400) (4, 500) (5, 100) (7, 400) (8, 300) (9, 50)
// 4 이(가) 중복되어서 저장 실패!
// (1, 200) (2, 100) (3, 400) (4, 500) (5, 100) (7, 400) (8, 300) (9, 50)