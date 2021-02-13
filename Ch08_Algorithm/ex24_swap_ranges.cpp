// swap_ranges() 알고리즘 예제
// 순차열과 순차열의 모든 원소를 교환하기 위해서는 swap_ranges() 알고리즘을 사용
// swap_ranges(b,e,b2) 알고리즘은 [b, e)의 순차열 구간[b2, b2 + (e-b))의 모든 원소를 교환.


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
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	vector<int> vec2;
	vec2.push_back(11);
	vec2.push_back(21);
	vec2.push_back(31);
	vec2.push_back(41);
	vec2.push_back(31);
	vec2.push_back(31);
	vec2.push_back(51);
	vec2.push_back(61);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	swap_ranges(vec1.begin(), vec1.end(), vec2.begin());

	cout << "swap_ranges()!" << endl;

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