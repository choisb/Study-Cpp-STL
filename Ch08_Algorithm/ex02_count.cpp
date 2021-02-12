// count() 알고리즘 예제
// 해당 원소의 개수를 int 값으로 반환

// count_if()를 사용하면 조건자를 활용해서 조건에 맞는 원소의 개수를 반환받을 수 있다.
// 이때 조건자는 원소 하나만 받는 단항 연산자를 사용한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 25 < n;
}
int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	Vec.push_back(30);
	Vec.push_back(30);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	// 구간 [v.begin(), v.end())에서 30 원소의 개수를 반환
	int n = count(Vec.begin(), Vec.end(), 30);
	cout << "30의 개수: " << n << endl;

	// 구간 [v.begin(), v.end())에서 Pred() 조건자를 만족하는 원소의 개수를 반환
	n = count_if(Vec.begin(), Vec.end(), Pred);
	cout << "25보다 큰 원소의 개수: " << n << endl;

	return 0;
}
// [출력 결과]
// 10 20 30 40 50 30 30
// 30의 개수 : 3
// 25보다 큰 원소의 개수 : 5
