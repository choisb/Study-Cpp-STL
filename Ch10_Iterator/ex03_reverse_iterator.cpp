// iterator와 reverse_iterator 사용법

// [출력 결과]
// iterator: 10 20 30 40 50
// reverse_iterator : 50 40 30 20 10

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "iterator : ";
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "reverse_iterator : ";
	for (vector<int>::reverse_iterator riter = vec1.rbegin(); riter != vec1.rend(); riter++)
		cout << *riter << " ";
	cout << endl;

	return 0;
}



