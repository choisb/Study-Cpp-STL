// �Լ��� ������ accumulate() �˰��� ����
// �Լ����� ����ϸ� accumulate() �˰������� ���� �پ��� �۾��� �� �� �ִ�.

// [��� ���]
// vec1: 1 2 3 4 5
// 15
// 65
// 1200

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
struct MyPlus
{
	T operator() (const T& left, const T& right)
	{
		return left + right;
	}
};
int main()
{
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << accumulate(vec1.begin(), vec1.end(), 0, MyPlus<int>()) << endl;
	cout << accumulate(vec1.begin(), vec1.end(), 50, MyPlus<int>()) << endl;
	cout << accumulate(vec1.begin(), vec1.end(), 10, multiplies<int>()) << endl;


	return 0;
}



