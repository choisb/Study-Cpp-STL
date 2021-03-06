// insert() 멤버 함수 예제
// insert() 멤버 함수는 index 위치나 반복자가 가리키는 위치에 문자나 문자열을 삽입
// 다른 컨테이너처럼 삽입 위치는 가리키는 원소의 앞쪽에 삽입

// [출력 결과]
// s1.insert(pos, sz) : HABCello!
// s2.insert(pos, sz, n) : HABello!
// s3.insert(pos, s) : HABCello!
// s4.insert(pos, s, off, n) : HBCello!
// s5.insert(pos, n, c) : HAAAello!
// 
// s6.insert(iter)오류
// s7.insert(iter, c) : HAello!
// s8.insert(iter, n, c) : HAAAello!
// s9.insert(iter1, s.begin(), s.end()) : HABCello!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("ABC");

	string s1("Hello!");
	string s2("Hello!");
	string s3("Hello!");
	string s4("Hello!");
	string s5("Hello!");
	string s6("Hello!");
	string s7("Hello!");
	string s8("Hello!");
	string s9("Hello!");

	s1.insert(1, "ABC");
	s2.insert(1, "ABC", 2);
	s3.insert(1, t);
	s4.insert(1, t, 1, 2);
	s5.insert(1, 3, 'A');

	// s6.insert(s6.begin() + 1); // s6.insert(iter) 은 없는데?
	s7.insert(s7.begin() + 1, 'A');
	s8.insert(s8.begin() + 1, 3, 'A');
	s9.insert(s9.begin() + 1, t.begin(), t.end());

	// sz: '\0' 문자열,  s: string 객체, c: 문자, pos: 삽입 위치, off: 위치, n: 길이, iter: 반복자, p: 포인터
	cout << "s1.insert(pos, sz): " << s1 << endl;
	cout << "s2.insert(pos, sz, n): " << s2 << endl;
	cout << "s3.insert(pos, s): " << s3 << endl;
	cout << "s4.insert(pos, s, off, n): " << s4 << endl;
	cout << "s5.insert(pos, n, c): " << s5 << endl<<endl;

	cout << "s6.insert(iter)" << "오류" << endl; // s6.insert(iter) 은 없는데?
	cout << "s7.insert(iter, c): " << s7 << endl;
	cout << "s8.insert(iter, n, c): " << s8 << endl;
	cout << "s9.insert(iter1, s.begin(), s.end()): " << s9 << endl;

	return 0;
}