// 삽입 반복자의 back_inserter(), front_inserter() 예제

// [출력 결과]
// vec1: 10 20 30 40 50
// lt1: 1 2 3 10 20 30 40 50
// lt2: 50 40 30 20 10 1 2 3

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);

	list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);

	copy(vec1.begin(), vec1.end(), back_inserter<list<int>>(lt1));
	copy(vec1.begin(), vec1.end(), front_inserter<list<int>>(lt2));


	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "lt1: ";
	for (auto l : lt1)
		cout << l << " ";
	cout << endl;

	cout << "lt2: ";
	for (auto l : lt2)
		cout << l << " ";
	cout << endl;

	return 0;
}



