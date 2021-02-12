// fill(), fill_n() 알고리즘 예제
// fill(), fill_n() 알고리즘은 순차열을 특정 값으로 채우기 위해서 사용.
// fill(b, e, x) 알고리즘은 순차열 [b,e)를 x로 채운다.
// fill_n(b, n, x) 알고리즘은 순차열 [b, b+n)을 x로 채운다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// 구간 [v.begin(), v.end())의 모든 원소를 0으로 채움
	fill(vec.begin(), vec.end(), 0);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// 구간 [vec.begin(), vec.begin() + 3)의 모든 원소를 55로 채움
	fill_n(vec.begin(), 3, 55);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 0 0 0 0 0
// vec : 55 55 55 0 0