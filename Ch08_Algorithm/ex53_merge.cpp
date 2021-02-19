// merge() 알고리즘 예제
// 정렬된 두 순차열을 하나의 목적지 순차열로 합병하려면 merge()알고리즘 사용
// p = merge(b,e,b2,e2,t) 알고리즘은 구간 [b,e)의 순차열과 구간 [b2,e2)의 순차열을 목적지 순차열 [t,p)로 합병
//
// 정렬기준에 따라서 조건자를 사용할 수도 있다.

// [출력 결과]
// vec1: 20 30 40 50 60
// vec2: 10 40 50 80
// vec3: 0 0 0 0 0 0 0 0 0 0 0 0
// vec1: 20 30 40 50 60
// vec2: 10 40 50 80
// vec3: 10 20 30 40 40 50 50 60 80 0 0 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(20);
	vec1.push_back(30);
	// vec1.push_back(100); 정렬되어있지 않다면 오류 발생. 
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(40);
	vec2.push_back(50);
	vec2.push_back(80);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(12);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// vec1순차열과 vec2순차열을 합쳐서 vec3에 저장
	auto iter_end = merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}