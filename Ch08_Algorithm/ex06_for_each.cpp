// for_each() 알고리즘 예제
// for_each(b,e,f)는 구간 [b,e)의 반복자가 구간 내 모든 원소에서
// f(*p)를 호출한다.
// 여기서 f는 함수류(함수자, 함수, 함수 포인터)를 뜻함.

// 부가적인 정보를 전달하고 변경할 수 있는 함수자(함수 객체)를 사용하면 다양한 패턴으로 사용할 수도 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class PrintFunctor
{
	char fmt;
public:
	explicit PrintFunctor(char c = ' ') : fmt(c) {}
	void operator () (int n) const
	{
		cout << n << fmt;
	}
};
void Print(int n)
{
	cout << n << " ";
}
int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	for_each(Vec.begin(), Vec.begin() + 2, Print);
	cout << endl;
	for_each(Vec.begin(), Vec.begin() + 4, Print);
	cout << endl;

	// 함수자 사용 예시
	cout << endl << "=========== 함수자 사용 예시 ==========" << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor());
	cout << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor(','));
	cout << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor('\n'));
	return 0;
}
// [출력 결과]
// 10 20
// 10 20 30 40
// 
// =========== 함수자 사용 예시 ==========
// 10 20 30 40 50
// 10, 20, 30, 40, 50,
// 10
// 20
// 30
// 40
// 50