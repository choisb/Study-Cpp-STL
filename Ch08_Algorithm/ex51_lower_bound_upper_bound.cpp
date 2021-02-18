// lower_bound(), upper_bound() 알고리즘 예제
// 순차열에서 같은 원소를 찾기 위해 연관 컨테이너의 lower_bound(), upper_bound() 멤버 함수와 비슷한 알고리즘이 필요하다면
// lower_bound(), upper_bound() 알고리즘을 사용한다.
// p = lower_bound(b,e,x)는 구간 [b,e)의 순차열에서 x 원소와 같은 첫 원소의 반복자를 반환
// p = upper_bound(b,e,x)는 구간 [b,e)의 순차열에서 x 원소와 같은 마지막 원소의 반복자를 반환
// 찾고자 하는 원소가 있는 순차열이 기본 정렬 기준 less가 아니라면 조건자 버전의 lower_bound(), upper_bound()를 사용해야한다.

// [출력 결과]
// vec1: 10 20 30 30 30 40 50 60
// 30 원소의 순차열 [iter_lower, iter_upper): 30 30 30

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

	auto iter_lower = lower_bound(vec1.begin(), vec1.end(), 30);
	auto iter_upper = upper_bound(vec1.begin(), vec1.end(), 30);

	cout << "30 원소의 순차열 [iter_lower, iter_upper): ";
	for (auto iter = iter_lower; iter != iter_upper; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



