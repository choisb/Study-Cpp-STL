// adjacent_find() 알고리즘 예제
// 순차열에서 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자를 반환.
// 찾는 원소를 발견하지 못할 경우 "탐색 구간의 끝 반복자"를 반환
//						      "컨테이너의 끝 반복자"가 아님. 주의할것
//
// 조건자를 사용하면 인접한 원소가 특정 조건에 따라 인접한지를 탐색할 수도 있다. 
// 이때 조건자는 이항 조건자를 사용한다. (현재 원소, 다음 원소를 매개변수로 사용)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int a, int b)
{
	return abs(b - a) > 10;
}

int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);	
	Vec.push_back(40);	
	Vec.push_back(50);  // 반복되는 데이터 삽입
	Vec.push_back(50);  // 반복되는 데이터 삽입
	Vec.push_back(70);
	Vec.push_back(80);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	auto iter = adjacent_find(Vec.begin(), Vec.end());	// 백터의 시작부터 끝까지 탐색.
														// 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자를 반환
	if (iter != Vec.end())
		cout << *iter << endl;	// 반복되는 원소인 50을 가리키는 반복자 반환

	for (; iter != Vec.end(); ++iter)	// 50이후의 원소들을 출력
		cout << *iter << " ";
	cout << endl;


	// 탐색에 실패할 경우 반환값 확인
	cout << "========탐색에 실패할 경우 반환값 확인 예제========" << endl;

	auto iter_b = Vec.begin();
	auto iter_e = Vec.begin() + 2;
	iter = adjacent_find(iter_b, iter_e);

	// 찾는 원소가 있다면 그 원소를 출력하기위한 코드
	// 컨테이너의 end()가 아니라 탐색 구간의 마지막 원소와 비교해야 한다.

	if (iter != iter_e)	// 찾는 원소가 없는지 확인하는 맞는 표현
		cout << "iter != iter_e: "<<*iter << endl;

	if (iter != Vec.end())	// 찾는 원소가 없는지 확인하는 틀린 표현
		cout << "iter != Vec.end(): " <<*iter << endl;
	cout << endl;

	// 조건자를 활용한 adjacent_find()함수 예제

	cout << "========조건자를 활용한 adjacent_find()함수 예제========" << endl;

	iter = adjacent_find(Vec.begin(), Vec.end(), Pred);
	if (iter != Vec.end())
		cout << *iter << endl;

	for (; iter != Vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
// [출력 결과
// 10 20 30 40 50 50 70 80
// 50
// 50 50 70 80
// ========탐색에 실패할 경우 반환값 확인 예제========
// iter != Vec.end() : 30
// 
// ========조건자를 활용한 adjacent_find()함수 예제========
// 50
// 50 70 80
