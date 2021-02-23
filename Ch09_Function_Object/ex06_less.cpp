// STL에서 제공하는 less<T> 함수자의 4가지 사용법과
// 사용자 정의 MyLess<T> 작성 및 사용 법
//
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
struct MyLess
{
	bool operator() (const T& left, const T& right) const
	{
		return left < right;
	}
};

int main()
{
	less<int> oLess;
	// 1. oLess 객체로 10, 20을 비교 true. 암묵적 호출
	cout << oLess(10, 20) << endl;
	// 2. oLess 객체로 10, 20을 비교 true. 명시적 호출
	cout << oLess.operator()(10, 20) << endl;

	// 3. 임시 객체로 10, 20을 비교 true. 암묵적 호출(일반적 사용)
	cout << less<int>() (10, 20) << endl;
	// 4. 임시 객체로 10, 20을 비교 true. 명시적 호출
	cout << less<int>().operator()(10, 20) << endl;


	MyLess<int> oMyLess;
	// 1. oMyLess 객체로 10, 20을 비교 true. 암묵적 호출
	cout << oMyLess(10, 20) << endl;
	// 2. oMyLess 객체로 10, 20을 비교 true. 명시적 호출
	cout << oMyLess.operator()(10, 20) << endl;

	// 3. 임시 객체로 10, 20을 비교 true. 암묵적 호출(일반적 사용)
	cout << MyLess<int>() (10, 20) << endl;
	// 4. 임시 객체로 10, 20을 비교 true. 명시적 호출
	cout << MyLess<int>().operator()(10, 20) << endl;

	return 0;
}