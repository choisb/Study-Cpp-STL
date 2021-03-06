// getline(), 스트림 연산자 >> 예제
// 스트림으로부터 string 객체로 문자열을 입력받으려면 입력 스트림 연산자 >>와 getline()함수를 사용
// 입력 스트림 연산자는 cin >> buf 처럼 공백 문자를 구분자로 사용
// getline() 함수는 cin.getline()처럼 공백 문자도 포함하여 한 줄을 입력으로 받음

// [출력 결과]
// 두 문자열 입력(공백 문자 가능):
// abcd efg
// hello world!
// s1: abcd efg
// s2: hello world!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;

	cout << "두 문자열 입력(공백 문자 가능): " << endl;
	getline(cin, s1);
	getline(cin, s2, '\n');
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	return 0;
}