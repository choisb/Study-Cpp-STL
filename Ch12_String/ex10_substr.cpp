// substr() 멤버 함수 예제
// substr() 멤버 함수는 string 객체의 일부 문자열을 추출하고자 할 때 사용
// 
// substr(pos, n)은 pos(index)의 위치부터 n개 만큼의 문자열을 반환
// 만약 n을 string::npos로 지정하면 문자열의 마지막 문자까지가 된다.

// [출력 결과]
// substr(0) - 0부터 끝까지 : Hello!
// substr(0, npos) - 0부터 끝까지 : Hello!
// substr(0, 2) - 0부터 2개 : He
// substr(2, 3) - 2부터 3개 : llo
// substr(2, npos) - 2부터 끝까지 : llo!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("Hello!");
	string s1, s2, s3, s4, s5;

	s1 = t.substr(0);
	s2 = t.substr(0, string::npos);

	s3 = t.substr(0, 2);
	s4 = t.substr(2, 3);
	s5 = t.substr(2, string::npos);

	cout << "substr(0) - 0부터 끝까지: " << s1 << endl;
	cout << "substr(0, npos) - 0부터 끝까지: " << s2 << endl;
	cout << "substr(0, 2) - 0부터 2개: " << s3 << endl;
	cout << "substr(2, 3) - 2부터 3개: " << s4 << endl;
	cout << "substr(2, npos) - 2부터 끝까지: " << s5 << endl;

	return 0;
}