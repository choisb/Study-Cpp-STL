// 조건자 버전의 unique() 알고리즘 예제
// unique() 알고리즘도 조건자를 사용할 수 있다.
// p = unique(b,e,f)알고리즘은 구간[b,e)의 반복자를 p라 하면 f(*p)가 참인 인접한 원소를 논리적으로 제거한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right)
{
	return abs(right - left) < 10;
}

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(11);
	vec1.push_back(30);
	vec1.push_back(32);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	auto iter_end = unique(vec1.begin(), vec1.end(), Pred);
	cout << endl << "unique(vec1.begin(), vec1.end(), Pred);" << endl << endl;
	// unique 후 [vec1.begin(), vec1.end()) 순차열
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;
	// unique 후 [vec1.begin(), iter_end) 순차열
	cout << "[vec2.begin(), iter_end): ";
	for (auto iter = vec1.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	return 0;
}
// [출력 결과]
// [vec1.begin(), vec1.end()): 10 11 30 32 40 50 | size : 6
// 
// unique(vec1.begin(), vec1.end(), Pred);
// 
// [vec1.begin(), vec1.end()) : 10 30 40 50 40 50 | size : 6
// [vec2.begin(), iter_end): 10 30 40 50 | size : 6
