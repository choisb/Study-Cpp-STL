#pragma once
#include <iostream>
using namespace std;

class Point
{
	friend const Point operator*(const int argL, const Point& argR);

	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // 디폴트 매개변수, 초기화 목록
	void Print() const { cout << x << ',' << y << endl; }

	//반환 타입: const Point
	const Point operator+(const Point& arg) const; // 자신의 멤버를 변경하지 않는 멤버 함수는 모두 const 멤버 함수로 선언할 것.


	//단항 연산자 오버로딩
	//반환 타입: const Point&
	const Point& operator++ ();	//전위 ++ 연산자

	//반환 타입: const Point
	const Point operator++ (int); // 후위 ++ 연산자

	//반환 타입: const Point&
	const Point& operator-- ();	//전위 -- 연산자

	//반환 타입: const Point
	const Point operator-- (int); // 후위 -- 연산자


	//이항 연산자 오버로딩
	bool operator==(const Point& arg) const;
	bool operator!=(const Point& arg) const;
};

//전역 함수를 이용한 연산자 오버로딩
const Point operator*(const int argL, const Point& argR);