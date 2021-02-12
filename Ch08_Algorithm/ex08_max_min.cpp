// max(), min() 알고리즘 예제
// max()나 min() 알고리즘을 사용하면 간단하게 값을 비교하여 두 개의 값 중 크거나 작은 값을 찾을 수 있다.
// 각각 조건자를 사용하여서 비교 기준을 사용자가 지정할 수도 있다.

#include <iostream>
#include <algorithm>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	int GetX() const { return x; }
	int GetY() const { return y; }
	void Print() const 	{cout << '(' << x << ',' << y << ')' << endl;}
};
bool XCompare(const Point& left, const Point& right)
{
	return left.GetX() < right.GetX();
}

bool YCompare(const Point& left, const Point& right)
{
	return left.GetY() < right.GetY();
}

int main()
{
	int a = 10, b = 20;
	int r;

	r = max(a, b);
	cout << "max: " << r << endl;

	r = min(a, b);
	cout << "min: " << r << endl;

	Point pt1(5, 8), pt2(3, 9);
	Point pt3;

	pt3 = max(pt1, pt2, XCompare);
	cout << "x max: "; 
	pt3.Print();

	pt3 = max(pt1, pt2, YCompare);
	cout << "y max: "; 
	pt3.Print();

	return 0;
}
// [출력 결과]
// max: 20
// min : 10
// x max : (5, 8)
// y max : (3, 9)