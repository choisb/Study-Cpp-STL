// equal_range() 알고리즘 예제
// 순차열에서 찾는 원소의 반복자 쌍(구간)을 얻고자 한다면 equal_range() 알고리즘을 사용한다.
// pair(p1, p2) = equal_range(b,e,x)는 
// 구간[b,e)의 순차열에서 x와 같은 원소들이 이루고 있는 순차열 구간의 반복자 쌍 (p1, p2)를 반환
// 순차열의 정렬기준이 less 조건자가 아니라면 조건자 버전의 equal_range() 사용

// [출력 결과]
// vec1: 10 20 30 30 30 40 50 60
// 30 원소의 순차열 [iter_pair.first, iter_pair.second) : 30 30 30
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	auto iter_pair = equal_range(vec1.begin(), vec1.end(), 30);

	cout << "30 원소의 순차열 [iter_pair.first, iter_pair.second) : ";
	for (auto iter = iter_pair.first; iter != iter_pair.second; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



