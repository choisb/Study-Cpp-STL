// stable_partition() �˰��� ����
// partition()�˰����� �з� �������� ���ҵ��� ����� ������ �ڼ��δ�.
// ���ҵ��� ����� ������ �����ϱ� ���ؼ��� stable_partition()�˰��� ���.
// ������ partition()�˰���� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return n < 40;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(70);
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(50);
	vec1.push_back(30);
	vec1.push_back(20);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// ������ ����� ������ �����ϸ� 40 ���Ҹ� �������� �̸��� �̻��� �з�
	auto iter_sep = stable_partition(vec1.begin(), vec1.end(), Pred);

	cout << "40�̸��� ������: ";
	for (auto iter = vec1.begin(); iter != iter_sep; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "40�̻��� ������: ";
	for (auto iter = iter_sep; iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	return 0;
}
// [��� ���]
// vec1: 70 10 20 40 60 70 50 30 20
// 40�̸��� ������ : 10 20 30 20
// 40�̻��� ������ : 70 40 60 70 50
