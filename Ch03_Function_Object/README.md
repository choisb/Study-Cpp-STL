# Function Object
## 📝 목차
- [함수 객체란](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#-함수-객체란)
- [함수 객체의 사용법](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#-함수-객체의-사용법)
- [함수 객체의 구현](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#-함수-객체의-구현)
- [연습문제](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#-연습문제)
___

## ✔ 함수 객체란
##### 함수 객체란
- 함수 객체(Function Object)는 함수 처럼 동작하는 객체이다.
- 객체가 함수 처럼 동작 하기 위해서는 `()`연산자를 오버로딩 해야한다.
- 함수 객체는 함수처럼 사용할 수 있으면서도 상태를 가질 수 있기 때문에 STL에서 함수보다 함수객체를 더 선호한다.


##### 함수 객체의 장점
- 함수 객체는 **객체**이므로 멤버 변수와 멤버 함수를 가질 수 있다.
- 함수 객체의 **서명**(반환 타입, 매개변수)이 같더라도 객체 타입이 다르면 서로 전혀 다른 타입으로 인식.
- 함수 객체는 **인라인**될 수 있고, 컴파일러가 쉽게 최적화 할 수 있어서 일반 함수보다 빠르다. 

[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#function-object) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 함수 객체의 사용법

##### 함수 객체의 예제
- 함수 객체는 아래의 예시처럼 사용 할 수 있다.
- `Add`는 객체지만 마치 함수인것 처럼 호출 할 수 있다.
- 함수 객체도 일반 함수처럼 **매개변수 리스트**도 가질 수 있다.
- **멤버 변수** `total`은 초깃값 `0`을 시작으로 `add()` 함수를 호출 할 때마다 정수를 누적하고 반환한다.
- `operator()(int n)` 함수는 클래스 내부에 정의되므로 **암묵적으로 인라인** 함수다.
- `operator()(int n)` 와 **서명**이 같더라도 **타입이 다른** 함수 객체는 `Adder` 클래스 객체에 대입하거나 복사 할 수 없다.

> 함수객체 예제[(`ex03_01.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch03_Function_Object/ex03_01.cpp)
```cpp
#include <iostream>
using namespace std;

class Adder
{
    int total;
public:
    explicit Adder(int n = 0) : total(n) { }
    int operator() (int n)  // 암묵적으로 인라인 함수로 적용됨
    {
        return total += n;
    }
};
int main()
{
    Adder add(0); // total의 초깃값 0
    
    cout << add(10) << endl;    //  add.total: 10
    cout << add(20) << endl;    //  add.total: 30
    cout << add(30) << endl;    //  add.total: 60

    return 0;
}
```
> 출력 결과
```
10
30
60
```
##### 함수 객체를 사용한 콜백 함수 구현
- 아래와 같이 함수 객체는 일반 함수 처럼 **콜백(Callback)함수** 구현에도 사용할 수 있다.
  - `for_each()` 알고리즘의 세 번째 인자에 함수 포인터가 아닌 함수 객체를 전달한 모습을 볼 수 있다.
> 콜백함수 예시 [(`ex03_02.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch03_Function_Object/ex03_02.cpp)
```cpp
#include <iostream>
#include <algorithm>  // for_each() 알고리즘(서버)을 사용하기 위한 헤더
using namespace std;

///// 클라이언트 /////
struct Functor1
{
    Functor1() { cout << "Functor1() 호출 " << endl; }
    void operator() (int n) // 공백을 이용해 원소 출력
    {
        cout << n << " ";
    }
};

struct Functor2
{
    Functor2() { cout << "Functor2() 호출 " << endl; }
    void operator() (int n) // 각 원소를 제곱해서 출력
    {
        cout << n * n << " ";
    }
};

struct Functor3
{
    Functor3() { cout << "Functor3() 호출 " << endl; }
    void operator() (int n) // 문자열과 endl을 이용해 원소 출력
    {
        cout << "정수 : " << n << endl;
    }
};

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };

    for_each(arr, arr + 5, Functor1());
    // 임시 함수 객체(Functor1())를 만들어 함수로 전달

    cout << endl << endl;
    for_each(arr, arr + 5, Functor2());
    // 임시 함수 객체(Functor2())를 만들어 함수로 전달

    cout << endl << endl;
    for_each(arr, arr + 5, Functor3());
    // 임시 함수 객체(Functor3())를 만들어 함수로 전달
}
```
> 출력 결과
```
Functor1() 호출
10 20 30 40 50

Functor2() 호출
100 400 900 1600 2500

Functor3() 호출
정수 : 10
정수 : 20
정수 : 30
정수 : 40
정수 : 50
```
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#function-object) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 함수 객체의 구현
- STL에서 함수 객체는 곳곳에 사용되며 중요한 역할을 하고있음을 기억하자.
- 여기에서는 예시로 STL에 구현되어 있는 less 함수객체의 기능 일부를 구현해보고 넘어가도록 한다.

##### STL의 less 객체
>STL의 less 객체 사용[(`ex03_03.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch03_Function_Object/ex03_03.cpp)
```cpp
#include <iostream>
#include <functional> // less<> 헤더
using namespace std;

typedef less<int> Less; // 템플릿으로 구현된 less<> 객체를 int 타입으로 사용

int main()
{
    Less l;

    cout << l(10, 20) << endl; // l 객체로 암시적 함수 호출
    cout << l(20, 10) << endl; // l 객체로 암시적 함수 호출
    cout << l.operator()(10, 20) << endl; // l 객체로 명시적 함수 호출
    cout << endl;

    cout << Less()(10, 20) << endl; // 임시 객체로 암시적 함수 호출
    cout << Less()(20, 10) << endl; // 임시 객체로 암시적 함수 호출
    cout << Less().operator()(10, 20) << endl; // 임시 객체로 명시적 함수 호출

    return 0;
}
```

##### 직접 구현한 less 객체
>less 구현[(`ex03_04.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch03_Function_Object/ex03_04.cpp)
```cpp
#include <iostream>
using namespace std;

bool Pred_less(int a, int b)
{
    return a < b;
}
struct Less
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Less l;

    cout << Pred_less(10, 20) << endl;
    cout << Pred_less(20, 10) << endl;
    cout << endl;

    cout << l(10, 20) << endl;      // l 객체로 암묵적 함수 호출
    cout << l(20, 10) << endl;      // l 객체로 암묵적 함수 호출
    cout << Less()(10, 20) << endl; // 임시 객체로 암묵적 호출
    cout << Less()(20, 10) << endl; // 임시 객체로 암묵적 호출
    cout << endl;

    cout << l.operator()(10, 20) << endl;       // 명시적 호출
    cout << Less().operator() (10, 20) << endl; // 명시적 호출

    return 0;
}
```
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#function-object) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 연습문제
##### 1. 다음 빈 칸을 채우세요.
- 함수처럼 호출 가능한 클래스 객체를 가리켜(✏함수 객체)라 합니다.
- 함수처럼 호출 가능한 클래스 객체는  (✏`()`)연산자를 오버로딩해 생성합니다.

##### 2. 다음 Equal 클래스의 객체가 cmp일 때 두 정사가 같으면 true, 아니면 false를 반환하는 Equal 클래스를 작성하세요. 
> 문제
```cpp
if(cmp(10, 20))
    cout << "같다!" << endl;
else
    cout << "다르다!" << endl;
```
> 답
```cpp
class Equal{
public:
    bool operator()(int left, int right)
    {
        if(left == right)
            return true;
        else
            return false;
    }
};
```
 ##### 🚩 오답 노트  
- 멤버 함수 내에서 멤버 변수를 변경하지 않는다면 반드시 `const` 함수로 선언할 것.
- `==` 연산자는 그 자체로도 `true`, `false`를 반환하기 때문에 별도의 `if`문 필요 없다.
> 정답
```cpp
class Equal{
public:
    bool operator()(int left, int right) const
    {
        return left == right;
    }
};
```
##### 3. 다음 Adder 클래스의 객체가 add일 때 두 정수의 합을 반환하는 Adder 클래스를 작성하세요.
> 문제
```cpp
int sum = add(10, 20);
cout << "sum= " << sum << endl;
```

> 정답
```cpp
class Adder{
public:
    itn operator()(int left, int right) const // const함수로 선언할 것
    {
        return left + right;
    }
};
```
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#function-object) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]

___
## 🏷 출처
- 본 프로젝트는 개인 학습을 목적으로 공동환 저자의 [뇌를 자극하는 C++ STL](한빛 미디어) 교재 내용을 요약 및 일부 수정하여 작성하였습니다.
- 본 프로젝트의 내용과 코드에 대한 저작권은 공동환과 한빛미디어(주)에 있으며, 한빛미디어(주)로 부터 허가를 받고 게시하였음을 밝힙니다.
- [도서 소개보기](https://www.hanbit.co.kr/store/books/look.php?p_code=B5912645820)

[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#function-object) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___