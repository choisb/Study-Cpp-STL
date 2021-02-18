// next_permutation() 알고리즘 예제
// 원소의 순서를 순열처럼 변경할 때 next_permutation()과 prev_permutation()알고리즘을 사용
// next_permutation(b,e)는 구간 [b,e)의 순차열을 다음 순열의 순차열이 되게 한다.
// 마지막 순열이라면 false를 반환하며, 아니면 true를 반환한다.
// 이전 순열의 순차열이 되도록 하기 위해서는 prev_premutation(b,e)를 사용한다.
// 기본적으로 순열의 기준은 사전순이며, 사용자가 조건자를 사용하여 기준을 만들 수도 있다.

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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	while (next_permutation(vec1.begin(), vec1.end()))
	{
		cout << "next> ";
		cout << "vec1: ";
		for (auto v : vec1)
			cout << v << " ";
		cout << endl;
	}
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	prev_permutation(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	while (prev_permutation(vec1.begin(), vec1.end()))
	{
		cout << "prev> ";

		cout << "vec1: ";
		for (auto v : vec1)
			cout << v << " ";
		cout << endl;
	}
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30
// next > vec1: 10 30 20
// next > vec1: 20 10 30
// next > vec1: 20 30 10
// next > vec1: 30 10 20
// next > vec1: 30 20 10
// vec1 : 10 20 30
// vec1 : 30 20 10
// prev > vec1: 30 10 20
// prev > vec1: 20 30 10
// prev > vec1: 20 10 30
// prev > vec1: 10 30 20
// prev > vec1: 10 20 30
// vec1 : 30 20 10