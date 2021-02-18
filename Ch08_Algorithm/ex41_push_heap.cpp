// push_heap() 알고리즘 예제
// push_make() 을 사용해서 힙으로 만들어진 순차열에 원소를 추가하기 위해서는 push_heap()알고리즘 사용
// push_heap() 알고리즘은 일반적으로 멤버 함수 push_back()과 함께 사용된다.
// push_heap(b,e) 알고리즘은 구간 [b,e)의 가장 마지막 원소를 부모 노드와 비교해가며 힙 연산을 수행하기 때문이다.
// 
// 즉, push_back()으로 힙의 가장 마지막에 원소를 추가하고, push_heap()으로 마지막 원소의 자리를 찾아주면서 전체적으로 힙 구조를 유지한다.

// [출력 결과]
// vec1: 10 20 30 40 50 60 70 80
// make_heap(vec1.begin(), vec1.end());
// vec1: 80 50 70 40 10 60 30 20
// vec1.push_back(35);
// vec1: 80 50 70 40 10 60 30 20 55
// push_heap(vec1.begin(), vec1.end());
// vec1: 80 55 70 50 10 60 30 20 40

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
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	make_heap(vec1.begin(), vec1.end());

	cout << "make_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// 새로운 원소 추가
	vec1.push_back(55);
	cout << "vec1.push_back(55);" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// push_heap()
	push_heap(vec1.begin(), vec1.end());
	cout << "push_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;


	return 0;
}

