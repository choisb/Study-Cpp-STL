// remove_copy() �˰��� ����
// ������ ������ �������� �ʰ� Ư�� ���Ҹ� �����Ͽ� ������ �������� �����ϰ��� �Ѵٸ� remove_copy() �˰����� ���.
// p=remove_copy(b,e,t,x)�� ���� [b,e) ���������� *p==x�� ���Ҹ� ������ ���Ҹ� ������ [t,p)�� ����. (����� ���� ����)

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
	vec1.push_back(30);
	vec1.push_back(70);
	vec1.push_back(80);

	vector<int> vec2(8);


	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	//remove_copy() �˰���
	auto iter_end = remove_copy(vec1.begin(), vec1.end(), vec2.begin(), 30);
	cout << endl << "remove_copy(vec1.begin(), vec1.end(), vec2.begin(), 30);" << endl << endl;
	// remvoe �� [vec1.begin(), vec1.end()) ������
	cout << "[vec1.begin(), vec1.end()): ";
	for (auto v : vec1)
		cout << v << " ";
	cout << " | size: " << vec1.size();
	cout << endl;

	// remove �� [vec2.begin(), vec2.end()) ������
	cout << "[vec2.begin(), vec2.end()): ";
	for (auto v : vec2)
		cout << v << " ";
	cout << " | size: " << vec2.size();
	cout << endl;

	cout << "[vec2.begin(), iter_end): ";
	for (auto iter = vec2.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << " | size: " << vec2.size();
	cout << endl;

	return 0;
}
// [��� ���]
// [vec1.begin(), vec1.end()): 10 20 30 40 50 30 70 80 | size : 8
// 
// remove(vec1.begin(), vec1.end(), Pred);
// 
// [vec1.begin(), vec1.end()): 10 20 30 40 50 30 70 80 | size : 8
// [vec2.begin(), vec2.end()): 10 20 40 50 70 80 0 0 | size : 8
// [vec2.begin(), iter_end): 10 20 40 50 70 80 | size : 8