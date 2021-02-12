// search_n() 알고리즘 예제
// 순차열에서 원소의 값이 n 번 반복되는지 찾고 싶을때 사용.
// search_n(b,e,n,x) 알고리즘은 구간 [b, e)의 순차열에서 원소 x가 n번 연속한 첫 원소의 반복자를 반환
// search_n() 알고리즘은 조건자를 사용해서 조건자 f(*p,x)가 참인 값이 n개 연속한 첫 원소의 반복자를 반환

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right)
{
	return abs(right - left) <= 5;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);

	vec.push_back(30);
	vec.push_back(30); // 30이 두번 반복
	vec.push_back(27);

	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(30); // 30이 세번 반복

	vec.push_back(40);
	vec.push_back(50);

	cout << "vec ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	
	auto iter = search_n(vec.begin(), vec.end(), 3, 30);
	if (iter != vec.end())
	{
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}
	cout << endl;

	cout << "조건자를 사용한 경우" << endl;
	iter = search_n(vec.begin(), vec.end(), 3, 30, Pred);
	if (iter != vec.end())
	{
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	return 0;
}
// [출력 결과]
// vec 10 30 30 27 30 30 30 40 50
// iter : 30
// iter - 1 : 27
// iter + 1 : 30
// 
// 조건자를 사용한 경우
// iter : 30
// iter - 1 : 10
// iter + 1 : 30
