// priority_queue ��� ����
//
// [��� ���]
// priority_queue[less]:
// 60
// 50
// 40
// 30
// 20
// 10
// ============================
// priority_queue[greater]:
// 10
// 20
// 30
// 40
// 50
// 60

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main()
{
	priority_queue<int> pq1; // �⺻ �����̳� vector<int>, �⺻ ���� ���� less
	pq1.push(40);
	pq1.push(20);
	pq1.push(30);
	pq1.push(50);
	pq1.push(10);
	pq1.push(60);

	cout << "priority_queue[less]: " << endl;
	while (!pq1.empty())
	{
		cout << pq1.top() << endl;
		pq1.pop();
	}
	cout << "============================" << endl;

	priority_queue<int, deque<int>, greater<int>> pq2; // deque<int> �����̳ʸ� ���, ���ı��� greater
	pq2.push(40);
	pq2.push(20);
	pq2.push(30);
	pq2.push(50);
	pq2.push(10);
	pq2.push(60);

	cout << "priority_queue[greater]: " << endl;
	while (!pq2.empty())
	{
		cout << pq2.top() << endl;
		pq2.pop();
	}

	return 0;
}
