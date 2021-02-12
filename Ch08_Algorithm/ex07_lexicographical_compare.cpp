// lexicographical_compare() 알고리즘 예제
// lexicographical_compare(b, e, b2, e2) 는
// 순차열 [b, e)와 [b2, e2)의 모든 원소를 문자열 처럼 비교하여 참과 거짓을 반환
// 기본적으로 (less: <) 조건자를 사용한다.
// 
// lexicographical_compare(b, e, b2, e2, f) 처럼
// 사용자가 비교기준 조건자를 직접 지정할 수 있다.
// 혹은 STL의 기본 greater, less를 사용할 수도 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
struct MyLess
{
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);

	vector<int> Vec2;
	Vec2.push_back(10);
	Vec2.push_back(20);
	Vec2.push_back(50);

	vector<int> Vec3;
	Vec3.push_back(10);
	Vec3.push_back(20);
	Vec3.push_back(30);

	if (lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end()))
		cout << "v1 < v2" << endl;
	else
		cout << "v1 >= v2" << endl;

	if (lexicographical_compare(Vec1.begin(), Vec1.end(), Vec3.begin(), Vec3.end()))
		cout << "v1 < v3" << endl;
	else
		cout << "v1 >= v3" << endl;

	cout << "STL less를 사용한 v1과 v2의 비교: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), less<int>()) << endl;

	cout << "STL greater를 사용한 v1과 v2의 비교: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), greater<int>()) << endl;

	cout << "사용자의 MyLess를 사용한 v1과 v2의 비교: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), MyLess<int>()) << endl;

	return 0;
}
// [출력 결과]
// v1 < v2
// v1 >= v3
// STL less를 사용한 v1과 v2의 비교 : 1
// STL greater를 사용한 v1과 v2의 비교 : 0
// 사용자의 MyLess를 사용한 v1과 v2의 비교 : 1