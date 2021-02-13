// boj 5052 문제 풀이를 위해서 미리 학습함
// string의 compare() 함수 예제
//compare() 멤버함수는 문자열을 비교하여 s1 > s2 이면 1 / s1 < s2 이면 -1 / s1 == s2 이면 0을 반환

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("ABCDE");
	string s2("AKABC");
	const char* sz = "AKABC";

	// s : string 객체, sz:'\0'문자열, off: 시작위치, n: 길이

	//s1과 s2를 비교. s1 보다 s2가 더 큼 => 1
	cout << "s1.compare(s): " << s1.compare(s2) << endl;	

	// s1과 s2를 비교할 때 3번째 문자부터 3개의 문자만 비교.
	// s1: CDE, s2: ABC 이므로 s1이 더큼 => -1
	cout << "s1.compare(off,n,s): " << s1.compare(2, 3, s2) << endl;

	// s1과 s2를 비교할때 s1은 1번째 문자 ~ 3번째 문자 / s2는 3번째 문자 ~ 5번째 문자 비교
	// s1: ABC, s2: ABC 이므로 => 0
	cout << "s1.compare(off,n,s,off2,n2): " << s1.compare(0, 3, s2, 2, 3) << endl;

	// 이후 부분은 추후 학습하면서 작성하자.
	
}
