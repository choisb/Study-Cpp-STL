#include <iostream>
using namespace std;
// 예외처리 생략
template<typename T>
class Queue {
    enum {CAP = 100};   // queue의 크기
    T buf[CAP];
    int front, rear;

public:
    Queue() :front(0), rear(0) {}
    void Push(const T& data)
    {
        buf[rear = (rear+1) % CAP] = data;      // rear의 값이 0 ~ CAP사이를 순환하도록 % 연산 
    }
    T& Pop()
    {
        return buf[front = (front+1) % CAP];    // front의 값이 0 ~ CAP사이를 순환하도록 % 연산 
    }
    bool Empty() const
    {
        return front == rear;
    }
};

int main()
{
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    if (!q.Empty())
        cout << q.Pop() << endl;
    if (!q.Empty())
        cout << q.Pop() << endl;
    if (!q.Empty())
        cout << q.Pop() << endl;

    return 0;
}