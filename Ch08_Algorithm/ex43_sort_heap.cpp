// sort_heap() �˰��� ����
// �������� �� �����϶� ���� �����ϱ� ���ؼ��� sort_heap()�� ���.
// sort_heap()�� ����ϱ� ���ؼ��� �������� �ݵ�� �� ���¿��� �Ѵ�.



// [��� ���]
// vec1: 10 20 30 40 50 60 70 80
// make_heap(vec1.begin(), vec1.end());
// vec1: 80 50 70 40 10 60 30 20
// sort_heap(vec1.begin(), vec1.end());
// vec1: 10 20 30 40 50 60 70 80

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

	// �������� �������� �����Ѵ�.
	sort_heap(vec1.begin(), vec1.end());
	cout << "sort_heap(vec1.begin(), vec1.end());" << endl;
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}

