// rotate_copy() 알고리즘 예제
// 순차열을 회전하여 목적지 순차열에 복사하려면 rotate_copy() 알고리즘 사용
// rotate(b,m,e,t) 알고리즘은 첫 원소와 마지막 원소가 연결된 것처럼 왼쪽으로 m-b만큼 회전하여 [t, t+(e-b)) 순차열로 복사

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
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(8);

	auto middle = vec1.begin() + 3;
	rotate_copy(vec1.begin(), middle, vec1.end(), vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30 40 50 60 70 80
// vec2: 40 50 60 70 80 10 20 30
