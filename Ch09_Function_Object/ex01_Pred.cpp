// 함수 객체, 함수, 함수 포인터 조건자 사용 예제

// [출력 결과]
// 1
// 1
// 1

#include <iostream>
using namespace std;

struct LessFunctor // 1.함수 객체 조건자
{
	bool operator() (int left, int right) const
	{
		return left < right;
	}
};

bool LessFunc(int left, int right) // 2. 함수 조건자
{
	return left < right;
}
int main()
{
	bool(*LessPtr)(int, int) = LessFunc; // 3. 함수 포인터 조건자
	LessFunctor lessFunctor;

	// 모두 bool 형식을 반환
	// 1. 함수 객체로 10과 20을 비교
	cout << lessFunctor(10, 20) << endl;

	// 2. 함수로 10과 20을 비교
	cout << LessFunc(10, 20) << endl;

	// 3. 함수 포인터로 10과 20을 비교
	cout << LessPtr(10, 20) << endl;
}