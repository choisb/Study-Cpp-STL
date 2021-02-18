// pop_heap() 알고리즘 예제
// 힙에서 루트(가장 큰 원소) 노드를 제거하기 위해서 pop_heap() 사용
// pop_heap(b,e) 알고리즘은 구간 [b,e)의 첫 원소를 가장 끝 원소와 교환한 후 힙이 유지되게 연산 수행
// 그냥 pop_heap()알고리즘만 사용할 경우 루트노드가 순차열 가장 끝으로 이동.
// 원소를 삭제하기 위해서는 멤버함수 pop_back()을 함께 사용.

// [출력 결과]
// vec1: 10 20 30 40 50 60 70 80
// make_heap(vec1.begin(), vec1.end());
// vec1: 80 50 70 40 10 60 30 20
// pop_heap(vec1.begin(), vec1.end());
// vec1: 70 50 60 40 10 20 30 80
// vec1.pop_back();
// vec1: 70 50 60 40 10 20 30

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

	// 루트노드를 힙에서 제외(순차열 가장 뒤로 보냄)
	pop_heap(vec1.begin(), vec1.end());
	cout << "pop_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	
	// 루트노드였던 원소 삭제
	vec1.pop_back();
	cout << "vec1.pop_back();" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}

