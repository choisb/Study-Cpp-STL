// for_each() �˰��� ����
// for_each() �˰����� ���Ҹ� �����ϴ� �˰������ε� ����� �� �ִ�.
// for_each(b, e, f)�� ���� [b, e)�� �ݺ��ڰ� p��� ��� ���ҿ� f(*p)�� ����.
//
// �Լ��ڸ� ����ϸ� for_each()�� ���� �پ��� �۾��� �� �� �ִ�.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Accumulation
{
	int total;
public:
	explicit Accumulation(int init = 0) :total(init) {}
	void operator() (int &r)	// �Ű������� ���޹��� ���Ҹ� �����ϱ� ���� &(���۷���)�� ���
	{
		total += r;
		r = total;
	}
};

// �Ű������� ���޹��� ���Ҹ� �����ϱ� ���� &(���۷���)�� ���
void Func(int& r)
{
	r += 5;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// for_each()�� �Լ������� ��� ����
	cout << "for_each()�� �Լ������� ��� ����" << endl;
	for_each(vec.begin(), vec.end(), Func);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// for_each()�� �Լ��ڸ� ����� ����
	cout << "for_each()�� �Լ��ڸ� ����� ����" << endl;
	for_each(vec.begin(), vec.end(), Accumulation());
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec: 10 20 30 40 50
// for_each()�� �Լ������� ��� ����
// vec : 15 25 35 45 55
// for_each()�� �Լ��ڸ� ����� ����
// vec : 15 40 75 120 175