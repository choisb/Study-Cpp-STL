// replace_if() 알고리즘 예제
// 사용자가 지정한 조건에 맞는 원소를 수정하려면 replace_if() 알고리즘을 사용할 수 있다.
// replace(b,e,f,x2) 알고리즘은 구간 [b,e)의 원소중 f(*p)가 참인 원소를 x2로 수정
// 여기서 f는 단항 조건자이다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 30 <= n && n <= 50;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(50);
	vec.push_back(60);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	//replace_if
	cout << "30 이상 50 이하의 원소를 0으로 replace! " << endl;
	replace_if(vec.begin(), vec.end(), Pred, 0);


	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 10 20 30 40 30 30 50 60
// 30 이상 50 이하의 원소를 0으로 replace!
// vec : 10 20 0 0 0 0 0 60