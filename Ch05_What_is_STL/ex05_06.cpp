#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    // �Ϲ����� stack�� ��� ��� ////
    // stack�� ����Ʈ �����̳ʷ� deque<int>�� ����Ѵ�.
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

    if (st.empty()) // ������ ������� Ȯ��
        cout << "stack�� ������ ����" << endl;

    // �����̳� ����ͷ� stack�� ��� ��� ////
    // �����̳� ����͸� Ȱ���ϸ� stack�� �����̳ʸ� vector<int>�� ����� �� �ִ�.
    stack<int, vector<int>> ast; // vector �����̳ʸ� �̿��� stack �����̳� ����
 
    ast.push(10);
    ast.push(20);
    ast.push(30);

    cout << ast.top() << endl;
    ast.pop();
    cout << ast.top() << endl;
    ast.pop();
    cout << ast.top() << endl;
    ast.pop();

    if (ast.empty()) // ������ ������� Ȯ��
        cout << "stack�� ������ ����" << endl;

    return 0;
}