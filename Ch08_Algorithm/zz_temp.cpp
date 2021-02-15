// () 알고리즘 예제
// 

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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);
	vec2.push_back(40);
	vec2.push_back(30);
	vec2.push_back(30);
	vec2.push_back(50);
	vec2.push_back(60);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;


	return 0;
}
// [출력 결과]