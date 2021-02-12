// copy() 알고리즘 예제
// copy() 알고리즘은 순차열에서 다른 순차열로 원소를 복사할때 사용한다.
// copy(b, e, t) 알고리즘은 구간 [b, e)의 순차열을 구간 [t, t+(e-b))의 순차열로 모두 복사한다.
// 복사가 진행될 때 기본적으로는 덮어쓰기 모드로 동작함.
// 삽입 모드로 동작하기 위해서는 반복자 어댑터(insert_iterator)등을 사용해야 한다.
// 덮어쓰기 모드로 동작하기 위해서는 반드시 목적지의 원소 개수가 대상 원소의 개수 이상으로 존재해야 한다.

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
	vec1.push_back(40);
	vec1.push_back(50);

	vector<int> vec2(7); // copy를 위해서 size 7인 vector 생성

	auto iter = copy(vec1.begin(), vec1.end(), vec2.begin());
	cout << "vec2의 마지막 원소: " << *(iter - 1) << endl;

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec2의 마지막 원소 : 50
// vec1 : 10 20 30 40 50
// vec2 : 10 20 30 40 50 0 0