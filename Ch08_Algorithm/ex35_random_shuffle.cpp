// random_shuffle() 알고리즘 예제
// 순차열 원소의 순서를 랜덤으로 뒤섞고자 한다면 random_shuffle() 알고리즘 사용
// random_shuffle(b,e) 알고리즘은 구간 [b, e)의 순차열을 랜덤으로 뒤섞는다.
// 초기화를 위해서는 <cstdlib> 헤더의 srand() 사용

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
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

	// 랜덤 초깃값
	srand((unsigned)time(NULL));

	// 원소를 뒤섞는다.
	random_shuffle(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// 원소를 뒤섞는다.
	random_shuffle(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30 40 50 60
// vec1 : 40 50 20 30 60 10
// vec1 : 40 60 50 20 10 30
