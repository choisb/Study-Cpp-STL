// max_element(), min_element() 알고리즘 예제
// max_element(), min_element() 알고리즘은 전달받은 순차열 내에서 각각
// 가장 큰 값과 가장 작은 값을 반환
// max_element(), min_element()는 조건자를 통해서 사용자가 기준을 정할 수 있다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	int GetX() const { return x; }
	int GetY() const { return y; }
	void Print() const { cout << '(' << x << ',' << y << ')' << endl; }
};
// x값을 기준으로 비교 후 x값이 동일할 경우 y값 비교
bool Compare(const Point& left, const Point& right)
{
	if (left.GetX() < right.GetX())
		return true;
	else if (left.GetX() > right.GetX())
		return false;
	else
		return left.GetY() < right.GetY();
}

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	auto iter = max_element(vec1.begin(), vec1.end());
	cout << *iter << endl;
	
	iter = min_element(vec1.begin(), vec1.end());
	cout << *iter << endl;

	// 조건자를 활용한 min_element, max_element
	vector<Point> vec2;
	vec2.push_back(Point(3, 1));
	vec2.push_back(Point(2, 2));
	vec2.push_back(Point(1, 3));
	vec2.push_back(Point(3, 4));
	vec2.push_back(Point(2, 5));

	auto iter2 = max_element(vec2.begin(), vec2.end(), Compare);
	cout << "max: "; iter2->Print();

	return 0;
}
// [출력 결과]
// 50
// 10
// max: (3,4)
