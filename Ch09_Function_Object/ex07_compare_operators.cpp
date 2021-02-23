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

	cout << "20보다 작은 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(less<int>(), placeholders::_1, 20)) << endl;

	cout << "20보다 작거나 같은 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(less_equal<int>(), placeholders::_1, 20)) << endl;

	cout << "20보다 큰 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(greater<int>(), placeholders::_1, 20)) << endl;

	cout << "20보다 크거나 같은 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(greater_equal<int>(), placeholders::_1, 20)) << endl;

	cout << "20과 같은 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(equal_to<int>(), placeholders::_1, 20)) << endl;

	cout << "20과 다른 원소의 개수: " << count_if(vec1.begin(), vec1.end(), bind(not_equal_to<int>(), placeholders::_1, 20)) << endl;


	return 0;
}