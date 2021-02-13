// replace_copy(), replace_copy_if() 알고리즘 예제
// 사용자가 지정한 조건에 맞는 원소를 수정하여 목적지 순차열로 복사하려면
// replace_copy()와 replace_copy_if() 알고리즘을 사용할 수 있다.
// replace(b,e,f,x2) 알고리즘은 구간 [b,e)의 원소중 f(*p)가 참인 원소를 x2로 수정
// 여기서 f는 단항 조건자이다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return n <= 30;
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

	vector<int> vec2(8);	// size가 8인 vector 생성
	vector<int> vec3(8);	// size가 8인 vector 생성


	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;
	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	cout << endl;
	//vec1에서 크기가 30인 원소를 0으로 변환하여 vec2에 복사
	cout << "vec1에서 크기가 30인 원소를 0으로 변환하여 vec2에 복사" << endl;
	auto iter_end2 = replace_copy(vec1.begin(), vec1.end(), vec2.begin(), 30, 0);

	//vec1에서 30이하인 원소를 0이르 변환하여 vec3에 복사
	cout << "vec1에서 30이하인 원소를 0이르 변환하여 vec3에 복사 " << endl;
	auto iter_end3 = replace_copy_if(vec1.begin(), vec1.end(), vec3.begin(), Pred, 0);

	cout << endl;

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;
	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec1: 10 20 30 40 30 30 50 60
// vec2 : 0 0 0 0 0 0 0 0
// vec3 : 0 0 0 0 0 0 0 0
// 
// vec1에서 크기가 30인 원소를 0으로 변환하여 vec2에 복사
// vec1에서 30이하인 원소를 0이르 변환하여 vec3에 복사
// 
// vec1 : 10 20 30 40 30 30 50 60
// vec2 : 10 20 0 40 0 0 50 60
// vec3 : 0 0 0 40 0 0 50 60
