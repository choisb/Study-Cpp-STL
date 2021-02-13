// merge() 알고리즘 예제
// 정렬된 두 순차열을 하나의 정렬된 순차열로 합병하기 위해서는 nmerge() 알고리즘을 사용한다.
// merge(b,e,b2,e2,t) 알고리즘은 정렬구간 [b,e)의 순차열과 구간 [b2, e2)의 순차열을
// [t, t+(e-b) + (e2 - b2))의 순차열로 합병 정렬한다.
// 주의할 점은 반드시 두 순차열은 정렬되어 있어야 한다. 정렬되어 있지 않다면 에러 발생.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(80);

	vector<int> vec2;
	vec2.push_back(20);
	vec2.push_back(40);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(90);

	vector<int> vec3(10);

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

	cout << "vec3(합병 순차열): " << *vec3.begin() << "~" << *(iter_end - 1) << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 30 50 60 80
// vec2 : 20 40 60 70 90
// vec3 : 10 20 30 40 50 60 60 70 80 90
// vec3(합병 순차열) : 10~90
