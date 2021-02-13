// transform() 알고리즘 예제
// 순차열의 모든 원소에 사용자의 정책을 반영하려면 일반적으로 for_each(), transform() 알고리즘을 사용한다.
// 이 둘의 차이는 for_each()는 원본의 순차열에 변경사항을 저장하는 반면
// transform() 알고리즘은 목적지의 순차열에 변경사항을 저장한다. (덮어쓰기 모드로)
// transform(b,e,b2,f)는 순차열 구간[b, e)에 f(*p)한 값을 순차열 구간[b2, b2 +(e-b))에 저장한다.
//
// 만약 두 순차열의 값을 연산하여 제 3의 순차열에 저장하기 위해서는 transform(b,e,b2,t,f)를 사용한다.
// 이는 구간 [b, e) 순차열과 [b2, b2+(e-b))의 순차열의 반복자를 p, q라 할때 f(*p, *q)한 값을
// 순차열 [t, t+(e-b))에 저장한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Func(int n)
{
	return n + 5;
}
int Plus(int left, int right)
{
	return left + right;
}

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	vector<int> vec2(8);

	transform(vec1.begin(), vec1.end(), vec2.begin(),Func);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// 자기 자신을 목적지로 지정하면 자신의 원소를 수정 할 수도 있다.
	transform(vec1.begin(), vec1.end(), vec1.begin(), Func);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(8);
	
	// vec1의 원소들과 vec2의 원소들을 Plus() 연산하여 vec3에 저장
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), Plus);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}
