#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "20���� ���� ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(less<int>(), placeholders::_1, 20)) << endl;

	cout << "20���� �۰ų� ���� ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(less_equal<int>(), placeholders::_1, 20)) << endl;

	cout << "20���� ū ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(greater<int>(), placeholders::_1, 20)) << endl;

	cout << "20���� ũ�ų� ���� ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(greater_equal<int>(), placeholders::_1, 20)) << endl;

	cout << "20�� ���� ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(equal_to<int>(), placeholders::_1, 20)) << endl;

	cout << "20�� �ٸ� ������ ����: " << count_if(vec1.begin(), vec1.end(), bind(not_equal_to<int>(), placeholders::_1, 20)) << endl;


	return 0;
}