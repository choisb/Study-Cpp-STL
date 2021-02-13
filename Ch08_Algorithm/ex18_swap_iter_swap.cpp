// swap(), iter_swap() �˰��� ����
// ���� ��ȯ�ϰų� �ݺ��ڰ� ����Ű�� ���� ��ȯ�ϰ��� �ϸ� swap()�� iter_swap()�� ����� �� �ִ�.
// swap(a, b)��  a�� b�� ��ȯ�Ѵ�.
// iter_swap(p,q)�� �ݺ��ڰ� ����Ű�� *p�� *q�� ��ȯ�Ѵ�.


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
// [��� ���]
// a = 10, b = 20
// a = 20, b = 10
// vec: 10 20
// vec : 20 10