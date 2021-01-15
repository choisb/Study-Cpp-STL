#include "PointPtr.h"
#include "Array.h"
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

class A
{

};
class B
{
public:
	operator A() // 반환 형식이 없다.
	{
		cout << "operator A() 호출" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int() 호출" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double() 호출" << endl;
		return 5.5;
	}
};

class String {
	const char* pstr;
public:
	String(const char* _pstr) : pstr(_pstr) { }
	operator const char* () const { return  pstr; }
};

int main()
{
	//Point p1(2, 3), p2(5, 5);

	//p1 + p2; // => p1.operator+(p2); 와 같다
	//p1 * p2; // => p1.operator*(p2); 와 같다
	//p1 = p2; // => p1.operator=(p2); 와 같다
	//p1 == p2; // => p1.operator==(p2); 와 같다
	//p1 += p2; // => p1.operator+=(p2); 와 같다

	//++p1; //p1.operator++();와 같다
	//p2++; //p2.operator++(0);와 같다. 후위연산는 operator++() 멤버 함수 호출 시 의미 없는(dummy) 정수형 인자 0을 전달한다.

	//Point result;

	//result = ++p1;
	//p1.Print();
	//result.Print();

	//result = p2++;
	//p2.Print();
	//result.Print();

	//Point p3(2, 3);

	//if (p1 != p2)
	//	cout << " p1 != p2" << endl;
	//if (p1 != p3)
	//	cout << " p1 != p3" << endl;

	//Point p1(2, 3);
	//Point result;

	//result = 2 * p1;
	//result.Print();

	//void(*Print2) (int) = Print1;
	//FuncObject Print3;

	//Print1(10); // '함수'를 사용한 정수 출력
	//Print2(10); // '함수 포인터'를 사용한 정수 출력
	//Print3(10); // '함수 객체'를 사용한 정수 출력 (Print3.operator(10)과 같음)


	//Array ar(10);
	//ar.Add(10);
	//ar.Add(20);
	//ar.Add(30);

	//for (int i = 0; i < ar.Size(); i++)
	//	cout << ar[i] << endl; //ar.operator[](int) 호출

	//const Array& ar2 = ar;
	//ar[0] = 40;	//ar.operator[](int) 호출
	//cout << ar2[0] << endl; //ar.operator[](int) const 호출
	////ar2[0] = 100; //에러! 상수 객체(값)을 반환하기 때문에 대입할 수 없다.


	//Point* ptr = new Point(2, 3);
	//PointPtr p1 = ptr; //PointPtr p1(ptr); 과 같은 표현인듯?

	//// Point* ptr = new Point(4, 5);
	//// PointPtr p2 = ptr;
	//// 위 두 줄을 아래와 같이 표현할 수도 있다.    
	//PointPtr p2 = new Point(4, 5);


	//p1->Print(); //p1.operator->() -> Print() 호출
	//p2->Print(); //p2.operator->() -> Print() 호출
	//cout << endl;

	//(*p1).Print(); //p1.operator*().Print() 호출
	//(*p2).Print(); //p2.operator*().Print() 호출

	////p2의 소멸자에서 Point 동적 객체를 자동으로 메모리에서 제거
	////p1의 소멸자에서 Point 동적 객체를 자동으로 메모리에서 제거

	//A a;
	//int n;
	//double d;

	//B b;	
	//a = b;	// b.operator A() 암시적 호출
	//n = b;	// b.operator int() 암시적 호출
	//d = b;	// b.operator double() 암시적 호출

	//cout << endl;
	//a = b.operator A();		// 명시적 호출
	//n = b.operator int();	// 명시적 호출
	//d = b.operator double();// 명시적 호출

	//int n = 10;

	//Point pt(2, 3);
	//n = pt; // pt.operator int() 암시적 호출
	//cout << n << endl;

	//return 0;
	const char* sz = "Hello!";
	String s("Hi~!");
	s = sz;



	return 0;
}