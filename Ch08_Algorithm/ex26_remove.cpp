// remove() 알고리즘 예제
// 순차열 구간에서 원하는 원소를 제거하고자 할때 remove() 알고리즘을 사용한다. (삭제가 아닌 논리적 제거)
// p = remove(b,e,x)는 구간 [b,e)의 순차열에서 x인 원소가 남지 않게 한다.
// 이때 remove는 실제 원소를 제거하지 않는다. 단지 다음 원소를 앞으로 이동하며 덮어쓸 뿐. size는 변하지 않음.
// remove()알고리즘 후의 순차열은 [b,q)가 된다.
// 주의할 점은 분명 [b,q) 구간에서는 x가 모두 삭제되지만, [q,e) 구간에서는 x가 남아있는 경우가 존재한다.
//
// [q,e) 구간을 완전히 삭제하기 위해서는 remove()알고리즘을 사용한 후 erase() 멤버 함수를 함께 사용한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(30);
	vec1.push_back(80);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//remove() 알고리즘
	auto iter_end = remove(vec1.begin(), vec1.end(), 30);
	cout << endl<<"remove(vec1.begin(), vec1.end(), 30);" << endl<<endl;
	// remvoe 후 [vec1.begin(), vec1.end()) 순차열
	// [iter_end, vec1.end()) 구간에서는 30이 남아있는 것을 확인할 수 있다.
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	// remove 후 [vec1.begin(), iter_end()) 순차열
	cout << "[vec1.begin(), iter_end()): ";
	for (auto iter = vec1.begin(); iter != iter_end; iter++ )
		cout << *iter << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//erase() 멤버함수
	vec1.erase(iter_end, vec1.end());

	cout << endl << "vec1.erase(iter_end, vec1.end());" << endl << endl;
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	return 0;
}
// [출력 결과]
// [vec1.begin(), vec1.end()): 10 30 20 30 40 30 30 30 50 60 70 30 80 | size : 13
// 
// remove(vec1.begin(), vec1.end(), 30);
// 
// [vec1.begin(), vec1.end()): 10 20 40 50 60 70 80 30 50 60 70 30 80 | size : 13
// [vec1.begin(), iter_end()): 10 20 40 50 60 70 80 | size : 13
// 
// vec1.erase(iter_end, vec1.end());
// 
// [vec1.begin(), vec1.end()): 10 20 40 50 60 70 80 | size : 7