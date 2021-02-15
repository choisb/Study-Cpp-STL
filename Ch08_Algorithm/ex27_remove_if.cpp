// remove_if() �˰��� ����
// ���ǿ� ���� ���Ҹ� �����ϰ��� �Ѵٸ� ������ remove_if() �˰��� ���.
// p = remove(b,e,f)�� ���� [b,e)�� ���������� f(*p)�� ���� ���Ҹ�� �����Ѵ�.
// �������� ����� remove()�� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int n)
{
	return 30 <= n && n <= 50;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(40);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(30);
	vec1.push_back(80);

	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//remove() �˰���
	auto iter_end = remove_if(vec1.begin(), vec1.end(), Pred);
	cout << endl << "remove_if(vec1.begin(), vec1.end(), Pred);" << endl << endl;
	// remvoe �� [vec1.begin(), vec1.end()) ������
	// [iter_end, vec1.end()) ���������� 30�� �����ִ� ���� Ȯ���� �� �ִ�.
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	// remove �� [vec1.begin(), iter_end()) ������
	cout << "[vec1.begin(), iter_end()): ";
	for (auto iter = vec1.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//erase() ����Լ�
	vec1.erase(iter_end, vec1.end());

	cout << endl << "vec1.erase(iter_end, vec1.end());" << endl << endl;
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	return 0;
}
// [��� ���]
// [vec1.begin(), vec1.end()): 10 40 20 30 40 30 40 30 50 60 70 30 80 | size : 13
// 
// remove(vec1.begin(), vec1.end(), Pred);
// 
// [vec1.begin(), vec1.end()): 10 20 60 70 80 30 40 30 50 60 70 30 80 | size : 13
// [vec1.begin(), iter_end()): 10 20 60 70 80 | size : 13
// 
// vec1.erase(iter_end, vec1.end());
// 
// [vec1.begin(), vec1.end()): 10 20 60 70 80 | size : 5