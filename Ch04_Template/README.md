# Tamplate
## 📝 목차
- [템플릿 이란?](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-템플릿-이란)
- [함수 템플릿](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-함수-템플릿)
- [클래스 템플릿](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Template#-클래스-템플릿)
- [STL을 위한 템플릿 예제]
- [이것만은 알고 갑시다.]
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
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Templatet#Tamplate) 
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
[위로](https://github.com/choisb/Study-Cpp-STL/tree/master/Ch04_Templatet#Tamplate) 
/ 
[처음으로](https://github.com/choisb/Study-Cpp-STL#c-stl-programming)
]
___
## ✔ 클래스 템플릿
