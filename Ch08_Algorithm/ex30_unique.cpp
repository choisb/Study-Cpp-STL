// unique() 알고리즘 예제
// 순차열의 인접 원소를 유일하게 만들고자 한다면 unique() 알고리즘 사용
// p = unique(b,e)는 구간 [b,e)의 순차열을 인접한 중복 원소가 남지 않게 한다.
// 알고리즘 수행 후 순차열은 [b,q)가 된다.
// unique() 알고리즘도 원소를 논리적으로만 제거한다.
// 정렬 상태에서 unique()알고리즘을 수행한다면 모든 원소를 유일하게 만들 수 있다.


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
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	auto iter_end = unique(vec1.begin(), vec1.end());
	cout << endl << "unique(vec1.begin(), vec1.end());" << endl << endl;
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
// [vec1.begin(), vec1.end()): 10 20 30 30 40 40 30 30 50 60 | size : 10
// 
// unique(vec1.begin(), vec1.end());
// 
// [vec1.begin(), vec1.end()) : 10 20 30 40 30 50 60 30 50 60 | size : 10
// [vec2.begin(), iter_end): 10 20 30 40 30 50 60 | size : 10