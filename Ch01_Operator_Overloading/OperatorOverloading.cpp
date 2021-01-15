#include "Point.h"

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

	void(*Print2) (int) = Print1;
	FuncObject Print3;

	Print1(10); // '함수'를 사용한 정수 출력
	Print2(10); // '함수 포인터'를 사용한 정수 출력
	Print3(10); // '함수 객체'를 사용한 정수 출력 (Print3.operator(10)과 같음)

	return 0;
}