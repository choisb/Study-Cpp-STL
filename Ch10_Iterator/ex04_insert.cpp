// 삽입 반복자 어댑터 insert() 예제

// [출력 결과]
// vec1: 10 20 30 40 50
// vec2: 10 20 30 40 50

#include <iostream>
#include <vector>
#include <iterator>
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

	vector<int> vec2;
	// copy(vec1.begin(), vec1.end(), vec2.begin()); 덮어쓰기 모드로 동작하기 때문에 size가 0인 vec2에서 에러 발생.

	// 삽입모드
	copy(vec1.begin(), vec1.end(), inserter<vector<int>>(vec2, vec2.begin()));

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



