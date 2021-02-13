// generate(), generate_n() 알고리즘 예제
// 순차열의 모든 원소를 단순한 동작의 값으로 수정하려면 generate() 알고리즘을 사용
// generate(b,e,f) 알고리즘은 구간 [b, e)의 모든 원소를 f()로 채운다.
// generate_n(b,n,f) 알고리즘은 구간[b, b+n)의 모든 원소를 f()로 채운다.
// 
// for_each()와의 차이는, for_each()는 함수자에서 원소를 매개변수로 받아서 활용할 수 있지만,
// generate()는 원소에 값을 대입할 수 있을 뿐 원소의 값을 참조할 수는 없다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정수를 1씩 증가하며 순차열을 채우는 generate()에 사용할 함수자
class Integer {
	int data;
public:
	explicit Integer(int d = 0) : data(d) {}
	int operator()()
	{
		return data++;
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())의 원소를 1 ~ 5로 채움
	generate(vec.begin(), vec.end(), Integer());
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())의 원소를 100 ~ 104로 채움
	generate(vec.begin(), vec.end(), Integer(100));
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())의 원소를 100 ~ 104로 채움
	generate_n(vec.begin(), 3, Integer(1));
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [출력 결과]
// vec: 10 20 30 40 50 60
// vec : 0 1 2 3 4 5
// vec : 100 101 102 103 104 105
// vec : 1 2 3 103 104 105