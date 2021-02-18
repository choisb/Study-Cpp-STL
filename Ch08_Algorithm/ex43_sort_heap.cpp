// sort_heap() 알고리즘 예제
// 순차열이 힙 상태일때 힙을 정렬하기 위해서는 sort_heap()을 사용.
// sort_heap()을 사용하기 위해서는 순차열이 반드시 힙 상태여야 한다.



// [출력 결과]
// vec1: 10 20 30 40 50 60 70 80
// make_heap(vec1.begin(), vec1.end());
// vec1: 80 50 70 40 10 60 30 20
// sort_heap(vec1.begin(), vec1.end());
// vec1: 10 20 30 40 50 60 70 80

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

	// 힙상태의 순차열을 정렬한다.
	sort_heap(vec1.begin(), vec1.end());
	cout << "sort_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}

