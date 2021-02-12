// find_end() 알고리즘 예제
// find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end())
// Vec1의 순차열에서 Vec2의 순차열과 동일한 순차열이 있는지 탐색
// 일치하는 순차열이 여러개라면 마지막 순차열의 첫 원소 반복자를 반환

// find_end() 알고리즘에 조건자를 사용하여 원소의 비교를 사용자가 결정할 수도 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return left >= right;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(5);

	Vec1.push_back(20);
	Vec1.push_back(30);
	Vec1.push_back(40);

	Vec1.push_back(50);

	Vec1.push_back(20);
	Vec1.push_back(300);
	Vec1.push_back(40);

	Vec1.push_back(50);

	cout << "Vec1 ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	vector<int> Vec2;
	Vec2.push_back(20);
	Vec2.push_back(30);
	Vec2.push_back(40);

	cout << "Vec2 ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	//Vec1에서 Vec2순차열 구간과 동일한 순차열이 있다면 시작원소의 반복자 반환
	auto iter = find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end());
	if (iter != Vec1.end())
	{
		//일치하는 마지막 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	iter = find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), Pred);
	if (iter != Vec1.end())
	{
		//일치하는 마지막 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	return 0;
}
// [출력 결과]
// Vec1 5 20 30 40 50 20 300 40 50
// Vec2 20 30 40
// iter : 20
// iter - 1 : 5
// iter + 1 : 30
// iter : 300
// iter - 1 : 20
// iter + 1 : 40