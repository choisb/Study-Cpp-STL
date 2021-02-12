// adjacent_find() �˰��� ����
// ���������� ���� ���ҿ� ���� ���Ұ� �������� ù ������ �ݺ��ڸ� ��ȯ.
// ã�� ���Ҹ� �߰����� ���� ��� "Ž�� ������ �� �ݺ���"�� ��ȯ
//						      "�����̳��� �� �ݺ���"�� �ƴ�. �����Ұ�
//
// �����ڸ� ����ϸ� ������ ���Ұ� Ư�� ���ǿ� ���� ���������� Ž���� ���� �ִ�. 
// �̶� �����ڴ� ���� �����ڸ� ����Ѵ�. (���� ����, ���� ���Ҹ� �Ű������� ���)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int a, int b)
{
	return abs(b - a) > 10;
}

int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);	
	Vec.push_back(40);	
	Vec.push_back(50);  // �ݺ��Ǵ� ������ ����
	Vec.push_back(50);  // �ݺ��Ǵ� ������ ����
	Vec.push_back(70);
	Vec.push_back(80);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	auto iter = adjacent_find(Vec.begin(), Vec.end());	// ������ ���ۺ��� ������ Ž��.
														// ���� ���ҿ� ���� ���Ұ� �������� ù ������ �ݺ��ڸ� ��ȯ
	if (iter != Vec.end())
		cout << *iter << endl;	// �ݺ��Ǵ� ������ 50�� ����Ű�� �ݺ��� ��ȯ

	for (; iter != Vec.end(); ++iter)	// 50������ ���ҵ��� ���
		cout << *iter << " ";
	cout << endl;


	// Ž���� ������ ��� ��ȯ�� Ȯ��
	cout << "========Ž���� ������ ��� ��ȯ�� Ȯ�� ����========" << endl;

	auto iter_b = Vec.begin();
	auto iter_e = Vec.begin() + 2;
	iter = adjacent_find(iter_b, iter_e);

	// ã�� ���Ұ� �ִٸ� �� ���Ҹ� ����ϱ����� �ڵ�
	// �����̳��� end()�� �ƴ϶� Ž�� ������ ������ ���ҿ� ���ؾ� �Ѵ�.

	if (iter != iter_e)	// ã�� ���Ұ� ������ Ȯ���ϴ� �´� ǥ��
		cout << "iter != iter_e: "<<*iter << endl;

	if (iter != Vec.end())	// ã�� ���Ұ� ������ Ȯ���ϴ� Ʋ�� ǥ��
		cout << "iter != Vec.end(): " <<*iter << endl;
	cout << endl;

	// �����ڸ� Ȱ���� adjacent_find()�Լ� ����

	cout << "========�����ڸ� Ȱ���� adjacent_find()�Լ� ����========" << endl;

	iter = adjacent_find(Vec.begin(), Vec.end(), Pred);
	if (iter != Vec.end())
		cout << *iter << endl;

	for (; iter != Vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
// [��� ���
// 10 20 30 40 50 50 70 80
// 50
// 50 50 70 80
// ========Ž���� ������ ��� ��ȯ�� Ȯ�� ����========
// iter != Vec.end() : 30
// 
// ========�����ڸ� Ȱ���� adjacent_find()�Լ� ����========
// 50
// 50 70 80
