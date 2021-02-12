// copy_backward() 알고리즘 예제
// copy_backward() 알고리즘은 copy() 알고리즘과 마찬가지로 순차열에서 다른 순차열로 원소를 복사할때 사용한다.
// 다만 copy() 알고리즘과는 다르게 뒤에서부터 원소를 복사한다.
// 뒤에서 부터 원소를 복사하기 때문에 copy()와 다르게 목적지 벡터의 시작점이 아닌 끝점을 전달해야한다.

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

	vector<int> vec2(7); // copy를 위해서 size가 7인 vector 생성

	auto iter = copy_backward(vec1.begin(), vec1.end(), vec2.end());
	cout << "vec2의 첫 원소: " << *iter << endl;

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec2의 첫 원소 : 10
// vec1 : 10 20 30 40 50
// vec2 : 0 0 10 20 30 40 50