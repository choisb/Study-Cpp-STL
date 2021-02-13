// for_each() 알고리즘 예제
// for_each() 알고리즘은 원소를 수정하는 알고리즘으로도 사용할 수 있다.
// for_each(b, e, f)는 구간 [b, e)의 반복자가 p라면 모든 원소에 f(*p)를 적용.
//
// 함수자를 사용하면 for_each()로 더욱 다양한 작업을 할 수 있다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Accumulation
{
	int total;
public:
	explicit Accumulation(int init = 0) :total(init) {}
	void operator() (int &r)	// 매개변수로 전달받은 원소를 수정하기 위해 &(레퍼런스)를 사용
	{
		total += r;
		r = total;
	}
};

// 매개변수로 전달받은 원소를 수정하기 위해 &(레퍼런스)를 사용
void Func(int& r)
{
	r += 5;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// for_each()의 함수포인터 사용 예시
	cout << "for_each()의 함수포인터 사용 예시" << endl;
	for_each(vec.begin(), vec.end(), Func);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// for_each()의 함수자를 사용한 예시
	cout << "for_each()의 함수자를 사용한 예시" << endl;
	for_each(vec.begin(), vec.end(), Accumulation());
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 10 20 30 40 50
// for_each()의 함수포인터 사용 예시
// vec : 15 25 35 45 55
// for_each()의 함수자를 사용한 예시
// vec : 15 40 75 120 175