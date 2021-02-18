// ���ĵ� ���� �˰���
// ���ĵ� ���� �˰����� ����ϱ� ���ؼ��� �Է� �������� �ݵ�� ���ĵ� �־�� �Ѵ�.
//
// binary_search() �˰��� ����
// binary_search(b,e,x)�� ����[b,e)�� ���������� x�� ���� ���Ұ� ������ true�� ��ȯ, ������ false�� ��ȯ 
// �������� ���Ұ� �⺻ ���� ������ less(<)�� ����(��������)�� �ִٴ� ���� �Ͽ� ����
// binary_search() �˰����� ���Ҹ� ã�� ���� �� ���� a, b�� ���� a == b ������ ������� �ʰ� !(a<b) && !(b>a) ������ ����Ѵ�.
//
// binary_search()�˰��� ������ ������ �����ϴµ�, ������ ������ ���ؼ� ���� ���꿡 ���� ���ø� �ٷ��.
// binary_search(b,e,x,f)�� ���� [b,e)�� ���� �� x ���ҿ� ���� ���Ұ� �ִٸ� true, �ƴ϶�� false ��ȯ. (f�� ���� ������)


// [��� ���]
// vec1: 10 20 30 40 50 60 70 80
// 20 ���Ұ� �����մϴ�.
// 
// *** ������ ���� ***
// ���� vec2: 40 46 12 80 10 47 30 55 90 53
// ���� vec2: 12 10 30 40 46 47 55 53 80 90
// 32 ���Ұ� �����մϴ�.
// 35 ���Ұ� �������� �ʽ��ϴ�.

// <<�߰� ����>>
// ��°������ ���ĵ� vec2�� ���� 12�� 10���� �ռ��ִ� ���� �� �� �ִ�. 55 53�� ��������
// ���� vec2�� �������� �ʴ� ���� 32������ binary_search()��� true�� ��ȯ�ϴ� �͵� �� �� �ִ�.
// �̷��� ���� ������ ������ a == b ������ ������� �ʰ� !(a<b) && !(b>a) ������ ����ϱ� �����̴�.
// !(Pred(30,32)) && !(Pred(32,30)) �� true�̸� �� ���Ҵ� ������ ���� �����Ѵ�. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return 3 < right - left;
}
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

	if(binary_search(vec1.begin(), vec1.end(), 20))
		cout << "20 ���Ұ� �����մϴ�." << endl;
	else
		cout << "20 ���Ұ� �������� �ʽ��ϴ�."<<endl;
 

	cout << endl << "*** ������ ���� ***" << endl;
	vector<int> vec2;
	vec2.push_back(40);
	vec2.push_back(46);
	vec2.push_back(12);
	vec2.push_back(80);
	vec2.push_back(10);
	vec2.push_back(47);
	vec2.push_back(30);
	vec2.push_back(55);
	vec2.push_back(90);
	vec2.push_back(53);

	cout << "���� vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	sort(vec2.begin(), vec2.end(), Pred);

	cout << "���� vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// ���������� �� ������ ���� 3���� ũ�ٸ� ���� ��ġ�� ���ҷ� �����ϰ� �˻�

	if (binary_search(vec1.begin(), vec1.end(), 32, Pred))
		cout << "32 ���Ұ� �����մϴ�." << endl;
	else
		cout << "32 ���Ұ� �������� �ʽ��ϴ�." << endl;


	if (binary_search(vec1.begin(), vec1.end(), 35, Pred))
		cout << "35 ���Ұ� �����մϴ�." << endl;
	else
		cout << "35 ���Ұ� �������� �ʽ��ϴ�." << endl;

	return 0;
}



