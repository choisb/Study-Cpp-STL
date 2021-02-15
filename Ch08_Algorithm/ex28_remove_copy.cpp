// remove_copy() 알고리즘 예제
// 순차열 원본을 변경하지 않고 특정 원소를 제거하여 목적지 순차열로 복사하고자 한다면 remove_copy() 알고리즘을 사용.
// p=remove_copy(b,e,t,x)는 구간 [b,e) 순차열에서 *p==x인 원소를 제외한 원소를 순차열 [t,p)에 복사. (덮어쓰기 모드로 동작)

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
	auto iter_end = remove_copy(vec1.begin(), vec1.end(), vec2.begin(), 30);
	cout << endl << "remove_copy(vec1.begin(), vec1.end(), vec2.begin(), 30);" << endl << endl;
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
// remove(vec1.begin(), vec1.end(), Pred);
// 
// [vec1.begin(), vec1.end()): 10 20 30 40 50 30 70 80 | size : 8
// [vec2.begin(), vec2.end()): 10 20 40 50 70 80 0 0 | size : 8
// [vec2.begin(), iter_end): 10 20 40 50 70 80 | size : 8