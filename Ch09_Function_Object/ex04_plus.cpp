// STL에서 제공하는 plus<T> 함수자의 4가지 사용법과
// 사용자 정의 MyPlus<T> 작성 및 사용 법
//
// [출력 결과]
// 30
// 30
// 30
// 30
// 30
// 30
// 30
// 30

#include <iostream>
#include <functional>
using namespace std;
template<typename T>
struct MyPlus : public binary_function<T, T, T> // 어댑터 적용이 가능하게
{
	T operator() (const T& left, const T& right) const
	{
		return left + right;
	}
};
int main()
{
	plus<int> oPlus;
	// 1. oPlus 객체로 10, 20 더하기, 암묵적 호출
	cout << oPlus(10, 20) << endl;
	// 2. oPlus객체로 10, 20 더하기, 명시적 호출
	cout << oPlus.operator()(10, 20) << endl;

	// 3. 임시 객체로 10, 20 더하기, 암묵적 호출(일반적인 사용)
	cout << plus<int>() (10, 20) << endl;
	// 4. 임시 객체로 10, 20 더하기, 명시적 호출
	cout << plus<int>().operator()(10, 20) << endl;


	// 사용자 정의 함수자 사용 예시


	MyPlus<int> oMyPlus;
	// 1. oMyPlus 객체로 10, 20 더하기, 암묵적 호출
	cout << oMyPlus(10, 20) << endl;
	// 2. oMyPlus객체로 10, 20 더하기, 명시적 호출
	cout << oMyPlus.operator()(10, 20) << endl;

	// 3. 임시 객체로 10, 20 더하기, 암묵적 호출(일반적인 사용)
	cout << MyPlus<int>() (10, 20) << endl;
	// 4. 임시 객체로 10, 20 더하기, 명시적 호출
	cout << MyPlus<int>().operator()(10, 20) << endl;
	return 0;
}