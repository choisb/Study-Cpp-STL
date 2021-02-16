// unique() �˰��� ����
// �������� ���� ���Ҹ� �����ϰ� ������� �Ѵٸ� unique() �˰��� ���
// p = unique(b,e)�� ���� [b,e)�� �������� ������ �ߺ� ���Ұ� ���� �ʰ� �Ѵ�.
// �˰��� ���� �� �������� [b,q)�� �ȴ�.
// unique() �˰��� ���Ҹ� �������θ� �����Ѵ�.
// ���� ���¿��� unique()�˰����� �����Ѵٸ� ��� ���Ҹ� �����ϰ� ���� �� �ִ�.


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
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	auto iter_end = unique(vec1.begin(), vec1.end());
	cout << endl << "unique(vec1.begin(), vec1.end());" << endl << endl;
	// unique �� [vec1.begin(), vec1.end()) ������
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;
	// unique �� [vec1.begin(), iter_end) ������
	cout << "[vec2.begin(), iter_end): ";
	for (auto iter = vec1.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	

	return 0;
}
// [��� ���]
// [vec1.begin(), vec1.end()): 10 20 30 30 40 40 30 30 50 60 | size : 10
// 
// unique(vec1.begin(), vec1.end());
// 
// [vec1.begin(), vec1.end()) : 10 20 30 40 30 50 60 30 50 60 | size : 10
// [vec2.begin(), iter_end): 10 20 30 40 30 50 60 | size : 10