// inplace_merge() 알고리즘 예제
// 하나의 순차열이 두 구간으로 정려돼 있다면 inplace_merge(b,m,e)을 사용하여 하나의 구간으로 정렬 가능
// inplace_merge(b,m,e) 알고리즘은 정렬된 [b,m)의 순차열과 정렬된 [m,e)의 순차열을 정렬된 [b,e) 순차열로 합병
// 정렬기준에 따라서 조건자를 사용할 수 있다.

// [출력 결과]
// vec1: 10 20 40 60 70 80 10 30 40 50
// vec1: 10 10 20 30 40 40 50 60 70 80

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(80);

	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	auto middle = vec1.begin() + 6;

	inplace_merge(vec1.begin(), middle, vec1.end());
	
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}



