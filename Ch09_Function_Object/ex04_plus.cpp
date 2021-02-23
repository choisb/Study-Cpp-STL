// STL���� �����ϴ� plus<T> �Լ����� 4���� ������
// ����� ���� MyPlus<T> �ۼ� �� ��� ��
//
// [��� ���]
// 30
// 30
// 30
// 30
// 30
// 30
// 30
// 30

#include <iostream>
#include <functional>
using namespace std;
template<typename T>
struct MyPlus : public binary_function<T, T, T> // ����� ������ �����ϰ�
{
	T operator() (const T& left, const T& right) const
	{
		return left + right;
	}
};
int main()
{
	plus<int> oPlus;
	// 1. oPlus ��ü�� 10, 20 ���ϱ�, �Ϲ��� ȣ��
	cout << oPlus(10, 20) << endl;
	// 2. oPlus��ü�� 10, 20 ���ϱ�, ����� ȣ��
	cout << oPlus.operator()(10, 20) << endl;

	// 3. �ӽ� ��ü�� 10, 20 ���ϱ�, �Ϲ��� ȣ��(�Ϲ����� ���)
	cout << plus<int>() (10, 20) << endl;
	// 4. �ӽ� ��ü�� 10, 20 ���ϱ�, ����� ȣ��
	cout << plus<int>().operator()(10, 20) << endl;


	// ����� ���� �Լ��� ��� ����


	MyPlus<int> oMyPlus;
	// 1. oMyPlus ��ü�� 10, 20 ���ϱ�, �Ϲ��� ȣ��
	cout << oMyPlus(10, 20) << endl;
	// 2. oMyPlus��ü�� 10, 20 ���ϱ�, ����� ȣ��
	cout << oMyPlus.operator()(10, 20) << endl;

	// 3. �ӽ� ��ü�� 10, 20 ���ϱ�, �Ϲ��� ȣ��(�Ϲ����� ���)
	cout << MyPlus<int>() (10, 20) << endl;
	// 4. �ӽ� ��ü�� 10, 20 ���ϱ�, ����� ȣ��
	cout << MyPlus<int>().operator()(10, 20) << endl;
	return 0;
}