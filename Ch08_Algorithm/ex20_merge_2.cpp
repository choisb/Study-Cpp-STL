// 조건자를 활용한 merge() 알고리즘 예제
// 만약 특정 정렬 기준에 의해 정렬된 상태라면 일반 버전의 merge() 알고리즘을 사용할 수 없다.
// 기본 merge() 알고리즘은 오름 차순 정렬 기준(less:<)를 전제로 동작한다.
// 조건자를 사용하는 경우는 아래와 같이 사용한다.
// merge(b,e,b2,e2,t,f)
// 여기서 f는 이항 조건자로 두 순차열의 특정 정렬 기준이다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct Greater
{
	bool operator() (const T& left, const T& right)const
	{
		return left > right;
	}
};

int main()
{
	vector<int> vec1;
	vec1.push_back(80);
	vec1.push_back(70);
	vec1.push_back(60);
	vec1.push_back(20);
	vec1.push_back(10);

	vector<int> vec2;
	vec2.push_back(90);
	vec2.push_back(70);
	vec2.push_back(50);
	vec2.push_back(30);
	vec2.push_back(20);

	vector<int> vec3(10);

	// 내림차순 기준의 merge()알고리즘
	auto iter_end = merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin(), Greater<int>());

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

	cout << "vec3(합병 순차열): " << *vec3.begin() << "~" << *(iter_end - 1) << endl;

	return 0;
}
// [출력 결과]
// vec1: 80 70 60 20 10
// vec2 : 90 70 50 30 20
// vec3 : 90 80 70 70 60 50 30 20 20 10
// vec3(합병 순차열) : 90~10