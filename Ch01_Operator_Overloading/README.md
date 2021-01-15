## 연산자 오버로딩이란
연산자 오버로딩은 C++에서 제공하는 기본 타입이 아닌 클래스 타입, 즉 사용자 정의 타입에도 연산자를 사용할 수 있게 하는 문법.
연산자 오버로딩은 많은 STL 구성 요소에 사용돼 쉽고 더 직관적이며 일반화된 코드를 만들어 낸다.

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



## 연산자 오버로딩 정의 및 사용하기

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
> friend 함수는 캡슐화를 저해하므로 가능하면 getter, setter를 사용하는 것이 좋다.

## STL에 필요한 주요 연산자 오버로딩
함수 호출 연산자 오버로딩은 **객체**를 **함수**처럼 동작하게 하는 연산자이다. C++에서  Print(10)이라는 함수 호출 문장은 다음 세가지로 해석할 수 있다.
- 첫째, 함수 호출: Print가 함수 이름
- 둘째, 함수 포인터: Print가 함수 포인터
- 셋째, 함수 객체: Print가 함수 객체

```cpp {.line-numbers}
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

$$ y = a + 3 $$
