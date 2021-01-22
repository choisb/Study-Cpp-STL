#include <iostream>
using namespace std;

// ����ó�� ����
template <typename T>
class Stack {
    T* arr;
    int top;
    const int capacity;

public:
    explicit Stack(int _cap = 100) : capacity(_cap), top(0) // ������ ����ȯ�� �������� ���� ���̱� ������ explicit ���� �� �Ұ�.
    { 
        arr = new T[capacity];
    }

    void Push(const T& data)    // �ӽ� ��ü ������ ���� ���ؼ� const T& Ÿ������ ȣ���� ��
    {
        arr[top++] = data;
    }

    bool Empty() const  // ��������� ��ȭ�� ���� ������ const�� �����Ұ�.
    {
        return top <= 0;
    }

    T& Pop()
    {
        return arr[--top];
    }
};

int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
    if (!st.Empty())
        cout << st.Pop() << endl;
}