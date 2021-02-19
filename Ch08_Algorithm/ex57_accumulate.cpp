// 수치알고리즘을 사용하기 위해서는 <numeric> 헤더를 포함해야함.
// accumulate() 알고리즘 예제
// 순차열의 모든 원소에 대해 누적을 구하기 위해서 accumulate()알고리즘 사용.
// for_each()나 transform()알고리즘을 사용할 수도 있지만, 이들은 누적값을 기억하기 위해 함수자를 사용해야 하므로 조금 복잡함.
// x2 = accumulate(b,e,x) 알고리즘은 x를 초기값으로 한 구간 [b,e)의 모든 원소 합을 x2에 반환

// [출력 결과]
// vec1: 10 20 30 40 50
// 150
// 650

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << accumulate(vec1.begin(), vec1.end(), 0) << endl;
	cout << accumulate(vec1.begin(), vec1.end(), 500) << endl;


	return 0;
}



