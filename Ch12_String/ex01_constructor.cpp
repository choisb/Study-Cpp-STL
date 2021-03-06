// string 컨테이너의 주요 생성자 사용방법
// string도 문자를 원소로 취하는 시퀀스 컨테이너이므로 반복자로 초기화할 수 있다.
// string 클래스는 출력 스트림 << 연산자를 함수 오버로딩하여 스트림에 문자열을 출력할 수 있다.
// string 컨테이너는 배열 기반의 시퀀스 컨테이너이며, c/c++처럼 문자열 끝에 '\0'문자를 포함해야 하는 요구사항은 없다.

// [출력 결과]
// s1():
// s2(sz): Hello!
// s3(sz, n): He
// s4(n,c): HHHHH
// s5(iter1, iter2): Hello!
// s6(p1, p2): Hello!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("Hello!"); // 임시 문자열
	const char* p1 = "Hello!";
	const char* p2 = p1 + 6;

	string s1;
	string s2("Hello!");
	string s3("Hello!", 2);
	string s4(5, 'H');
	string s5(t.begin(), t.end()); // 반복자 쌍
	string s6(p1, p2); // 포인터 쌍

	// s: string객체, sz: '\0' 문자열, c: 문자, n: 길이, iter: 반복자, p: 포인터
	cout << "s1(): " << s1 << endl;
	cout << "s2(sz): " << s2 << endl;
	cout << "s3(sz, n): " << s3 << endl;
	cout << "s4(n,c): " << s4 << endl;
	cout << "s5(iter1, iter2): " << s5 << endl;
	cout << "s6(p1, p2): " << s6 << endl;

	return 0;
}