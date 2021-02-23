// bind ����
// binder1st, binder2nd�� ���� ���� �Լ� ��ü�� ���� �Լ� ��ü�� ��ȯ�ϴ� ���δ�(�����)������ C++11 ���� ������� �ʱ� �����߰�, C++17���ʹ� ������.
// ��� bind() �Լ��� ��ü
//
// std::bind(addAndPrint, 10, std::placeholders::_1)�� 
// addAndPrint(int, int) �Լ��� 
// ù ��° �Ķ���ʹ� 10, 
// �� ��° �Ķ���ʹ� func2 �� ȣ���� �� ������ ù��° ����(std::placeholders::_1)�� �־��شٴ� �ǹ�
//
// STL�� ���� �Լ��ڿ� 
// ����� ���� ���� �Լ��ڸ�
// bind �Լ��� ���ؼ� ���� �Լ��ڷ� ����ϴ� ����
// bin


// [��� ���]
// vec1: 10 20 30
// vec2: 1 2 3
// vec3: 11 22 33
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct MyPlus
{
	// ����� ���� �Լ��ڿ��� binder1st<int>�� ����ϱ� ���ؼ��� �Ʒ��� ���� ���ǰ� �ʿ��ϴ�.

	T operator() (const T& left, const T& right) const
	{
		return left + right;
	}
};

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);


	vector<int> vec3(3); // size: 3�� vector ����

	// STL ������ plus<int> ��� C++14 ����
	//transform(vec1.begin(), vec1.end(), vec3.begin(), binder1st<plus<int>>(plus<int>(), 100));

	// STL ������ plus<int> ��� C++17 �̻�
	//transform(vec1.begin(), vec1.end(), vec3.begin(), bind(plus<int>(), placeholders::_1, 100));

	// ����� ���� ������ MyPlus<int> ��� C++17 �̻�
	transform(vec1.begin(), vec1.end(), vec3.begin(), bind(plus<int>(), placeholders::_1, 100));

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;



	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}