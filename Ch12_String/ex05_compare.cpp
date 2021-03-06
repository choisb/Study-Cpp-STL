// compare()멤버함수 사용 예제
// 문자열 비교 연산(== , >, < 등)은 전체 문자열을 비교하지만 compare() 멤버 함수는 부분 문자열을 비교할 수 있다.
//compare() 멤버함수는 문자열을 비교하여 s1 > s2 이면 1 / s1 < s2 이면 -1 / s1 == s2 이면 0을 반환

// [출력 결과]
// s1.compare(s) : -1
// s1.compare(off, n, s) : 1
// s1.compare(off, n, s, off2, n2) : 0
// s1.compare(sz) : -1
// s1.compare(off, n, sz) : 1
// s1.compare(off, n, sz, off2, n2) : 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("ABCDE");
	string s2("AKABC");
	const char* sz = "AKABC";

	// s : string 객체, sz:'\0'문자열, off: 시작위치, n: 길이

	//s1과 s2를 비교.
	// s1: ABCDE, s2: AKABC 이므로 -1
	cout << "s1.compare(s): " << s1.compare(s2) << endl;	

	// s1과 s2를 비교할 때 3번째 문자부터 3개의 문자만 비교.
	// s1: CDE, s2: ABC 이므로 s1이므로 1
	cout << "s1.compare(off,n,s): " << s1.compare(2, 3, s2) << endl;

	// s1과 s2를 비교할때 s1은 1번째 문자 ~ 3번째 문자 / s2는 3번째 문자 ~ 5번째 문자 비교
	// s1: ABC, s2: ABC 이므로 => 0
	cout << "s1.compare(off,n,s,off2,n2): " << s1.compare(0, 3, s2, 2, 3) << endl;

	// s1과 '\0'문자열 비교
	// s1: ABCDE, sz: AKABC 이므로 -1
	cout << "s1.compare(sz): " << s1.compare(sz) << endl;

	// s1과 '\0'문자열을 비교할 때  3번째 문자부터 3개의 문자만 비교.
	// s1: CDE, sz: ABC 이므로 1
	cout << "s1.compare(off, n, sz): " << s1.compare(2, 3, sz) << endl;

	// s1과 '\0'문자열을 비교할때 s1은 1번째 문자 ~ 3번째 문자를 '\0'문자열은 3번째 문자 ~ 5번째 문자 비교
	// s1: ABC, sz: ABC 이므로 0
	cout << "s1.compare(off,n,sz,off2,n2): " << s1.compare(0, 3, sz, 2, 3) << endl;

}
