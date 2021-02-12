// equal() 알고리즘 예제
// equal() 알고리즘은 두 순차열의 원소를 비교하여 동일할 경우 true 반환
// equal() 알고리즘은 조건자를 사용할 수 있다.
// 조건자는 두개의 원소를 받을 수 있는 이항 조건자를 사용하고, 조건자가 참인 경우 equal()은 참을 반환

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 두 수의 차이가 5 미만일 경우 참을 반환하는 조건자.
bool Pred(int left, int right)
{
	return abs(right - left) < 5;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);

	vector<int> Vec2;
	Vec2.push_back(12);
	Vec2.push_back(21);
	Vec2.push_back(33);
	Vec2.push_back(40);
	Vec2.push_back(50);

	cout << "Vec1 : ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	cout << "Vec2 : ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	// 구간 [Vec1.begin(), Vec2.end()) 와
	// 구간 [Vec2.begin(), Vec2.begin() + 3) 이 동일한지 확인
	// 기본 equal() 사용
	if (equal(Vec1.begin(), Vec1.end(), Vec2.begin()))
		cout << "두 순차열은 정확히 같습니다." << endl;

	// 사용자 정의 조건자를 사용하는 equal() 사용
	if (equal(Vec1.begin(), Vec1.end(), Vec2.begin(), Pred))
		cout << "두 순차열은 거의 같습니다." << endl;

	return 0;
}
// [출력 결과]
// Vec1: 10 20 30
// Vec2 : 10 20 30 40 50
// 두 순차열은 거의 같습니다.