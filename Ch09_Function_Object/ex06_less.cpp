// STL���� �����ϴ� less<T> �Լ����� 4���� ������
// ����� ���� MyLess<T> �ۼ� �� ��� ��
//
// [��� ���]
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1

#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct MyLess
{
	bool operator() (const T& left, const T& right) const
	{
		return left < right;
	}
};

int main()
{
	less<int> oLess;
	// 1. oLess ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��
	cout << oLess(10, 20) << endl;
	// 2. oLess ��ü�� 10, 20�� �� true. ����� ȣ��
	cout << oLess.operator()(10, 20) << endl;

	// 3. �ӽ� ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��(�Ϲ��� ���)
	cout << less<int>() (10, 20) << endl;
	// 4. �ӽ� ��ü�� 10, 20�� �� true. ����� ȣ��
	cout << less<int>().operator()(10, 20) << endl;


	MyLess<int> oMyLess;
	// 1. oMyLess ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��
	cout << oMyLess(10, 20) << endl;
	// 2. oMyLess ��ü�� 10, 20�� �� true. ����� ȣ��
	cout << oMyLess.operator()(10, 20) << endl;

	// 3. �ӽ� ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��(�Ϲ��� ���)
	cout << MyLess<int>() (10, 20) << endl;
	// 4. �ӽ� ��ü�� 10, 20�� �� true. ����� ȣ��
	cout << MyLess<int>().operator()(10, 20) << endl;

	return 0;
}