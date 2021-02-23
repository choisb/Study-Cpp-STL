// STL �� ���� ������ ȣ�� �� 
// ����� �� ���� ������ ���� ����
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
struct MyLogical_and
{
	bool operator() (const T& left, const T&right) const
	{
		return left && right;
	}
};

int main()
{
	int n = 30;

	// STL ���� �� ���� ������
	logical_and<bool> oAnd;
	// 1. oAnd ��ü�� �Ϲ��� ȣ��
	cout << oAnd(greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 2. oAnd ��ü�� ����� ȣ��
	cout << oAnd.operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// 3. �ӽ� ��ü�� �Ϲ��� ȣ�� (�Ϲ����� ���)
	cout << logical_and<bool>() (greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 4. �ӽ� ��ü�� ����� ȣ��
	cout << logical_and<bool>().operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// ����� ���� �� ���� ������
	MyLogical_and<bool> oMyAnd;
	// 1. oMyAnd ��ü�� �Ϲ��� ȣ��
	cout << oMyAnd(greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 2. oMyAnd ��ü�� ����� ȣ��
	cout << oMyAnd.operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// 3. �ӽ� ��ü�� �Ϲ��� ȣ�� (�Ϲ����� ���)
	cout << MyLogical_and<bool>() (greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 4. �ӽ� ��ü�� ����� ȣ��
	cout << MyLogical_and<bool>().operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	return 0;
}