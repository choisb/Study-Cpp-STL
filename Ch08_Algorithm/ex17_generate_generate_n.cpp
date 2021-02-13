// generate(), generate_n() �˰��� ����
// �������� ��� ���Ҹ� �ܼ��� ������ ������ �����Ϸ��� generate() �˰����� ���
// generate(b,e,f) �˰����� ���� [b, e)�� ��� ���Ҹ� f()�� ä���.
// generate_n(b,n,f) �˰����� ����[b, b+n)�� ��� ���Ҹ� f()�� ä���.
// 
// for_each()���� ���̴�, for_each()�� �Լ��ڿ��� ���Ҹ� �Ű������� �޾Ƽ� Ȱ���� �� ������,
// generate()�� ���ҿ� ���� ������ �� ���� �� ������ ���� ������ ���� ����.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ������ 1�� �����ϸ� �������� ä��� generate()�� ����� �Լ���
class Integer {
	int data;
public:
	explicit Integer(int d = 0) : data(d) {}
	int operator()()
	{
		return data++;
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())�� ���Ҹ� 1 ~ 5�� ä��
	generate(vec.begin(), vec.end(), Integer());
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())�� ���Ҹ� 100 ~ 104�� ä��
	generate(vec.begin(), vec.end(), Integer(100));
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// [vec.begin(), vec.end())�� ���Ҹ� 100 ~ 104�� ä��
	generate_n(vec.begin(), 3, Integer(1));
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec: 10 20 30 40 50 60
// vec : 0 1 2 3 4 5
// vec : 100 101 102 103 104 105
// vec : 1 2 3 103 104 105