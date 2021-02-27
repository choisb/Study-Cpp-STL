// ostream_iterator<T>와 istream_iterator<T> 예제

// [출력 결과]
// vec1 :1020304050
// vec1 :10, 20, 30, 40, 50,
// lt + v : 110 220 330
// 10 20 30 50 40 80 10^D
// vec2: 10 20 30 50 40 80 10

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	// ostream_iterator<T> 예제
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	// ostream_iterator<int>(cout): cout과 연결되어 있으면서 정수를 출력하는 반복자를 생성
	cout << "vec1 :";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout));
	cout << endl;

	// ostream_iterator<int>(cout, ", "): cout과 연결되어 있으면서 정수를 출력하는 반복자를 생성. 출력 끝 패턴을 ", "로 설정.
	cout << "vec1 :";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	list<int> lt;
	lt.push_back(100);
	lt.push_back(200);
	lt.push_back(300);

	//transform(b, e, b2, t, f)는
	// 구간 [b, e) 순차열과 [b2, b2+(e-b))의 순차열의 반복자를 p, q라 할때 f(*p, *q)한 값을
	// 순차열 [t, t+(e-b))에 저장한다.
	cout << "lt + v : ";
	transform(lt.begin(), lt.end(), vec1.begin(), ostream_iterator<int>(cout, " "), plus<int>());
	cout << endl;


	// istream_iterator<T> 예제
	// 표준 입력 스트림에서 정수를 입력받아 vec2에 저장하는 예제

	vector<int> vec2;

	// istream_iterator<int>(cin): 표준 입력 스트림과 연결된 반복자를 생성
	// istream_iterator<int>(): 입력 스트림의 끝 반복자를 생성
	// end-of-file (Ctrl+D)가 입력될때 까지 정수를 입력받음
	// back_inserter<vector<int>>(vec2): vec2의 push_back() 멤버 함수를 호출하는 삽입 반복자를 생성
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(vec2));
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}



