# 연산자 오버로딩
### 목차📝
- 연산자 오버로딩이란
  - 연산자 오버로딩 정의 및 사용하기
  - 단항 연산자 오버로딩
  - 이항 연산자 오버로딩
- 전역 함수를 이용한 연산자 오버로딩
  - 멤버 함수를 이용한 연산자 오버로딩
  - 전역 함수를 이용한 연산자 오버로딩
- STL에 필요한 주요 연산자 오버로딩
  - 함수 호출 연산자 오버로딩(`()` 연산자)
  - 배열 인덱스 연산자 오버로딩(`[]` 연산자)
  - 메모리 접근, 클래스 멤버 접근 연산자 오버로딩(`*`, `->` 연산자)
- 타입 변환 연산자 오버로딩
  - 생성자를 이용한 타입 변환
  - 타입 변환 연산자 오버로딩을 이용한 타입 변환
- ❗이것만은 알고 갑시다

___
## 연산자 오버로딩이란
- C++에서 제공하는 기본 타입이 아닌 클래스 타입에도 연산자를 사용할 수 있게 하는 문법.
- 연산자 오버로딩은 많은 STL 구성 요소에 사용돼 쉽고 더 직관적이며 일반화된 코드를 만들어 낸다.

```cpp
int n1 = 10;
int n2 = 20;

cout << n1 + n2 << endl; // 컴파일러에 의해서 정의되어 있는 + 연산자
```

> 출력 결과  

```
30
```

위의 코드에서 `(int)n1 + (int)n2`은 `int`타입에 대한 `+`연산이 컴파일러에 정의되어 있기 때문에 사용 가능. 
하지만 사용자가 정의한 클래스의 연산은 컴파일러 내부에 정의되어 있지 않기 때문에 사용할 수 없다.

```cpp
class Point
{
    ...
};

int main()
{
    Point p1(2, 3), p2(5, 5);
    p1 + p2; // 컴파일러에 두 객체에 대한 + 연산이 정의되어 있지 않기 때문에 에러!
    return 0; 
}
```
사용자가 정의한 클래스에 대한 연산자를 사용하기 위해서는 **연산자 오버로딩**을 통해서 사용자가 직접 정의해야 한다.



### 연산자 오버로딩 정의 및 사용하기

___
## 전역 함수를 이용한 연산자 오버로딩
연산자 오버로딩에는 다음 두가지가 존재한다.

- 멤버 함수를 이용한 연산자 오버로딩
- 전역 함수를 이용한 연산자 오버로딩  

#### 반드시 전역 함수를 이용해야하는 경우

일반적으로는 멤버함수를 이용한 연산자 오버로딩을 사용하지만, 
**멤버 함수를 이용한 연산자 오버로딩을 사용할 수 없을 경우**는 전역 함수 연산자 오버로딩을 사용함.  
  
이항 연산의 왼쪽 항이 연산자 오버로딩 객체가 아니면 멤버 함수를 이용한 연산자 오버로딩을 이용할 수 없다.
왜냐하면 연산자 멤버 함수는 항상 **이항 연산의 왼쪽 객체에서 호출**하기 때문이다.

```cpp
    Point pt1(1, 2), pt2(2, 3); 
    pt1 + pt2; // pt1.operator+(pt2) 함수를 호출
```

위와 같은 상황에서는 이항 연산의 왼쪽항인 `pt1`이 `operator+(const Point&)`를 호출하는 모습이다. 하지만 만약에 다음과 같은 상황이라면
`k`가 호출할 수 있는 적당한 연산자 함수가 없기 때문에 에러가 발생한다.
```cpp
    Point pt1(1,2);
    int k;
    k * pt1; // 에러!
```

#### 전역 함수
```cpp
class Point
{
    //operator* 함수에서 Point의 멤버변수에 접근할 수 있도록 friend 선언
    friend const Point operator*(const int argL, const Point& argR);
    ...
};

// 전역함수로 정의된 operator* 함수
const Point operator*(const int k, const Point& argR)
{
    Point pt;
    pt.x = k * argR.x;
    pt.y = k * argR.y;
    return pt;
}

...

int main(){
    Point p1(2, 3);
    Point result;

    result = 2 * p1; // operator*(2, p1) 함수 호출
    result.Print();

    return 0;
}
```
friend 함수는 캡슐화를 저해하므로 가능하면 getter, setter를 사용하는 것이 좋다.

___

## STL에 필요한 주요 연산자 오버로딩
**순서**
- 함수 호출 연산자 오버로딩(`()`연산자)
- 배열 인덱스 연산자 오버로딩(`[]` 연산자)
- 메모리 접근, 클래스 멤버 접근 연산자 오버로딩(`*`, `->` 연산자)
### 함수 호출 연산자 오버로딩(`()` 연산자)
함수 호출 연산자 오버로딩은 **객체**를 **함수**처럼 동작하게 하는 연산자이다. C++에서  `Print(10)`이라는 함수 호출 문장은 다음 세가지로 해석할 수 있다.
- 첫째, 함수 호출: Print가 함수 이름
- 둘째, 함수 포인터: Print가 함수 포인터
- 셋째, 함수 객체: Print가 함수 객체

```cpp 
struct FuncObject
{
public:
    void operator() (int arg) const
    {
        cout << " 정수 : " << arg << endl;
    }
};

void Print1(int arg)
{
    cout << " 정수 : " << arg << endl;
}
int main(){
    void(*Print2) (int) = Print1;   // 함수 포인터 Print2 선언
    FuncObject Print3;              // 함수 객체 Print3 선언

    Print1(10); // '함수'를 사용한 정수 출력
    Print2(10); // '함수 포인터'를 사용한 정수 출력
    Print3(10); // '함수 객체'를 사용한 정수 출력 (Print3.operator(10)과 같음)

    return 0;
}
```

`FuncObject` 구조체의 `void operator() (int arg) const` 연산자 함수에서 `()` 연산자에 대한 Overloading을 하였기 때문에 `Print3` 객체를 객체이지만 마치 함수인것 처럼 사용할 수 있다.
> 함수 포인터와, 함수 객체는 추후 2장 3장에서 자세하게 다룰 예정.  
 

###  배열 인덱스 연산자 오버로딩(`[]` 연산자)
배열 인덱스 연산자 오버로딩을 사용하면 배열에 사용하는 `[]`연산자를 객체에도 사용할 수 있다. `[]`연산자 오버로딩은 일반적으로 많은 객체를 저장하고 관리하는 객체에 사용됨.
> Array.h
```cpp
#include <iostream>
using namespace std;

class Array
{
    int *arr;
    int size;
    int capacity;

public:
...
    int operator[] (int idx) const // 상수값 반환
    {
        return arr[idx];
    }

    int& operator[] (int idx) // L-Value 반환
    {
        return arr[idx];
    }
};
```
> main.cpp
```cpp
#include "Array.h"

int main()
{
    Array ar(10);
    ar.Add(10);
    ar.Add(20);
    ar.Add(30);

    for (int i = 0; i < ar.Size(); i++)
        cout << ar[i] << endl; //ar.operator[](int) 호출

    const Array& ar2 = ar;  // 상수참조 ar2 선언
    ar[0] = 40;	        //ar.operator[](int) 호출
    cout << ar2[0] << endl; //ar.operator[](int) const 호출
    //ar2[0] = 100;         에러! 상수 객체(값)을 반환하기 때문에 대입할 수 없다.

    return 0;
}
```
>출력 결과
```
10
20
30
40
```

### 메모리 접근, 클래스 멤버 접근 연산자 오버로딩(`*`, `->` 연산자)
- `*`, `->` 연산자는 스마트 포인터나 반복자(iterator) 등의 특수한 객체에 사용됨
- 반복자가 STL의 핵심 구성 요소이므로 `*`, `->` 연산자 오버로딩은 아주 중요함.

>PointPtr.h
```cpp
#include "Point.h"

class PointPtr
{
    Point *ptr;
public:
    PointPtr(Point *p) : ptr(p) 
    {
        cout << "PointPtr(Point *p): ptr(p) > " << ptr << endl;
    }
    ~PointPtr()
    {
        cout << "~PointPtr(): delete ptr; > " << ptr << endl;
        delete ptr;
    }

    Point* operator->() const
    {
        cout << "operator->(): return ptr; > " << ptr << endl;
        return ptr; // Point의 주소값에 해당하는 ptr을 반환
    }
    Point& operator*() const // 반환 형식은 L-Value
    {
        cout << "operator*(): return *ptr; >" << ptr << endl;
        return *ptr;
    }
};
```
>main.cpp
```cpp
#include "PointPtr.h"

int main()
{
    Point* ptr = new Point(2,3);
    PointPtr p1 = ptr;  // 생성자를 이용한 타입 변환
                        // 바로 다음에 나오는 생성자를 이용한 타입 변환 절에서 나옴.

    //Point* ptr = new Point(4, 5);
    //PointPtr p2 = ptr;
    //위 두 줄을 아래와 같이 표현할 수도 있다.    
    PointPtr p2 = new Point(4,5);


    p1->Print(); //p1.operator->() -> Print() 호출
    p2->Print(); //p2.operator->() -> Print() 호출
    cout << endl;

    (*p1).Print(); //p1.operator*().Print() 호출
    (*p2).Print(); //p2.operator*().Print() 호출

    //p2의 소멸자에서 Point 동적 객체를 자동으로 메모리에서 제거
    //p1의 소멸자에서 Point 동적 객체를 자동으로 메모리에서 제거

    return 0;
}
```
> 출력 결과
```
PointPtr(Point *p): ptr(p) > 0077E460
PointPtr(Point *p): ptr(p) > 0077E0E0
operator->(): return ptr; > 0077E460
2,3
operator->(): return ptr; > 0077E0E0
4,5

operator*(): return *ptr; >0077E460
2,3
operator*(): return *ptr; >0077E0E0
4,5
~PointPtr(): delete ptr; > 0077E0E0
~PointPtr(): delete ptr; > 0077E460
```
**PointPtr 특징**
- `p1`, `p2`는 스택 객체이므로 `main()`함수 블록이 종료될 때 자동으로 `p1`, `p2` 소멸자 호출 (스택영역 이기 때문에 `p2`, `p1` 순으로 삭제)
- 아래와 같은 상황에서도 동적으로 생성한 `Point` 객체를 소멸자에서 삭제하여 메모리 누수 방지
  - 프로그램 중에 예외가 발생한 경우
  - `delete` 연산자 호출을 빼먹는 경우 등
- `->`연산자 오버로딩을 통해서 `p1`, `p2`에서 `Point` 클래스의 멤버를 접근 할 수 있다
- `*` 연산자 오버로딩을 통해서 `(*p1).Print()`와 같이 멤버 함수를 호출 할 수 있다.

___
## 타입 변환 연산자 오버로딩

**순서**
- 생성자를 이용한 타입 변환
- 타입 변환 연산자 오버로딩을 이용한 타입 변환

### 생성자를 이용한 타입 변환
- 생성자를 이용해 다른 타입을 자신의 타입으로 변환 가능

```cpp
#include <iostream>
using namespace std;
class A
{

};
class B
{
public:
    B() { cout << "B() 생성자" << endl; }
    B(A& _a) { cout << "B(A _a) 생성자" << endl; }
    B(int n) { cout << "B(int n) 생성자" << endl; }
    B(double d) { cout << "B(double d) 생성자" << endl; }
};

int main()
{
    A a;
    int n = 10;
    double d = 5.5;

    B b;	// B() 생성자 호출
    b = a;	// b = B(a) 암시적 생성자 호출 후 대입
    b = n;	// b = B(n) 암시적 생성자 호출 후 대입
    b = d;	// b = B(d) 암시적 생성자 호출 후 대입

    return 0;
}
```
>출력 결과
```
B() 생성자
B(A _a) 생성자
B(int n) 생성자
B(double d) 생성자
```

**같은 원리로 다음과 같은 타입 변환도 가능하다**
```cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // 디폴트 매개변수, 초기화 목록
    void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
    Point pt;
    pt.Print();
    pt = 10; // pt = Point(10); 이 암시적으로 호출
    pt.Print();

    return 0;
}
```
>출력 결과
```
0, 0
10, 0
```
- 이 경우 실수로 Point 객체에 정수를 대입해도 컴파일이 성공하여 버그로 연결 될 수 있다.
- 때문에 생성자를 이용한 형변환을 의도하지 않는다면 생성자는 명시적 호출만 가능하도록 다음 처럼 `explicit` 키워드를 지정해야한다.

```cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // 디폴트 매개변수, 초기화 목록
    void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
    Point pt;
    pt.Print();
    //pt = 10; // 에러! 암시적 생성자 호출 불가능
    pt = Point(10); //명시적 생성자 호출만 가능
    pt.Print();

    return 0;
}
```
> 중요! 암시적인 생성자 형변환을 의도하지 않는 한  
> "인자를 갖는 생성자는 모두 `explicit` 생성자로 만들자"

### 타입 변환 연산자 오버로딩을 이용한 타입 변환 
- 타입 변환 연산자 오버로딩을 사용하면 자신의 타입을 다른 타입으로 변환 할 수 있다.
```cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // explicit 묵시적 호출 차단
    void Print() const { cout << x << ',' << y << endl; }
    operator int() const // 형변환 연산자 오버로딩 (Point -> int), 반환 형식 지정하지 않음.
    {
        return x;
    }
...
};

int main()
{
    int n = 10;

    Point pt(2, 3);
    n = pt; // pt.operator int() 암시적 호출
    cout << n << endl;

    return 0;
}
```
> 출력 결과
```
2
```
- 문장 `n = pt;`에서 컴파일러는 `Point`타입의 `pt`를 `int` 타입으로 변환하기 위해 타입 변환 연산자 `pt.operator int() const` 멤버 함수 호출
- 주의할 점은 타입 변환 연산자는 생성자나 소멸자처럼 반환 타입을 지정하지 않음.
- `operator int()` 멤버함수는 `const`로 선언하여 `const`객체나 비 `const`객체 모두 타입 변환이 가능하도록 함. 

___
## ❗이것만은 알고 갑시다.

##### 1. 다음 이항 연산자 `+`가 호출하는 오버로딩 함수 두 개를 고르세요.
```cpp
Point p1, p2;
p1 + p2;
```
- `p1.operator+(p2);`
- `operator(p1, p2);`

##### 2. 다음처럼 세 인자를 받는 `()` 연산자 오버로딩 함수 선언으로 맞는 것은?
```cpp
func(10, 20, 30);
```
- `int operator()(int, int, int);` 

##### 3. 다음 배열 클래스의 정수 원소를 참조하기 위한 `[]`연산자 오버로딩 함수 선언으로 맞는 것은?
```cpp
array[0];
```
- `int operator[](int)`

##### 4. 다음이 컴파일 될 수 있게 최소한의 String 클래스를 작성하세요.
```cpp
String s("Hello!");
const char* sz = s;
```
>답
```cpp
class String {
    const char* pstr;
public:
    explicit String(const char* _pstr) : pstr(_pstr) { }
    operator const char* () const { return  pstr; } // 반환 타입은 없지만, 반환은 반드시 필요.
};
```

##### 5. 다음이 컴파일될 수 있게 최소한의 String 클래스를 작성하세요
```cpp
const char* sz = "Hello!";
String s("Hi~!");
s = sz;
```
>답
```cpp
class String {
    const char* pstr;
public:
    String(const char* _pstr) : pstr(_pstr) { }
    operator const char* () const { return  pstr; }
};
```