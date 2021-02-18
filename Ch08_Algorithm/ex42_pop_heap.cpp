// pop_heap() �˰��� ����
// ������ ��Ʈ(���� ū ����) ��带 �����ϱ� ���ؼ� pop_heap() ���
// pop_heap(b,e) �˰����� ���� [b,e)�� ù ���Ҹ� ���� �� ���ҿ� ��ȯ�� �� ���� �����ǰ� ���� ����
// �׳� pop_heap()�˰��� ����� ��� ��Ʈ��尡 ������ ���� ������ �̵�.
// ���Ҹ� �����ϱ� ���ؼ��� ����Լ� pop_back()�� �Բ� ���.

// [��� ���]
// vec1: 10 20 30 40 50 60 70 80
// make_heap(vec1.begin(), vec1.end());
// vec1: 80 50 70 40 10 60 30 20
// pop_heap(vec1.begin(), vec1.end());
// vec1: 70 50 60 40 10 20 30 80
// vec1.pop_back();
// vec1: 70 50 60 40 10 20 30

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	make_heap(vec1.begin(), vec1.end());

	cout << "make_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// ��Ʈ��带 ������ ����(������ ���� �ڷ� ����)
	pop_heap(vec1.begin(), vec1.end());
	cout << "pop_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	
	// ��Ʈ��忴�� ���� ����
	vec1.pop_back();
	cout << "vec1.pop_back();" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}

