// 조건자를 사용하는 heap()알고리즘 예제
// 앞서 다뤘던 heap() 관련 알고리즘들은 모두 조건자로 사용할 수도 있다.


// [출력 결과]
// vec1: 80 70 60 50 40 30 20 10
// make_heap(vec1.begin(), vec1.end(), greater<int>());
// vec1: 10 40 20 50 80 30 60 70
// vec1.push_back(25);
// vec1: 10 40 20 50 80 30 60 70 25
// push_heap(vec1.begin(), vec1.end(), greater<int>());
// vec1: 10 25 20 40 80 30 60 70 50

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(80);
	vec1.push_back(70);
	vec1.push_back(60);
	vec1.push_back(50);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(20);
	vec1.push_back(10);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	make_heap(vec1.begin(), vec1.end(),greater<int>());

	cout << "make_heap(vec1.begin(), vec1.end(), greater<int>());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// 새로운 원소 추가
	vec1.push_back(25);
	cout << "vec1.push_back(25);" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// push_heap()
	push_heap(vec1.begin(), vec1.end(), greater<int>());
	cout << "push_heap(vec1.begin(), vec1.end(), greater<int>());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;


	return 0;
}

