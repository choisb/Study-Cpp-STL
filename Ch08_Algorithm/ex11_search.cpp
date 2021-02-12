// search() 알고리즘 예제
// find_end()와 마찬가지로 순차열에 여러 순차열이 일치하는지 찾는 알고리즘이다.
// find_end()와 차이점은 find_end()는 마지막 순차열의 반복자를 반환하지만,
// search()는 첫 번째 순차열의 반복자를 반환한다.

// search()는 조건자를 사용하여서 비교 기준을 사용자가 지정할 수 있다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return abs(left - right) <= 5;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(30);

	Vec1.push_back(20);
	Vec1.push_back(35);
	Vec1.push_back(40);

	Vec1.push_back(50);

	Vec1.push_back(20);
	Vec1.push_back(30);
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
	auto iter = search(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end());
	if (iter != Vec1.end())
	{
		//일치하는 첫 번쨰 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}
	cout << endl;

	cout << "조건자 사용 예제" << endl;
	iter = search(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), Pred);
	if (iter != Vec1.end())
	{
		//일치하는 첫 번쨰 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	return 0;
}
// [출력 결과]
// Vec1 30 20 35 40 50 20 30 40 50
// Vec2 20 30 40
// iter : 20
// iter - 1 : 50
// iter + 1 : 30
// 
// 조건자 사용 예제
// iter : 20
// iter - 1 : 30
// iter + 1 : 35
