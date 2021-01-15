#include "Point.h"

//반환 타입: const Point
const Point Point::operator+(const Point& arg) const // 자신의 멤버를 변경하지 않는 멤버 함수는 모두 const 멤버 함수로 선언할 것.
{
	Point pt;
	pt.x = this->x + arg.x;
	pt.y = this->y + arg.y;

	return pt;
}

//반환 타입: const Point&
const Point& Point::operator++ ()	//전위 ++ 연산자
{
	++x;
	++y;
	return *this;
}

//반환 타입: const Point
const Point Point::operator++ (int) // 후위 ++ 연산자
{
	Point pt(x, y);
	++x;
	++y;
	return pt;
}

//반환 타입: const Point&
const Point& Point::operator-- ()	//전위 -- 연산자
{
	--x;
	--y;
	return *this;
}

//반환 타입: const Point
const Point Point::operator-- (int) // 후위 -- 연산자
{
	Point pt(x, y);
	--x;
	--y;
	return pt;
}

bool Point::operator==(const Point& arg) const
{
	return x == arg.x && y == arg.y ? true : false;
}
bool Point::operator!=(const Point& arg) const
{
	// 이미 정의된 "==" 연산자를 사용
	return !(*this == arg);
}

const Point operator*(const int k, const Point& argR)
{
	Point pt;
	pt.x = k * argR.x;
	pt.y = k * argR.y;

	return pt;
}