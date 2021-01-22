# Tamplate
## 📝 목차
- [템플릿 이란?](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-템플릿-이란)
  - 템플릿의 종류
- [함수 템플릿](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-함수-템플릿)
  - 함수 오버로딩 vs 함수 템플릿
  - 명시적 함수 템플릿 인스턴스 생성
  - 여러 개의 매개변수를 갖는 함수 템플릿
  - 정수를 매개 변수로 갖는 함수 템플릿
  - 템플릿 함수와 인터페이스
  - 함수 템플릿 특수화
- [클래스 템플릿](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-클래스-템플릿)
  - 클래스 템플릿의 사용
  - 클래스 템플릿의 특수화
- [STL을 위한 템플릿 예제](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-STL을-위한-템플릿-예제)
  - 함수 템플릿 예제
  - 함수 객체와 클래스 템플릿
  - 더 유연한 함수 객체
  - `Pair`클래스 구현
- [연습문제](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-연습문제)
___
## ✔ 템플릿 이란?
- 템플릿은 STL 제네릭 프로그래밍의 핵심.
- 템플릿은 **컴파일 타임**에 클라이언트가 여러 타입의 **함수나 클래스**를 쉽게 생성하게 한다.
- 템플릿을 이용하면 제네릭한 프로그래밍이 가능해진다.
  - 서버 코드 작성자는 조금더 일반적인 프로그램 코드를 만들 수 있다.
  - 클라이언트 사용자는 구체적인 코드를 작성할 수 있다. 

##### 템플릿의 종류
- **함수 템플릿**: 여러 함수를 만들어내는 함수의 틀
- **클래스 템플릿**: 여러 클래스를 만들어내는 클래스의 틀
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 함수 템플릿
- 함수 템플릿은 여러 함수를 만들어내는 **함수의 틀** 이다.
- 이해를 돕기 위해서 **함수 오버로딩**과 **함수 템플릿**의 차이를 살펴본다.

##### 함수 오버로딩 vs 함수 템플릿
- 함수 오버로딩을 이용하면 아래와 같이 매개변수 리스트가 다른 세 함수를 정의할 수 있다.
>함수 오버로딩 예제 [(`ex04_01.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_01.cpp)
```cpp
#include <iostream>
using namespace std;

void Print(int a, int b)
{
    cout << a << ", " << b << endl;
}

void Print(double a, double b)
{
    cout << a << ", " << b << endl;
}

void Print(const char* a, const char* b)
{
    cout << a << ", " << b << endl;
}

int main()
{
    Print(10, 20);          // 정수 출력
    Print(0.123, 1.123);    // 실수 출력
    Print("ABC", "abcd");   // 문자열 출력

    return 0;
}
```

>출력 결과
```
10, 20
0.123, 1.123
ABC, abcd
```
- 하지만 **함수 오버로딩**은 다음과 같은 단점이 있다.
  - 서버가 클라이언트의 매개변수 타입을 미리 알고 있어야 한다.
  - 따라서 서버는 사용자 정의 타입 서버가 예측할 수 없는 타입을 지원 할 수 없다.

- **템플릿 함수**를 사용하면 컴파일러는 클라이언트의 함수 호출 인자 타입을 보고 
템플릿 함수의 매개변수 타입을 결정하여 실제 함수인 템플릿 인스턴스 함수를 만들어낸다.
  - 서버 함수는 일반화된 기능만을 제공할 수 있다.
  - 클라이언트가 함수의 매개변수 타입을 결정한다.

- 이는 클라이언트가 타입이 다른 함수를 얼마든지 만들어 내므로 **뛰어난 확장성**을 가진다.
- 아래의 예시에서 각각의 상황에 따라 정의되었던 함수 오버로딩이 하나의 일반화된 템플릿 함수로 작성된 것을 볼 수 있다.

>함수 템플릿 예제 [(`ex04_02.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_02.cpp)
```cpp
#include <iostream>
using namespace std;

template<typename T>
void Print(T a, T b)
{
    cout << a << ", " << b << endl;
}

int main()
{
    Print(10, 20);          // 정수 출력
    Print(0.123, 1.123);    // 실수 출력
    Print("ABC", "abcd");   // 문자열 출력

    return 0;
}
```
> 출력 결과
```
10, 20
0.123, 1.123
ABC, abcd
```
##### 명시적 함수 템플릿 인스턴스 생성
- 앞선 코드들이 실행되면 컴파일러는 암묵적으로 아래의 템플릿 인스턴스를 생성한다. 
```cpp
void Print<int>(int a, int b);
void Print<double>(double a, double b);
void Print<const char*>(const char* a, const char* b);
```

- 필요에 따라서 클라이언트가 생성할 템플릿의 인스턴스를 명시적으로 지정하는 것도 가능하다.
```cpp
...
int main()
{
    Print<int>(10, 20);                 // 정수 출력
    Print<double>(0.123, 1.123);        // 실수 출력
    Print<const char*>("ABC", "abcd");  // 문자열 출력
}
```

##### 여러 개의 매개변수를 갖는 함수 템플릿
- 템플릿도 함수처럼 여러 매개변수를 가질 수 있다.
> 두 개의 매개변수를 갖는 함수 템플릿 [(`ex04_03.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_03.cpp)
```cpp
#include <iostream>
using namespace std;

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << ", " << b << endl;
}

int main()
{
    Print(10, 1.5);
    Print("Hello!", 100);
    Print(1.5, "Hello!");

    return 0;
}
```
> 출력 결과
```
10, 1.5
Hello!, 100
1.5, Hello!
```

##### 정수를 매개변수로 갖는 함수 템플릿
- 앞서 살펴본 함수 템플릿들의 매개변수는 모두 데이터 타입 이름이었다.
```cpp
template<typename T1, typename T2>
Print(T1 a, T2 b)
{
    ...
}
main(){
    Print<int, const char*>(3, "Hello");// 함수 템플릿의 매개변수로 "int", "const char*" 전달
    Print<double, int>(1.1, 2);         // 함수 템플릿의 매개변수로 "double", "int" 전달
}
```

- 하지만 함수 템플릿의 매개변수로 데이터 타입의 이름 뿐만 아니라 다음과 같이 정수 등의 데이터도 가능하다.
- 단, 클라이언트 코드에서 `PrintArray<int, 5>(arr1)`처럼 반드시 **명시적으로 호출** 해야한다.
  - 만약 묵시적으로 `PrintArray(arr1)`와 같이 호출하게 될 경우 컴파일러는 함수 템플릿의 매개변수 `int size`값을 알 수 없어서 인스턴스를 생성할 수 없기 때문이다.  
> 배열 출력 함수 템플릿[(`ex04_04.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_04.cpp)
```cpp
#include <iostream>
using namespace std;

template<typename T, int size>
void PrintArray(T* arr)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int arr1[5] = { 10, 20, 30, 40, 50 };
    PrintArray<int, 5>(arr1); // 명시적 호출

    double arr2[3] = { 1.1, 2.2, 3.3};
    PrintArray<double, 3>(arr2); // 명시적 호출

    return 0;
}
```
> 출력 결과
```
[0]: 10
[1]: 20
[2]: 30
[3]: 40
[4]: 50

[0]: 1.1
[1]: 2.2
[2]: 3.3
```
##### 템플릿 함수와 인터페이스
- 템플릿 함수의 매개변수로 어떤 객체가 들어올 수 있는지 살펴 보기 위해서 예시로 `Swap()`를 구현해 본다.

> `Swap()` 템플릿 함수 [(`ex04_05.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_05.cpp)
```cpp
#include <iostream>
using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n1 = 10, n2 = 20;
    double d1 = 1.1, d2 = 2.2;

    cout << n1 << ", " << n2 << endl;
    Swap(n1, n2);
    cout << n1 << ", " << n2 << endl;
    cout << endl;

    cout << d1 << ", " << d2 << endl;
    Swap(d1, d2);
    cout << d1 << ", " << d2 << endl;

    return 0;
}
```
> 출력 결과
```
10, 20
20, 10

1.1, 2.2
2.2, 1.1
```
- 여기서 템플릿의 매개변수 타입 객체 `a`와 `b`에는 반드시 템플릿 함수 정의의 연산이 가능한 객체, 즉 **인터페이스를 지원하는 객체**만 올 수 있다.
  - `T temp = a` 문장에서 복사 생성자를 호출하기 때문에, `a`에 들어올 객체는 반드시 복사 생성자(**인터페이스**)를 지원 해야한다.
  - `a = b`나 `b = temp` 문장에서 대입 연산자를 호출하므로 대입 연산자(**인터페이스**)를 지원해야한다.

##### 함수 템플릿 특수화
- 특수화는 말 그대로 특수화된 버전의 함수 템플릿을 더 제공하는 것.

- 앞서 `swap()` 예시에서 본것 처럼 매개변수 타입 객체는 반드시 템플릿 함수 정의의 연산(**인터페이스**)를 지원해야 한다.
  - 아래와 같이 템플릿 함수 정의의 연산(**인터페이스**)을 지원하지 않을 경우 에러가 발생한다. (전체 소스 코드 보기[`ex04_06.cpp`](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_06.cpp))
    ```cpp
    template<typename T>
    void Print(T a)
    {
        cout << a << endl;
    }
    ```  
  - `void Print(T a)` 템플릿 함수에서 `a` 객체는 반드시 `cout`의 `<<`연산이 가능한(**인터페이스를 지원하는**) 객체여야만 한다. 
    ```cpp
    class Point
    {
        int x; int y;
    public:
        explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
        void Print() const{ cout << x << ',' << y << endl; }
    };
    ```
  - `Point` 클래스는 `cout`의 `<<` 연산을 지원하지 않고 있다. 
  - 때문에 아래와 같이 `Print(pt);` 코드는  `cout << pt`가 불가능 하기 때문에 에러가 발생한다.
    ```cpp
    int main()
    {
        Point pt(2, 3);

        Print(pt); // 에러! cout << pt; 연산이 불가능

        return 0;
    }
    ```
- 이 문제를 해결하기 위해서는 아래와 같은 방법이 있다.
  - `Point` 클래스에 `<<` 연산자 오버로딩 함수를 추가.
  - `Point` 객체만의 특수화된 함수 템플릿을 지원.
- 만약 `Point` 클래스가 소스코드로 지원되지 않는 라이브러리 상태라던가, `Point` 클래스를 수정하지 
못하는 상태라면 `Point`함수에 `<<`연산자를 오버로딩 할 수 없기 때문에 반드시 **특수화된 함수 템플릿**을
지원 해야한다.
- 아래는 함수 템플릿 `Print()`의 **특수화 버전**을 추가한 예제 이다.
> `Point` 객체만의 함수 템플릿 특수화 지원 [(`ex04_07.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_07.cpp)
```cpp
#include <iostream>
using namespace std;

class Point
{
    int x; int y;
public:
    explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
    void Print() const { cout << x << ',' << y << endl; }
};

// 일반화 함수 템플릿
template<typename T>
void Print(T a)
{
    cout << a << endl;
}

// 특수화 함수 템플릿
template<>
void Print(Point a) // 명시적인 코드: void Print<Point>(Point a)
{
    cout << "Print 특수화 버전: ";
    a.Print();
}

int main()
{
    int n = 10;
    double d = 2.5;
    Point pt(2, 3);

    Print(n);   // Print<int>(n)    일반화 버전 호출
    Print(d);   // Print<double>(d) 일반화 버전 호출
    Print(pt);  // Print<Point>(pt) 특수화 버전 호출

    return 0;
}
```
> 출력 결과
```
10
2.5
Print 특수화 버전: 2,3
```
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 클래스 템플릿
 - 함수 템플릿이 함수를 만들어 내는 틀이라면, 클래스 템플릿은 클래스를 만들어내는 틀이다.

##### 클래스 템플릿의 사용 
 - 만약 아래와 같이 정수형 데이터를 관리하는 `Array`라는 클래스가 있다고 하자.
```cpp
class Array
{
    int *buf;
    int size; // 원소의 개수
    int capacity; // 저장 가능한 메모리 크기
public:
    explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
    {
        buf = new int[capacity];
    }
    ~Array() { delete[] buf; }

    void Add(int data)
    {
        buf[size++] = data;
    }

    int operator[] (int idx) const
    {
        return buf[idx];
    }

    int GetSize() const
    {
        return size;
    }
    // 나머지 인터페이스 생략...
};
``` 
- 그런데 이제 정수 뿐만 아니라 실수를 저장하는 `Array`도 필요하고, 
문자열을 저장하는 `Array`도 필요할 수 있다.

  - 정수형 `Array`, 실수형 `Array`, 문자열`Array`모두 데이터 타입만 다르고
  **객체가 해야 할 일**(**인터페이스**, **기능**: 데이터 객체생성, 삭제, 데이터 삽입, 데이터 참조 등)
  은 모두 같을 것이다.

  - 이때 각각 데이터 타입에 맞는 `IntArray`, `DoubleArray`, `StringArray`를 각각
  만들 수도 있을 것이다.

  - 하지만 이럴때 클래스 템플릿을 사용하면 더욱 효율적이다.

  - 그리고 클래스 템플릿의 매개변수는 함수 템플릿처럼 정수형으로 사용할 수도 있으며, 
  디폴트 매개변수를 설정할 수도 있다.

> 디폴트 매개변수 값을 갖는 클래스 템플릿 [(`ex04_08.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_08.cpp)
```cpp
#include <iostream>
#include <string>   // 문자열 string 클래스 헤더
using namespace std;

template<typename T = int, int capT = 100>  // T = 100 / capT = 100 으로 디폴트값 설정
class Array
{
    T *buf;
    int size; // 원소의 개수
    int capacity; // 저장 가능한 메모리 크기
public:
    explicit Array(int cap = capT) : buf(0), size(0), capacity(cap)
    {
        buf = new T[capacity];
    }
    ~Array() { delete[] buf; }

    void Add(T data)
    {
        buf[size++] = data;
    }

    T operator[] (int idx) const
    {
        return buf[idx];
    }

    int GetSize() const
    {
        return size;
    }
    // 나머지 인터페이스 생략...
};
int main()
{
    Array<> iarr; // 디폴트 매개변수 값 T = int, capT = 100 사용.

    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);

    for (int i = 0; i < iarr.GetSize(); i++)
        cout << iarr[i] << endl;
    cout << endl;

    Array<double> darr; // 디폴트 매개변수 capT = 100 사용.

    darr.Add(10.12);
    darr.Add(20.12);
    darr.Add(30.12);

    for (int i = 0; i < darr.GetSize(); i++)
        cout << darr[i] << endl;
    cout << endl;

    Array<string, 10> sarr; // 디폴트 매개변수 값 사용하지 않음.

    sarr.Add("abc");
    sarr.Add("ABC");
    sarr.Add("Hello");

    for (int i = 0; i < sarr.GetSize(); i++)
        cout << sarr[i] << endl;
    cout << endl;

    return 0;
}
```
> 출력 결과
```
10
20
30

10.12
20.12
30.12

abc
ABC
Hello
```

##### 클래스 템플릿의 특수화
- **클래스 템플릿의 특수화**(Class Template Specialization)는 함수 템플릿 특수화처럼 
일반 버전의 템플릿을 사용할 수 없는 경우나 성능 개선이나 특수한 기능 등을 위해 특수화 
버전을 별도로 제공하고자 할 때 사용한다.

- 어떤 경우에 클래스 템플릿의 특수화를 살펴보기 위해서 먼저 특수화를 사용하지 않은 예시
`ex04_09.cpp`를 살펴보자. `ObjectInfo` 클래스는 객체의 정보를 출력하는 클래스 템플릿 이다.
> 객체 정보를 출력하는 ObjectInfo 클래스 [(`ex04_09.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_09.cpp)
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ObjectInfo
{
    T data;
public:
    ObjectInfo(const T& d) : data(d) {}
    void Print()
    {
        cout << "타입 : " << typeid(data).name() << endl;
        cout << "크기 : " << sizeof(data) << endl;
        cout << "값 : " << data << endl;
        cout << endl;
    }
};

int main()
{
    ObjectInfo<int> d1(10);
    d1.Print(); // 객체 정보 출력

    ObjectInfo<double> d2(5.5);
    d2.Print(); // 객체 정보 출력

    ObjectInfo<string> d3("Hello!");
    d3.Print(); // 객체 정보 출력

    return 0;
}
```
> 출력 결과
```
타입 : int
크기 : 4
값 : 10

타입 : double
크기 : 8
값 : 5.5

타입 : class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
크기 : 28
값 : Hello!
```

- 출력결과에서 `string` 클래스의 정보는 우리의 의도와는 조금 다르게 출력된 것을 확인 할 수 있다.

  - `string`클래스가 템플릿 클래스로 `typedef`되어 있기 때문에 우리가 관심있는 값인 `string`이 아닌
  실제 값이 출력되었다.

  - 크기또한 우리가 관심있는 문자열의 길이가 아니라 실제 메모리에 할당된 크기가 출력되었다.
  - 우리는 아래의 예시 처럼 `int`, `double`형과는 다른 조금 특별한 `string`만의 **특수 클래스**가 필요하다.
    - 일반화 버전
    ```cpp
        template<typename T> 
        class ObjectInfo
    ```
    - 특수화 버전: 
    ```cpp
        template<> 
        class ObjectInfo<string>
    ```
>`ObjectInfo` 특수화 버전 [(`ex04_10.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_10.cpp)
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ObjectInfo
{
    T data;
public:
    ObjectInfo(const T& d) : data(d) {}
    void Print()
    {
        cout << "타입 : " << typeid(data).name() << endl;
        cout << "크기 : " << sizeof(data) << endl;
        cout << "값 : " << data << endl;
        cout << endl;
    }
};
template<> // T를 string으로 특수화(클래스 템플릿 특수화)
class ObjectInfo<string>
{
    string data;
public:
    ObjectInfo(const string& d) :data(d) {}

    void Print()
    {
        cout << "타입 : " << "string" << endl;    // 타입 정보 수정
        cout << "문자열 길이 : " << data.size() << endl; // string 만의 문자열 길이 정보 추가
        cout << "값 : " << data << endl;
        cout << endl;
    }
};
int main()
{
    ObjectInfo<int> d1(10);
    d1.Print(); // 객체 정보 출력

    ObjectInfo<double> d2(5.5);
    d2.Print(); // 객체 정보 출력

    ObjectInfo<string> d3("Hello!");    // 특수화 버전의 클래스 템플릿으로 생성.
    d3.Print(); // 객체 정보 출력

    return 0;
}
```
> 출력 결과
```
타입 : int
크기 : 4
값 : 10

타입 : double
크기 : 8
값 : 5.5

타입 : string
문자열 길이 : 6
값 : Hello!
```

[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___

## ✔ STL을 위한 템플릿 예제
- STL에서 사용되는 템플릿에 대한 이해를 돕기 위해서 다음 두 가지 예제를 살펴본다.

  - 함수 템플릿 예제 `For_each()`
  - 클래스 템플릿 예제

##### 함수 템플릿 예제

- 앞서 2장에서 **콜백함수**의 개념을 익히기 위해서 `For_each()`함수를 다룬 적 있다.
[(코드 이동)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch02_Function_Pointer/ex02_04.cpp)

- 이 코드에서 `For_each()` 함수는 배열의 원소가 정수일 때만 사용 가능했다.

- 만약 원소의 `For_each()` 함수가 타입에 상관없이 사용할 수 있는 일반적인 함수라면 
클라이언트의 활용도를 높이고 유지 보수를 좋게 할 수 있다.

- 이때 함수 템플릿을 사용하면 배열의 원소 타입을 클라이언트가 결정하게 만들 수 있다.
  - 함수 템플릿은 예시와 같이 묵시적 호출과 명시적 호출모두 가능 하다.
  - 또한 함수 포인터로 전달할 `Print()` 함수 또한 타입에 따라서 생성될 
  수 있도록 함수 포인터로 정의 할 수 있다.
    - 이때 주의할 점은 출력 함수의 템플릿 매개변수를 컴파일러가 유추할 수 있도록
    명시적으로 매개변수 인자`Print<int>, Print<string>`를 지정해야 한다.

> 일반화 한 `For_each()` 함수[(`ex04_11.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_11.cpp)
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while (begin != end)
    {
        pf(*begin++);
    }
}

template<typename T>
void Print(T n)
{
    cout << n << " ";
}

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    string sarr[3] = { "abc", "ABC", "Hello" };

    // 정수 출력, 묵시적 함수 템플릿 호출
    For_each(arr, arr + 5, Print<int>);
    cout << endl;

    // 문자열 출력, 묵시적 함수 템플릿 호출
    For_each(sarr, sarr + 3, Print<string>); 
    cout << endl << endl;

    // 정수 출력, 명시적 함수 템플릿 호출
    For_each<int* , void(*)(int)>(arr, arr + 5, Print<int>); 
    cout << endl;

    // 문자열 출력, 명시적 함수 템플릿 호출
    For_each<string*, void(*)(string)>(sarr, sarr + 3, Print<string>); 
    cout << endl;

    return 0;
}
```
> 출력 결과
```
10 20 30 40 50
abc ABC Hello

10 20 30 40 50
abc ABC Hello
```

##### 함수 객체와 클래스 템플릿
- 3장에서 함수 객체의 장점을 다뤘다. [(3장. 함수 객체란)]((https://github.com/choisb/Study-Cpp-STL/tree/master/Ch03_Function_Object#-함수-객체란))
  - 함수 객체를 사용하면 멤버 변수를 사용한 부가적인 서비스를 제공할 수 있다. 
- 앞서 다룬 예제의 `Print()` 함수를 함수 객체로 만들어 보자.

  - 함수 템플릿을 함수 객체로 선언하게되면 **클래스 템플릿**이 된다.
  - 함수 객체는 부가정보를 가질 수 있으므로 (`sep`)라는 출력 패턴 구분자를 가질 수 있다.
  - 생성자를 호출할 때 출력 패턴(`sep`)을 입력 받는다.

> 함수객체 적용 예시 [(`ex04_12.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_12.cpp)
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while (begin != end)
    {
        pf(*begin++);
    }
}

template<typename T>
struct PrintFunctor
{
    string sep; // 출력 구분자 정보

    explicit PrintFunctor(const string& s = " ") : sep(s) {}
    void operator() (T data) const
    {
        cout << data << sep;
    }
};

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    string sarr[3] = { "abc", "ABC", "Hello" };

    // 정수 출력, 묵시적 함수 템플릿 호출
    For_each(arr, arr + 5, PrintFunctor<int>());    // 디폴트 매개변수 s = " " 사용
    cout << endl;

    // 문자열 출력, 묵시적 함수 템플릿 호출
    For_each(sarr, sarr + 3, PrintFunctor<string>("*\n")); // s = "*\n" : 매 출력마다 * + 줄바꿈. 
    cout << endl << endl;

    return 0;
}
```
> 출력 결과
```
10 20 30 40 50
abc*
ABC*
Hello*
```
##### 더 유연한 함수 객체
- **템플릿의 매개변수**와 **함수 객체**를 결합하면 반환 타입과 함수 매개변수 타입을 클라이언트가 결정하는 아주 **유연한 함수 객체**를 만들 수 있다.
> 반환 타입과 매개변수 타입을 인자로 갖는 함수 객체 [(`ex04_13.cpp`)]((https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_13.cpp))
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename RetType, typename ArgType>
class Functor
{
public:
    RetType operator() (ArgType data)
    {
        cout << data << endl;
        return RetType();
    }
};

int main()
{
    Functor<void, int> functor1;
    functor1(10);
    Functor<bool, string> functor2;
    functor2("Hello!");

    return 0;
}
```
> 출력 결과
```
10
Hello!
```

##### `Pair` 클래스 구현
- STL에서 제공하는 `pair`클래스를 템플릿으로 구현 해보자.
  - `pair`클래스는 두 객체를 하나의 객체로 취급할 수 있게 두 객체를 묶어주는 역할을 한다.
  - STL의 모든 쌍을 이루는 객체는 pair 객체를 사용한다. (대표적으로 `map` 컨테이너가 있다.)
>Pair 클래스[(`ex04_14.cpp`)](https://github.com/choisb/Study-Cpp-STL/blob/master/Ch04_Template/ex04_14.cpp)
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
    MyPair(const T1& ft, const T2& sd) :first(ft), second(sd) {}
};
int main()
{
    // 우리가 구현한 pair 클래스
    MyPair<int, int> p1(10, 20);
    cout << p1.first << ',' << p1.second << endl;
    MyPair<int, string> p2(1, "one");
    cout << p2.first << ',' << p2.second << endl;
    cout << endl;

    //stl에 구현되어 있는 pair 클래스
    pair<int, int> p3(10, 20);
    cout << p3.first << ',' << p3.second << endl;
    pair<int, string> p4(1, "one");
    cout << p4.first << ',' << p4.second << endl;

    return 0;
}
```
> 출력 결과
```
10,20
1,one

10,20
1,one
```
- 함수 객체와, 템플릿을 활용해서 직접 구현한 `MyPair` 클래스가 
STL `pair`클래스와 동일하게 동작 하는 것을 확인 할 수 있다.

[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___

## 🎯 연습문제
##### 1. 다음은 배열의 원소를 복사하는 함수 템플릿 Copy()의 호출 코드입니다. 함수 템플릿 Copy()를 작성하세요.
```cpp
int main()
{
    int arr1[5] = { 10, 20, 30, 40, 50 };
    int arr2[5];
    //Copy(t, s, n) t: 목적지 주소, s: 소스 주소, n: 원소 개수
    Copy(arr2, arr1, 5);

    MyType myArr1[5];
    MyType myArr2[5];
    Copy(myArr2, myArr1, 5);

    return 0;
}
```
> 정답
```cpp
template<typename T>
void Copy(T t[], const T s[], int n)
{
    for (int i = 0; i < n; i++)
        t[i] = s[i];
}
class MyType { };
```

##### 2. 다음은 Push(), Pop(), Empty() 인터페이스를 갖는 Stack 객체의 사용 코드입니다. 최소한의 Stack 클래스를 작성하세요.
```cpp
int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
}
```
> 정답
```cpp
// 예외처리 생략
template <typename T>
class Stack {
    T* arr;
    int top;
    const int capacity;

public:
    explicit Stack(int _cap = 100) : capacity(_cap), top(0) // 생성자 형변환을 지원하지 않을 것이기 때문에 explicit 선언 꼭 할것.
    { 
        arr = new T[capacity];
    }

    void Push(const T& data)    // 임시 객체 생성을 막기 위해서 const T& 타입으로 호출할 것
    {
        arr[top++] = data;
    }

    bool Empty() const  // 멤버변수에 변화가 없기 때문에 const로 선언할것.
    {
        return top <= 0;
    }

    T& Pop()
    {
        return arr[--top];
    }
};
```
##### 🚩 오답노트
- `Push()`함수에서 임시 객체 생성을 막기 위해서 매개변수 타입은 `const T&`으로 선언할 것
- `Empty()`에서는 멤버변수에 변화가 없기 때문에 `const`로 선언할 것.

##### 3. 다음은 Push(), Pop(), Empty() 인터페이스를 갖는 Queue 객체의 사용 코드입니다. 최소한의 Queue 클래스를 작성하세요.
```cpp
int main()
{
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    if (!q.Empty())
        cout << q.Pop() << endl;
    if (!q.Empty())
        cout << q.Pop() << endl;
    if (!q.Empty())
        cout << q.Pop() << endl;

    return 0;
}
```
> 정답
```cpp
// 예외처리 생략
template<typename T>
class Queue {
    enum {CAP = 100};   // queue의 크기
    T buf[CAP];
    int front, rear;

public:
    Queue() :front(0), rear(0) {}
    void Push(const T& data)
    {
        buf[rear = (rear+1) % CAP] = data;      // rear의 값이 0 ~ CAP사이를 순환하도록 % 연산 
    }
    T& Pop()
    {
        return buf[front = (front+1) % CAP];    // front의 값이 0 ~ CAP사이를 순환하도록 % 연산 
    }
    bool Empty() const
    {
        return front == rear;
    }
};
```
[
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
