// 정렬된 범위 알고리즘
// 정렬된 범위 알고리즘을 사용하기 위해서는 입력 순차열이 반드시 정렬돼 있어야 한다.
//
// binary_search() 알고리즘 예제
// binary_search(b,e,x)는 구간[b,e)의 순차열에서 x와 같은 원소가 있으면 true를 반환, 없으면 false를 반환 
// 순차열의 원소가 기본 정렬 기준인 less(<)로 정렬(오름차순)돼 있다는 전제 하에 동작
// binary_search() 알고리즘은 원소를 찾기 위해 두 원소 a, b에 대해 a == b 연산을 사용하지 않고 !(a<b) && !(b>a) 연산을 사용한다.
//
// binary_search()알고리즘도 조건자 버전을 지원하는데, 조건자 버전을 통해서 같은 연산에 대한 예시를 다룬다.
// binary_search(b,e,x,f)는 구간 [b,e)의 원소 중 x 원소와 같은 원소가 있다면 true, 아니라면 false 반환. (f는 이항 조건자)


// [출력 결과]
// vec1: 10 20 30 40 50 60 70 80
// 20 원소가 존재합니다.
// 
// *** 조건자 버전 ***
// 원본 vec2: 40 46 12 80 10 47 30 55 90 53
// 정렬 vec2: 12 10 30 40 46 47 55 53 80 90
// 32 원소가 존재합니다.
// 35 원소가 존재하지 않습니다.

// <<추가 설명>>
// 출력결과에서 정렬된 vec2를 보면 12가 10보다 앞서있는 것을 볼 수 있다. 55 53도 마찬가지
// 또한 vec2에 존재하지 않는 원소 32에대한 binary_search()결과 true를 반환하는 것도 볼 수 있다.
// 이러한 것이 가능한 이유가 a == b 연산을 사용하지 않고 !(a<b) && !(b>a) 연산을 사용하기 때문이다.
// !(Pred(30,32)) && !(Pred(32,30)) 이 true이면 두 원소는 같은것 으로 간주한다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return 3 < right - left;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	if(binary_search(vec1.begin(), vec1.end(), 20))
		cout << "20 원소가 존재합니다." << endl;
	else
		cout << "20 원소가 존재하지 않습니다."<<endl;
 

	cout << endl << "*** 조건자 버전 ***" << endl;
	vector<int> vec2;
	vec2.push_back(40);
	vec2.push_back(46);
	vec2.push_back(12);
	vec2.push_back(80);
	vec2.push_back(10);
	vec2.push_back(47);
	vec2.push_back(30);
	vec2.push_back(55);
	vec2.push_back(90);
	vec2.push_back(53);

	cout << "원본 vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	sort(vec2.begin(), vec2.end(), Pred);

	cout << "정렬 vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// 순차열에서 두 원소의 차가 3보다 크다면 다음 위치의 원소로 정렬하고 검색

	if (binary_search(vec1.begin(), vec1.end(), 32, Pred))
		cout << "32 원소가 존재합니다." << endl;
	else
		cout << "32 원소가 존재하지 않습니다." << endl;


	if (binary_search(vec1.begin(), vec1.end(), 35, Pred))
		cout << "35 원소가 존재합니다." << endl;
	else
		cout << "35 원소가 존재하지 않습니다." << endl;

	return 0;
}



