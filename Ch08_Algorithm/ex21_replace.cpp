// replace() 알고리즘 예제
// 순차열의 특정 원소를 다른 값으로 수정하고자 할때 replace()알고리즘을 사용한다.
// replace(b,e,x,x2) 알고리즘은 구간 [b,e)의 x 원소를 x2로 수정

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	//replace
	cout << "30을 0으로 replace! " << endl;
	replace(vec.begin(), vec.end(), 30, 0);


	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 10 20 30 40 30 30 50 60
// 30을 0으로 replace!
// vec : 10 20 0 40 0 0 50 60