// reverse() 알고리즘 예제
// reverse() 알고리즘을 사용하면 순차열을 뒤집을 수 있다.
// reverse(b,e) 알고리즘은 순차열 [b,e)구간의 원소들을 역순으로 뒤집는다.

#include <iostream>
#include <vector>
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
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	reverse(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30 40 50 60
// vec1: 60 50 40 30 20 10