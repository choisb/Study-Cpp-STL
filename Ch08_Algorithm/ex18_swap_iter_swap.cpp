// swap(), iter_swap() 알고리즘 예제
// 값을 교환하거나 반복자가 가리키는 값을 교환하고자 하면 swap()과 iter_swap()을 사용할 수 있다.
// swap(a, b)는  a와 b를 교환한다.
// iter_swap(p,q)는 반복자가 가리키는 *p와 *q를 교환한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int a = 10, b = 20;

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);

	cout << " a= " << a << ", " << "b = " << b << endl;
	swap(a, b);
	cout << " a= " << a << ", " << "b = " << b << endl;

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	auto p = vec.begin();
	auto q = vec.begin() + 1;

	iter_swap(p, q);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// a = 10, b = 20
// a = 20, b = 10
// vec: 10 20
// vec : 20 10