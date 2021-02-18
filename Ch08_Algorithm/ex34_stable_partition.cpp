// stable_partition() 알고리즘 예제
// partition()알고리즘은 분류 과정에서 원소들의 상대적 순서가 뒤섞인다.
// 원소들의 상대적 순서를 유지하기 위해서는 stable_partition()알고리즘 사용.
// 사용법은 partition()알고리즘과 동일

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return n < 40;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(70);
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(50);
	vec1.push_back(30);
	vec1.push_back(20);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// 원소의 상대적 순서를 유지하며 40 원소를 기준으로 미만과 이상을 분류
	auto iter_sep = stable_partition(vec1.begin(), vec1.end(), Pred);

	cout << "40미만의 순차열: ";
	for (auto iter = vec1.begin(); iter != iter_sep; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "40이상의 순차열: ";
	for (auto iter = iter_sep; iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	return 0;
}
// [출력 결과]
// vec1: 70 10 20 40 60 70 50 30 20
// 40미만의 순차열 : 10 20 30 20
// 40이상의 순차열 : 70 40 60 70 50
