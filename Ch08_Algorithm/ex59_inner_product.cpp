// inner_product() 알고리즘 예제
// 두 순차열의 내적(모든 원소의 곱의 합)을 구하려면 inner_product() 알고리즘을 사용
// x2 = inner_product(b,e,b2,x) 알고리즘은 x를 초깃값으로 구간 [b,e)의 원소와 구간 [b2,b2+e-b)의 원소 내적을 x2에 반환
//
// 함수류를 버전의 inner_product() 알고리즘을 사용하면 더 다양한 원소 간의 연산과 누적 연산을 수행
// inner_product(b,e,b2,x,f1,f2) 알고리즘은 f1이 '+'연산이고 f2'*' 연산이라면
// 구간 [b,e)의 원소와 구간 [b2,b2+e-b)의 각 원소들간의 '*' 연산 후 '+' 연산을 시행한다.

// [출력 결과]

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int Plus(int left, int right)
{
	return left + right;
}
int Minus(int left, int right)
{
	return left - right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(2);
	vec1.push_back(3);


	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(3);
	vec2.push_back(3);
	vec2.push_back(2);
	vec2.push_back(2);
	vec2.push_back(4);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// vec1과 ve2의 내적: 2*3 + 4*3 + 5*2 + 2*2 + 3*4
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0) << endl;
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 1000) << endl;

	// 함수류 버전의 inner_product()
	// vec1과 ve2의 사용자 정의 연산: 2-3 + 4-3 + 5-2 + 2-2 + 3-4
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, Plus, Minus) << endl;;
	// STL 함수자 사용 버전
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, plus<int>(), minus<int>()) << endl;

	return 0;
}



