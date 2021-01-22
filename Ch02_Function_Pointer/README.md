# Function Pointer
### 목차📝
- 함수 포인터란
- 함수 포인터의 종류
- 클라이언트 코드와 서버 코드
- ❗이것만은 알고 갑시다

___

## 함수 포인터란
- 함수의 시작 주소를 저장하는 변수.
- STL 알고리즘이 사용자 정책 함수인 클라이언트 코드를 호출하는 개념이나, 
STL 어댑터인 함수 포인터 어댑터, 멤버 함수 포인터 어댑터 등을 이해하는데 도움이됨.
- 함수 포인터는 참조대상이 되는 함수의 **반환 타입**과 **매개변수 리스트**를 같게 선언.

**함수포인터 사용 예제**
> ex02_01.cpp
```cpp
#include <iostream>
using namespace std;

void Print(int n)
{
    cout << "정수: " << n << endl;
}

int main()
{
    // void Print(int n)의 함수 포인터 선언
    void(*pf) (int);
    // 함수의 이름은 함수의 시작 주소
    pf = Print;
    
    Print(10);	// 1. 함수 호출
    pf(10);     // 2. 함수 포인터를 이용한 함수 호출, 첫 번째 방법
    (*pf)(10);	// 3. 함수 포인터를 이용한 함수 호출, 두 번째 방법
    
    cout << endl;
    cout << Print << endl;
    cout << pf << endl;
    cout << *pf << endl;
    
    return 0;
}
```
> 출력 결과
```
정수: 10
정수: 10
정수: 10

00FD113B
00FD113B
00FD113B
```
- 출력 결과에서 `OOFD113B`는 `Print()`함수의 시작 주소
- 함수 포인터 `pf`의 시그너처(반환타입과 매개변수)는 참조하는 `Print()`와 동일하게 선언. `void(*pf) (int);`
- 함수 포인터는 메모리 접근 연산자`*`를 붙여도 그대로 함수의 주소. (`pf()`와 `(*pf)()` 은 같은 문장 )

___
## 함수 포인터의 종류
**C++에서 함수의 종류**
- 정적 함수
  - 전역 함수
  - `namespace` 내의 전역 함수
  - `static` 멤버 함수
- 멤버 함수
  - 객체로 접근 (`.`)
  - 주소로 접근 (`->`)

**함수 호출 방법 세 가지**
- 정적 함수 호출(정적 함수)
- 객체로 멤버 함수 호출(멤버 함수)
- 객체의 주소로 멤버 함수 호출(멤버 함수)

### 정적 함수 호출
- 정적 함수인 전역 함수 / `namespace` 내의 전역함수 / `static`멤버 함수는 함수 호출 규약이 같아서 각각 함수 시그너처만 알면 쉽게 선언 가능.

**정적 함수 호출 예시**
> ex02_02.cpp
```cpp
#include <iostream>
using namespace std;

void Print(int n)
{
    cout << "전역 함수: " << n << endl;
}

namespace A
{
    void Print(int n)
    {
        cout << "namespace A 전역 함수: " << n << endl;
    }
}

class Point
{
public:
    static void Print(int n)
    {
        cout << "Point 클래스의 정적 멤버 함수: " << n << endl;
    }
};

int main()
{
    void(*pf) (int);	// 정적 함수 포인터 선언

    Print(10);          // 1. namespace 없는 전역 함수 호출
    A::Print(10);       // 2. namespace A의 전역 함수 호출
    Point::Print(10);   // 3. Point 클래스의 정적 멤버 함수 호출

    pf = Print;			
    pf(10);             // 1. 함수 포인터로 namespace 없는 전역 함수 호출
    pf = A::Print;
    pf(10);             // 2. 함수 포인터로 namespace A의 전역 함수 호출
    pf = Point::Print;
    pf(10);             // 3. 함수 포인터로 Point 클래스의 정적 멤버 함수 호출

    return 0;
}
```
> 출력 결과
```
전역 함수: 10
namespace A 전역 함수: 10
Point 클래스의 정적 멤버 함수: 10
전역 함수: 10
namespace A 전역 함수: 10
Point 클래스의 정적 멤버 함수: 10
```

### 객체와 주소로 멤버 함수 호출
**선언 및 호출 방법**
- 함수 포인터 선언에 어떤 클래스의 멤버 함수를 가리킬 것인지 클래스 이름을 지정.
  - `void(Point::*pf)(int)`처럼 선언.
- 객체로 멤버 함수 호출 시에는 `.*` 연산자를 이용.
- 주소로 멤버 함수 호출 시에는 `->*` 연산자를 이용.
- 함수 호출 시 연산자 우선순위로 `.*`, `->*`연산 시 `()` 반드시 사용.

>ex02_03.cpp
```cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const { cout << x << ',' << y << endl; }
    void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
};

int main()
{
    Point pt(2, 3);
    Point *p = &pt;

    void (Point::*pf1)() const;	// 멤버 함수 포인터 선언
    pf1 = &Point::Print;

    void (Point::*pf2)(int);	// 멤버 함수 포인터 선언
    pf2 = &Point::PrintInt;

    pt.Print();
    pt.PrintInt(10);
    cout << endl;

    (pt.*pf1)();		// 객체로 멤버 함수 포인터를 이용한 호출
    (pt.*pf2)(10);		// 객체로 멤버 함수 포인터를 이용한 호출
    cout << endl;

    (p->*pf1)();		// 주소로 멤버 함수 포인터를 이용한 호출
    (p->*pf2)(10);		// 주소로 멤버 함수 포인터를 이용한 호출

    return 0;
}
```
> 출력 결과
```
2,3
테스트 정수 : 10

2,3
테스트 정수 : 10

2,3
테스트 정수 : 10
```
___
## 클라이언트 코드와 서버 코드
**콜백(Callback)이란?**
- 어떤 기능이나 서비스를 제공하는 코드를 **서버** / 기능을 제공받는 코드 측을 **클라이언트**라 함.
- 일반적으로 서버는 하나지만 서버 코드를 사용하는 클라이언트는 여러개 이다.
- 일반적으로 클라이언트 코드 측에서 서버를 호출하고 기능을 제공받음. `콜(Call)`
- 때로는 서버가 클라이언트를 할 수도 있음. 이를 `콜백(Callback)`이라함.
- 콜백 메커니즘을 이용하면 알고리즘 정책을 클라이언트에서 유연하게 바꿀 수 있고, 서버를 더욱 추상화 할 수 있음.
- 대부분 GUI의 강력한 이벤트 기능도 콜백 메커니즘으로 구현.
- STL의 많은 알고리즘도 콜백을 사용.
- 윈도우의 모든 프로시저는 시스템이 호출하는 '콜백 함수'.

**간단한 콜백 매커니즘**
```cpp
...
///////// 서버 /////////
void PrintHello()
{
    cout << "Hello!" << endl;
    Client(); // 서버에서 클라이언트 코드 호출
}

///////// 클라이언트 /////////
void Client()
{
    cout << "난 Client" << endl;
}

int main()
{
    PrintHello(); // 서버 코드 호출
    return 0;
}
```
> 출력 결과
```
Hello!
난 Client
```
- `PrintHello()`함수인 서버에서 클라이언트 측 코드인 `Client()` 함수를 호출.
- 이때 Client()함수를 `콜백 함수`라 한다. 
- 실제로 서버 코드는 이렇게 구현할 수 없다.
  - 서버는 여러 클라이언트에 의해 호출 되며.
  - 서버는 클라이언트의 존재를 미리 알지 못함.
  - 즉, **서버가 미리 `Client()` 함수를 알고 호출하는 것**은 불가능!
 
 **함수 포인터를 이용한 콜백 메커니즘 구현**
>ex02_04
```cpp
#include <iostream>
using namespace std;

///////// 서버 /////////
// 배열의 모든 원소에 반복적인 작업을 수행하게 추상화됨(구체적인 작업은 없음)
void For_each(int *begin, int *end, void(*pf)(int))
{
    while (begin != end)
    {
        pf(*begin++); // 클라이언트 함수 호출(콜백)
    }
}
///////// 클라이언트 /////////
void Print1(int n)	// 공백을 이용해 원소를 출력
{
    cout << n << ' ';
}

void Print2(int n)	// 각 원소를 제곱해 출력
{
    cout << n * n << " ";
}
void Print3(int n)	// 문자열과 endl을 이용해 원소를 출력
{
    cout << "정수 : " << n << endl;
}

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    For_each(arr, arr + 5, Print1); // Print1 () 콜백 함수의 주소를 전달
    cout << endl << endl;
    For_each(arr, arr + 5, Print2); // Print2 () 콜백 함수의 주소를 전달
    cout << endl << endl;
    For_each(arr, arr + 5, Print3); // Print3 () 콜백 함수의 주소를 전달

    return 0;
}
```
> 출력 결과
```
10 20 30 40 50

100 400 900 1600 2500

정수 : 10
정수 : 20
정수 : 30
정수 : 40
정수 : 50
```

- 서버는 배열의 원소에 대해 반복적인 작업을 수행할 뿐 구체적인 작업은 알지 못함.
- 구체적인 작업은 클라이언트에서 콜백 함수 `Print1()`, `Print2()`, `Print3()`를 이용해 수행함.
- 클라이언트는 서버 함수 For_each()를 세 번 호출하지만, 세번의 출력 결과는 클라이언트에 의해 결정.

___
## 이것만은 알고 갑시다. 💯

##### 1. 다음은 `Print()`의 주소를 저장하는 함수 포인터 정의입니다. 빈 칸을 채우세요.
```cpp
void Print(int data) { ... }
```
- `Print()` 함수가 정적 함수나 전역 함수라면 함수 포인터는 ( ✏`void (*pf)(int)` )와 같이 선언 합니다.
- `Print()` 함수가 `MyClass` 클래스의 멤버 함수라면 함수 포인터는 ( ✏`void (MyClass::*pf)(int)`)와 같이 선언 합니다.
- 함수 포인터 `pf`가 전역 함수 `Print()`의 주소라면 ( ✏ `pf(int)` or `(*pf)(int)` )처럼 전역 함수를 호출합니다.
- 함수 포인터 `pf`가 `MyClass` 클래스의 멤버 함수 `Print()`의 주소고, 객체가 `obj`라면 ( ✏ `(obj.*pf)(int)` )처럼 멤버 함수를 호출합니다.
 
##### 2. 다음 빈 칸을 채우세요.
- 서버는 클라이언트의 정책을 반영하려고 서버 측 코드에서 클라이언트 측 함수를 호출합니다. 이때 서버가 호출하는 클라이언트 함수를 가리켜 ( ✏ 콜백(Callback) )함수라 합니다.

___
## 출처
- 본 프로젝트는 개인 학습을 목적으로 공동환 저자의 [뇌를 자극하는 C++ STL](한빛 미디어) 교재 내용을 요약 및 일부 수정하여 작성하였습니다.
- 본 프로젝트의 내용과 코드에 대한 저작권은 공동환과 한빛미디어(주)에 있으며, 한빛미디어(주)로 부터 허가를 받고 게시하였음을 밝힙니다.
- [도서 소개보기](https://www.hanbit.co.kr/store/books/look.php?p_code=B5912645820)

___  