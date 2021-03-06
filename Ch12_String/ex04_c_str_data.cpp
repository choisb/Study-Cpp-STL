// c_str(), data() 멤버함수 사용 예제
// 두 멤버 함수 모두 const char* 형식을 반환.
// c_str(): string 객체가 가지고 있는 문자열을 C-style의 문자열로 변환할 때 사용
// data(): '\0' 문자를 포함하지 않는 문자의 배열을 반환

// [출력 결과]
// '\0' 문자로 끝나는 문자열(C - style) : Hello!
// '\0' 문자를 포함하지 않은 문자열 배열 : Hello!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("Hello!");
	const char* sz;
	const char* buf;

	sz = s.c_str();
	buf = s.data();

	cout << "'\\0' 문자로 끝나는 문자열 (C-style): " << sz << endl;
	cout << "'\\0' 문자를 포함하지 않은 문자열 배열: ";
	for (int i = 0; i < 6; i++)
		cout << buf[i];
	cout << endl;

	return 0;

}