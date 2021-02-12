// for_each() �˰��� ����
// for_each(b,e,f)�� ���� [b,e)�� �ݺ��ڰ� ���� �� ��� ���ҿ���
// f(*p)�� ȣ���Ѵ�.
// ���⼭ f�� �Լ���(�Լ���, �Լ�, �Լ� ������)�� ����.

// �ΰ����� ������ �����ϰ� ������ �� �ִ� �Լ���(�Լ� ��ü)�� ����ϸ� �پ��� �������� ����� ���� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class PrintFunctor
{
	char fmt;
public:
	explicit PrintFunctor(char c = ' ') : fmt(c) {}
	void operator () (int n) const
	{
		cout << n << fmt;
	}
};
void Print(int n)
{
	cout << n << " ";
}
int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	for_each(Vec.begin(), Vec.begin() + 2, Print);
	cout << endl;
	for_each(Vec.begin(), Vec.begin() + 4, Print);
	cout << endl;

	// �Լ��� ��� ����
	cout << endl << "=========== �Լ��� ��� ���� ==========" << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor());
	cout << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor(','));
	cout << endl;
	for_each(Vec.begin(), Vec.end(), PrintFunctor('\n'));
	return 0;
}
// [��� ���]
// 10 20
// 10 20 30 40
// 
// =========== �Լ��� ��� ���� ==========
// 10 20 30 40 50
// 10, 20, 30, 40, 50,
// 10
// 20
// 30
// 40
// 50