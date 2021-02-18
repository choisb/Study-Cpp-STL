// includes() 알고리즘 예제
// 한 순차열이 다른 순차열의 부분 집합인지 판단하려면 includes() 알고리즘을 사용
// includes(b,e,b2,e2) 알고리즘은 구간 [b2,e2)의 원소가 구간 [b,e)의 원소에 포함되면 true, 아니면 false 반환
// 조건자 버전은 f를 비교에 사용.

// [출력 결과]
// vec1: 10 20 30 40 50
// vec2: 10 20 30
// vec3: 10 20 60
// vec2는 vec1의 부분 집합
// vec3는 vec1의 부분 집합이 아님

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
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3;
	vec3.push_back(10);
	vec3.push_back(20);
	vec3.push_back(60);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	if (includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()))
		cout << "vec2는 vec1의 부분 집합" << endl;
	else
		cout << "vec2는 vec1의 부분 집합이 아님" << endl;

	if (includes(vec1.begin(), vec1.end(), vec3.begin(), vec3.end()))
		cout << "vec3는 vec1의 부분 집합" << endl;
	else
		cout << "vec3는 vec1의 부분 집합이 아님" << endl;


	return 0;
}



