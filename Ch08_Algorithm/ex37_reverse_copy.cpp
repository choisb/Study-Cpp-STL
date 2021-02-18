// reverse_copy() 알고리즘 예제
// 뒤집힌 순차열을 목적지 순차열로 복사하고자 한다면 reverse_copy() 알고리즘을 사용
// p = reverse_copy(b,e,t)는 구간[b,e)의 순차열을 뒤집어 목적지 순차열 [t,p)에 저장한다.

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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(6);

	reverse_copy(vec1.begin(), vec1.end(),vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30 40 50 60
// vec2: 60 50 40 30 20 10
