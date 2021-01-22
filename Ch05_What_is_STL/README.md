# What is STL
## 📝 목차
- [STL이란]()
- [STL을 한눈에]()
- [연습문제]()
___
## ✔ STL이란
- STL은 표준 C++ 라이브러리의 일부분으로 Standard Template Library의 약자이다.

- STL은 프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공한다.

- 또한, 자료구조와 알고리즘을 서로 반복자라는 구성 요소를 통해 연결한다.

- STL의 주요한 세가지 특성은 다음과 같다.
  - 효율성 
  - 일반화 프로그램(재사용성) 
  - 확장성

- STL의 구성요소는 다음과 같다.
  - 컨테이너
  - 반복자
  - 알고리즘
  - 함수 객체
  - 어댑터
  - 할당기 

##### 컨테이너
- 컨테이너는 같은 타입의 데이터를 저장, 관리할 목적으로 만들어진 클래스다.

- 컨테이너 종류는 성능이나 메모리 사용, 지원 인터페이스(알고리즘, 멤버 함수)등에 
큰 차이를 보이며, 컨테이너의 종류는 아래와 같다.

  - **표준 시퀀스 컨테이너:** 컨테이너 원소가 자신만의 삽입 위치(순서)를 가지는 컨테이너. 
    - `vector`, `deque`, `list`
  - **표준 연관 컨테이너:** 저장 원소가 삽입 순서와 다르게 특정 정렬 기준에 의해 자동 정렬되는 컨테이너.
    - `set`, `multiset`, `map`, `multimap`
 
- 컨테이너는 데이터를 하나의 연속한 메모리 단위로 저장하느냐에 따라 두 가지로 나눈다.
  - **배열 기반 컨테이너:** 데이터 여러 개가 하나의 메모리 단위에 저장.
    - `vector`, `deque`
  - **노드 기반 컨테이너:** 데이터 하나를 하나의 메모리 단위에 저장.
    - `list`, `set`, `multiset`, `map`, `multimap`

> vector 컨테이너 사용 예시(`ex05_01.cpp`)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int 타입(정수)을 저장하는 컨테이너 v를 생성
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (unsigned int i = 0; i < v.size(); ++i)
        cout << v[i] << endl; 
}
```
> 출력 결과
```
10
20
30
40
50
```
- `vector`는 시퀀스 컨테이너이므로 추가한 순서대로 출력된다.
- `vector`는 배열 기반 컨테이너므로 `[]` 연산자로 저장 원소에 접근 할 수 있다.

##### 반복자













___
## 🏷 출처
- 본 프로젝트는 개인 학습을 목적으로 공동환 저자의 [뇌를 자극하는 C++ STL](한빛 미디어) 교재 내용을 요약 및 일부 수정하여 작성하였습니다.
- 본 프로젝트의 내용과 코드에 대한 저작권은 공동환과 한빛미디어(주)에 있으며, 한빛미디어(주)로 부터 허가를 받고 게시하였음을 밝힙니다.
- [도서 소개보기](https://www.hanbit.co.kr/store/books/look.php?p_code=B5912645820)

[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___