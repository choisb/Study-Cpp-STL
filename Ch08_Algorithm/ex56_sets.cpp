// 집합과 관련된 알고리즘 예제
// set_intersection(): 두 순차열의 교집합을 구할 때 사용
// set_difference(): 두 순차열의 차집합을 구할 때 사용
// set_symmetric_difference(): 두 순차열의 대칭 차집합을 구할 때 사용
// 세 알고리즘 모두 덮어쓰기 모드로 동작한다.
//
// 정렬 기준에 따라서 조건자 버전 사용.

// [출력 결과]
// vec1: 10 30 40 70 80
// vec2: 10 20 50 60 70 90
// 교집합: 10 70
// 차집합: 30 40 80
// 대칭 차집합: 20 30 40 50 60 80 90

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(50);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(90);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(12);

	// set_intersection() 교집합
	auto iter_end = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "교집합: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;
	
	// set_difference() 차집합
	iter_end = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "차집합: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;

	// set_symmetric_difference() 대칭 차집합
	iter_end = set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "대칭 차집합: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



