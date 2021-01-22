#include <iostream>
using namespace std;

// 예외처리 생략
template <typename T>
class Stack {
    T* arr;
    int top;
    const int capacity;

public:
    explicit Stack(int _cap = 100) : capacity(_cap), top(0) // 생성자 형변환을 지원하지 않을 것이기 때문에 explicit 선언 꼭 할것.
    { 
        arr = new T[capacity];
    }

    void Push(const T& data)    // 임시 객체 생성을 막기 위해서 const T& 타입으로 호출할 것
    {
        arr[top++] = data;
    }

    bool Empty() const  // 멤버변수에 변화가 없기 때문에 const로 선언할것.
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