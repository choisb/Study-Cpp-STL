#include <iostream>
using namespace std;
// ����ó�� ����
template<typename T>
class Queue {
    enum {CAP = 100};   // queue�� ũ��
    T buf[CAP];
    int front, rear;

public:
    Queue() :front(0), rear(0) {}
    void Push(const T& data)
    {
        buf[rear = (rear+1) % CAP] = data;      // rear�� ���� 0 ~ CAP���̸� ��ȯ�ϵ��� % ���� 
    }
    T& Pop()
    {
        return buf[front = (front+1) % CAP];    // front�� ���� 0 ~ CAP���̸� ��ȯ�ϵ��� % ���� 
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