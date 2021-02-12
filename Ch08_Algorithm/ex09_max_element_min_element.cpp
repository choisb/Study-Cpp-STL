// max_element(), min_element() �˰��� ����
// max_element(), min_element() �˰����� ���޹��� ������ ������ ����
// ���� ū ���� ���� ���� ���� ��ȯ
// max_element(), min_element()�� �����ڸ� ���ؼ� ����ڰ� ������ ���� �� �ִ�.
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
// x���� �������� �� �� x���� ������ ��� y�� ��
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

	// �����ڸ� Ȱ���� min_element, max_element
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
// [��� ���]
// 50
// 10
// max: (3,4)
