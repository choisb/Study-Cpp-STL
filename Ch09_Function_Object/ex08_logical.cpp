// STL 논리 연산 조건자 호출 및 
// 사용자 논리 연산 조건자 구현 예제
// [출력 결과]
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1

#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct MyLogical_and
{
	bool operator() (const T& left, const T&right) const
	{
		return left && right;
	}
};

int main()
{
	int n = 30;

	// STL 제공 논리 연산 조건자
	logical_and<bool> oAnd;
	// 1. oAnd 객체로 암묵적 호출
	cout << oAnd(greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 2. oAnd 객체로 명시적 호출
	cout << oAnd.operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// 3. 임시 객체로 암묵적 호출 (일반적인 사용)
	cout << logical_and<bool>() (greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 4. 임시 객체로 명시적 호출
	cout << logical_and<bool>().operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// 사용자 정의 논리 연산 조건자
	MyLogical_and<bool> oMyAnd;
	// 1. oMyAnd 객체로 암묵적 호출
	cout << oMyAnd(greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 2. oMyAnd 객체로 명시적 호출
	cout << oMyAnd.operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	// 3. 임시 객체로 암묵적 호출 (일반적인 사용)
	cout << MyLogical_and<bool>() (greater<int>() (n, 10), less<int>()(n, 50)) << endl;
	// 4. 임시 객체로 명시적 호출
	cout << MyLogical_and<bool>().operator()(greater<int>() (n, 10), less<int>()(n, 50)) << endl;

	return 0;
}