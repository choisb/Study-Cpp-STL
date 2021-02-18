// partition() 알고리즘 예제
// 순차열의 원소를 특정 조건에 따라 분류하고자 한다면 partition()알고리즘을 사용
// p = partition(b,e,f) 알고리즘은 구간 [b,e)의 반복자가 p일 때 
// f(*p)가 참인 원소는 [b, p) 순차열에
// f(*p)가 거짓인 원소는 [p,e) 순차열로 분류
// 분류과정에서 퀵소트의 pivot값 처럼 f(*p)값을 기준으로 원소들 간의 swap을 통해서 분류하기 때문에 
// 원소들의 상대적 순서가 바뀌게 된다.
// 원소들의 상대적 순서를 유지하기 위해서는 stable_partition() 알고리즘을 사용한다.

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
	
	auto iter_sep = partition(vec1.begin(), vec1.end(), Pred);

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
// 40미만의 순차열 : 20 10 20 30
// 40이상의 순차열 : 60 70 50 40 70