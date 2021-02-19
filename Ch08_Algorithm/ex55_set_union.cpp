// set_union() 알고리즘 예제
// 정렬된 두 순차열의 합집합을 구하려면 set_union()을 사용한다.
// p = set_union(b,e,b2,e2,t) 알고리즘은 구간 [b,e)와 구간 [b2,e2)의 순차열을 합집합하여 목적지 순차열 [t,p)에 저장한다.
// (합집합이기 때문에 중복된 값을 제외)
//
// 정렬 기준에 따라서 조건자를 활용할 수도 있다.
//
// [출력 결과]
// vec1: 10 20 30 40 50
// vec2: 30 50 60 70 80
// vec3: 10 20 30 40 50 60 70 80 0 0

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
	

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(30);
	vec2.push_back(50);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(80);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int>vec3(10);
	auto iter_end = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}

