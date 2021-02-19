// partial_sum() 알고리즘 예제
// 순차열에서 현재 원소까지의 합을 구하고자 한다면 partial_sum()알고리즘 사용
// p = partial_sum(b,e,t) 알고리즘은 구간 [b,e)의 현재 원소까지의 ㅎ합(누적)을 목적지 순차열 [t,p)에 저장
//
// 순차열에서 현재 원소까지의 합 뿐만 아니라 사용자 연산을 수행하려면 함수류 버전의 partial_sum()알고리즘 사용
// p = partial_sum(b,e,t,f) 알고리즘은 구간 [b,e)의 현재 원소까지의 f 연산의 값을 목적지 순차열 [t,p)에 저장.
//
// [출력 결과]

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int MyMulti(int left, int right)
{
	return left * right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(5);
	
	auto iter_end = partial_sum(vec1.begin(), vec1.end(), vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	iter_end = partial_sum(vec1.begin(), vec1.end(), vec2.begin(), MyMulti);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}

