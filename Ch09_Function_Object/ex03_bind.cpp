// bind 예제
// binder1st, binder2nd는 원래 이항 함수 객체를 단항 함수 객체로 변환하는 바인더(어댑터)였으나 C++11 부터 사용하지 않기 시작했고, C++17부터는 삭제됨.
// 대신 bind() 함수로 대체
//
// std::bind(addAndPrint, 10, std::placeholders::_1)는 
// addAndPrint(int, int) 함수의 
// 첫 번째 파라메터는 10, 
// 두 번째 파라메터는 func2 를 호출할 때 들어오는 첫번째 인자(std::placeholders::_1)를 넣어준다는 의미
//
// STL의 이항 함수자와 
// 사용자 정의 이항 함수자를
// bind 함수를 통해서 단항 함수자로 사용하는 예제
// bin


// [출력 결과]
// vec1: 10 20 30
// vec2: 1 2 3
// vec3: 11 22 33
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct MyPlus
{
	// 사용자 정의 함수자에서 binder1st<int>를 사용하기 위해서는 아래의 형식 정의가 필요하다.

	T operator() (const T& left, const T& right) const
	{
		return left + right;
	}
};

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);


	vector<int> vec3(3); // size: 3인 vector 생성

	// STL 조건자 plus<int> 사용 C++14 이하
	//transform(vec1.begin(), vec1.end(), vec3.begin(), binder1st<plus<int>>(plus<int>(), 100));

	// STL 조건자 plus<int> 사용 C++17 이상
	//transform(vec1.begin(), vec1.end(), vec3.begin(), bind(plus<int>(), placeholders::_1, 100));

	// 사용자 정의 조건자 MyPlus<int> 사용 C++17 이상
	transform(vec1.begin(), vec1.end(), vec3.begin(), bind(plus<int>(), placeholders::_1, 100));

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;



	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}