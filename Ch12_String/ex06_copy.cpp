// copy() 멤버함수 사용 예제
// copy()는 끝에 '\0'문자를 포함하지 않는다

// [출력 결과]
// 전체 문자열[copy(buf, n)]: Hello!
// 부분문자열[copy(buf, n, off)] : llo!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("Hello!");
	char buf[100];

	// 주의점: copy()는 끝에 '\0'문자를 포함하지 않는다.
	s.copy(buf, s.length()); // length()는 size()함수와 같다. 문자열의 길이를 직관적으로 표현하기 위해서 size 대신 legth() 사용
	buf[s.length()] = '\0';
	cout << "전체 문자열[copy (buf, n)]: " << buf << endl;

	s.copy(buf, 4, 2);
	buf[4] = '\0';
	cout << "부분문자열[copy (buf, n, off)]: " << buf << endl;

	return 0;
}