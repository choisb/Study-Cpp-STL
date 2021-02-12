// find_first_of() 알고리즘 예제
// 두 순차열을 비교하여 모든 원소 중 같은 원소가 하나라도 발견되면 발견된 첫 원소의 반복자를 반환
// 조건자를 활용해서 비교 조건을 사용자가 정의할 수도 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return left > right;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);
	Vec1.push_back(40);
	Vec1.push_back(50);


	cout << "Vec1 ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	vector<int> Vec2;
	Vec2.push_back(40);
	Vec2.push_back(80);
	Vec2.push_back(20);

	cout << "Vec2 ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	// Vec1에서 Vec2순차열의 원소와 일치하는 원소가 단 하나라도 있다면
	// 일치하는 순차열의 첫번째 원소 반환
	cout << "기본 find_first_of()함수" << endl;
	auto iter = find_first_of(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end());
	if (iter != Vec1.end())
		cout << "iter : " << *iter << endl;

	cout << "조건자를 사용하는 find_first_of()함수" << endl;
	iter = find_first_of(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), Pred);
	if (iter != Vec1.end())
		cout << "iter : " << *iter << endl;

	return 0;
}
// [출력 결과]
// Vec1 10 20 30 40 50
// Vec2 40 80 20
// 기본 find_first_of()함수
// iter : 20
// 조건자를 사용하는 find_first_of()함수
// iter : 30