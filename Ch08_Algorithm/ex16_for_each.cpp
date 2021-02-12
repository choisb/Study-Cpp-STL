// for_each() 알고리즘 예제
// for_each() 알고리즘은 원소를 수정하는 알고리즘으로도 사용할 수 있다.
// for_each(b, e, f)는 구간 [b, e)의 반복자가 p라면 모든 원소에 f(*p)를 적용.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 매개변수로 전달받은 원소를 수정하기 위해 &(레퍼런스)를 사용
void Func(int& r)
{
	r += 5;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	for_each(vec.begin(), vec.end(), Func);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 10 20 30 40 50
// vec: 15 25 35 45 55