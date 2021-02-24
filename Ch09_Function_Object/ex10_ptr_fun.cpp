// ptr_fun 예제 (`C++11` 부터 사용하지 않고, `C++17` 부터 삭제됨)
// 함수 포인터 어뎁터를 활용해서 일반함수 Pred를 함수객체로 변환하기 위하여 사용
// 가령 일반 함수Pred 를 not1() 어뎁터에 적용하기 위해서는 
// 일반 함수 Pred를 함수 포인터 어뎁터로 함수객체로 변환 후 not1() 어뎁터를 적용해야 했다.
//
// C++17 이후부터는 별도의 변환과정 없이 not_fn()에 일반함수를 바로 적용할 수 있다.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
using namespace std;

bool Pred(int n)
{
	return 30 <= n && n <= 40;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "30이상 40이하의 원소 개수: " << count_if(vec1.begin(), vec1.end(), Pred) << endl;
	
	//C++17 이전 함수 포인터 어뎁터를 활용해서 일반함수 Pred를 함수객체로 변환하여
	//cout << "30이상 40이하가 아닌 원소 개수: " << count_if(vec1.begin(), vec1.end(), (ptr_fun(Pred))) << endl;

	//C++17 이후
	cout << "30이상 40이하가 아닌 원소 개수: " << count_if(vec1.begin(), vec1.end(), not_fn(Pred)) << endl;
}