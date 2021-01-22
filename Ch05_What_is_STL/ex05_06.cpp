#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    // 일반적인 stack의 사용 방법 ////
    // stack은 디폴트 컨테이너로 deque<int>를 사용한다.
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    if (st.empty()) // 스택이 비었는지 확인
        cout << "stack에 데이터 없음" << endl;

    // 컨테이너 어댑터로 stack의 사용 방법 ////
    // 컨테이너 어댑터를 활용하면 stack의 컨테이너를 vector<int>로 사용할 수 있다.
    stack<int, vector<int>> ast; // vector 컨테이너를 이용한 stack 컨테이너 생성
 
    ast.push(10);
    ast.push(20);
    ast.push(30);

    cout << ast.top() << endl;
    ast.pop();
    cout << ast.top() << endl;
    ast.pop();
    cout << ast.top() << endl;
    ast.pop();

    if (ast.empty()) // 스택이 비었는지 확인
        cout << "stack에 데이터 없음" << endl;

    return 0;
}