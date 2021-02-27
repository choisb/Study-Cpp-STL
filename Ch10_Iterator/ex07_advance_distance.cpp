// advance(), distance() 예제

// viter: 10
// liter: 10
// viter: 30
// liter: 30
// viter: 10
// liter: 10
// [vec1.begin(), vec1.end())의 원소 개수: 5
// [lt1.begin(), lt1.end())의 원소 개수: 5

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	auto viter = vec1.begin();
	auto liter = lt1.begin();

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// advance() 예제

	// 양방향 반복자인 liter이 advance()를 통해서 `+=` 연산을 수행
	advance(viter, 2);
	advance(liter, 2);

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// 양방향 반복자인 liter이 advance()를 통해서 `-=` 연산을 수행
	advance(viter, -2);
	advance(liter, -2);

	cout << "viter: " << *viter << endl;
	cout << "liter: " << *liter << endl;

	// distance() 예제
	// 양방향 반복자인 liter이 distance()를 통해서 `-` 연산을 수행
	cout << "[vec1.begin(), vec1.end())의 원소 개수: " << distance(vec1.begin(), vec1.end()) << endl;
	cout << "[lt1.begin(), lt1.end())의 원소 개수: " << distance(lt1.begin(), lt1.end()) << endl;

	// distance() 함수의 반환 형식은 대부분 unsigned int 혹은 int 이지만 반복자에 따라서 다르다.
	// 정확히 표현하면 반복자 특성의 difference_type 형식이다. 즉 반환 타입의 표현은 다음과 같다.
	iterator_traits<vector<int>::iterator>::difference_type n = distance(lt1.begin(), lt1.end());

	return 0;
}