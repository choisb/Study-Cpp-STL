// remove_copy_if() 알고리즘 예제
// remove_copy() 알고리즘을 조건자 버전으로 사용하기 위해서 remove_copy_if() 알고리즘을 사용한다.
// p=remove_copy(b,e,t,f) 로 사용하고 remove_if()와 remove_copy()의 기능이 합쳐진 것으로 보면 된다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int n)
{
	return 30 <= n && n <= 50;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(30);
	vec1.push_back(70);
	vec1.push_back(80);

	vector<int> vec2(8);


	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//remove_copy() 알고리즘
	auto iter_end = remove_copy_if(vec1.begin(), vec1.end(), vec2.begin(), Pred);
	cout << endl << "remove_copy_if(vec1.begin(), vec1.end(), vec2.begin(), Pred);" << endl << endl;
	// remvoe 후 [vec1.begin(), vec1.end()) 순차열
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	// remove 후 [vec2.begin(), vec2.end()) 순차열
	cout << "[vec2.begin(), vec2.end()): ";
	for (auto v : vec2)
		cout << v << " ";
	cout << " | size: " << vec2.size();
	cout << endl;

	cout << "[vec2.begin(), iter_end): ";
	for (auto iter = vec2.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec2.size();
	cout << endl;

	return 0;
}
// [출력 결과]
// [vec1.begin(), vec1.end()): 10 20 30 40 50 30 70 80 | size : 8
// 
// remove_copy_if(vec1.begin(), vec1.end(), vec2.begin(), Pred);
// 
// [vec1.begin(), vec1.end()): 10 20 30 40 50 30 70 80 | size : 8
// [vec2.begin(), vec2.end()): 10 20 70 80 0 0 0 0 | size : 8
// [vec2.begin(), iter_end): 10 20 70 80 | size : 8