// find(), find_if() 알고리즘의 예제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 35 < n;
}

int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	// 구간 [Vec.begin(), Vec.end())에서 20을 찾아서 반복자 반환
	auto iter = find(Vec.begin(), Vec.end(), 20);
	if (iter != Vec.end())
		cout << *iter << "을 찾았다!" << endl;

	// 구간 [Vec.begin(), Vec.end())에서 35보다 큰 원소의 첫번째 원소 반환
	iter = find_if(Vec.begin(), Vec.end(), Pred);
	if (iter != Vec.end())
		cout << "순차열에서 35보다 큰 첫 번째 원소: " << *iter << endl;

	return 0;
}