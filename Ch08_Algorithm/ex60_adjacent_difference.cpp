// adjacent_difference() 알고리즘 예제
// 순차열에서 원소들간의 차를 구하기 위해서는 adjacent_difference() 알고리즘을 사용
// adjacent_difference(b,e,t) 알고리즘은 구간 [b,e)의 반복자가 p일때 (*p - *(p-1)) 연산을 목적지 순차열 [t,p)에 저장
//
// 인접 원소와의 사용자 정의 연산을 수행하려면 함수류 버전 adjacent_difference() 알고리즘
// p = adjacent_difference(b,e,t,f) 알고리즘은 구간 [b,e)의 반복자가 p라면 f(*p, *(p-1)) 연산을 목적지 순차열 [t,p)에 저장

// [출력 결과]
// vec1: 10 20 40 30 50 60 90 20
// vec2: 10 10 20 -10 20 10 30 -70
// vec2: 10 30 60 70 80 110 150 110

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int MyPlus(int left, int right)
{
	return left + right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(90);
	vec1.push_back(20);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(8);

	auto iter_end = adjacent_difference(vec1.begin(), vec1.end(), vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// 사용자 정의 연산을 활용하는 adjacent_difference() 알고리즘
	iter_end = adjacent_difference(vec1.begin(), vec1.end(), vec2.begin(), MyPlus);
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;
	return 0;
}

