// find(), rfind() 멤버함수 사용 예제
// find()와 rfind() 멤버 함수는 문자나 부분 문자열의 위치를 반환하는 함수
// find()는 문자열의 앞에서부터 끝으로 탐색
// rfind()는 문자열의 끝에서부터 앞으로 탐색
// 만약 찾는 문자가 없으면 string::npos 정의 값을 반환.
// string::npos는 string(basic_string<>)의 멤버 정의 정수이며 일반적으로 -1

// [출력 결과]
// Lorem Ipsum is simply dummy text of the printingand typesetting industry.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
//
// s.find(c) : 6
// s.find(c, off) : 246
// s.find(sz) : 53
// s.find(sz, off) : 321
// s.find(sz, off, n) : 28
// s.find(s) : 53
// 
// - 1 : -1
// s.rfind(c) : 568

#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char* sz = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";

	string t("typesetting");
	string s = sz;

	// sz: '\0' 문자열,  s: string 객체, c: 문자, off: 시작위치, n: 길이, iter: 반복자, p: 포인터
	cout << s << endl << endl;
	cout << "s.find(c): " << s.find('I') << endl;
	cout << "s.find(c, off): " << s.find('I', 200) << endl;
	cout << "s.find(sz): " << s.find("typesetting") << endl;
	cout << "s.find(sz, off): " << s.find("typesetting", 100) << endl;
	cout << "s.find(sz, off, n): " << s.find("typesetting", 0, 1) << endl;
	cout << "s.find(s): " << s.find(t) << endl << endl;

	string::size_type pos = s.find("Not found");
	cout << (int)pos << " : " << (int)string::npos << endl;

	pos = s.rfind('I');
	if (string::npos != pos)
		cout << "s.rfind(c): " << pos << endl;

	return 0;
}