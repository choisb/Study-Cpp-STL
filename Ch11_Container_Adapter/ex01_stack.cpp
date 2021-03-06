// stack 사용 예시
//
// [출력 결과]
// 30
// 20
// 10

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;

	st.push(10);
	st.push(20);
	st.push(30);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}