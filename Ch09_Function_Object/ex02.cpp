// [출력 결과]
// vec1: 10 20 30
// vec2: 1 2 3
// vec3: 11 22 33
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct MyPlus
{
	T operator() (const T& left, const T& right) const
	{
		return left + right;
	}
};

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);

	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);

	vector<int> vec3(3); // size: 3인 vector 생성

	// STL 조건자 plus<int> 사용
	//transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), plus<int>());

	// 사용자 정의 MyPlus<int> 사용
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), MyPlus<int>());


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