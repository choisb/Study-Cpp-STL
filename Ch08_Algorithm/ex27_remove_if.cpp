// remove_if() 알고리즘 예제
// 조건에 따라 원소를 제거하고자 한다면 조건자 remove_if() 알고리즘 사용.
// p = remove(b,e,f)는 구간 [b,e)의 순차열에서 f(*p)가 참인 원소모두 삭제한다.
// 나머지는 기능은 remove()와 동일

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
	vec1.push_back(40);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(30);
	vec1.push_back(80);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//remove() 알고리즘
	auto iter_end = remove_if(vec1.begin(), vec1.end(), Pred);
	cout << endl << "remove_if(vec1.begin(), vec1.end(), Pred);" << endl << endl;
	// remvoe 후 [vec1.begin(), vec1.end()) 순차열
	// [iter_end, vec1.end()) 구간에서는 30이 남아있는 것을 확인할 수 있다.
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	// remove 후 [vec1.begin(), iter_end()) 순차열
	cout << "[vec1.begin(), iter_end()): ";
	for (auto iter = vec1.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//erase() 멤버함수
	vec1.erase(iter_end, vec1.end());

	cout << endl << "vec1.erase(iter_end, vec1.end());" << endl << endl;
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	return 0;
}
// [출력 결과]
// [vec1.begin(), vec1.end()): 10 40 20 30 40 30 40 30 50 60 70 30 80 | size : 13
// 
// remove(vec1.begin(), vec1.end(), Pred);
// 
// [vec1.begin(), vec1.end()): 10 20 60 70 80 30 40 30 50 60 70 30 80 | size : 13
// [vec1.begin(), iter_end()): 10 20 60 70 80 | size : 13
// 
// vec1.erase(iter_end, vec1.end());
// 
// [vec1.begin(), vec1.end()): 10 20 60 70 80 | size : 5