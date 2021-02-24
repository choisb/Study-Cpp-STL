// ptr_fun ���� (`C++11` ���� ������� �ʰ�, `C++17` ���� ������)
// �Լ� ������ ��͸� Ȱ���ؼ� �Ϲ��Լ� Pred�� �Լ���ü�� ��ȯ�ϱ� ���Ͽ� ���
// ���� �Ϲ� �Լ�Pred �� not1() ��Ϳ� �����ϱ� ���ؼ��� 
// �Ϲ� �Լ� Pred�� �Լ� ������ ��ͷ� �Լ���ü�� ��ȯ �� not1() ��͸� �����ؾ� �ߴ�.
//
// C++17 ���ĺ��ʹ� ������ ��ȯ���� ���� not_fn()�� �Ϲ��Լ��� �ٷ� ������ �� �ִ�.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
using namespace std;

bool Pred(int n)
{
	return 30 <= n && n <= 40;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "30�̻� 40������ ���� ����: " << count_if(vec1.begin(), vec1.end(), Pred) << endl;
	
	//C++17 ���� �Լ� ������ ��͸� Ȱ���ؼ� �Ϲ��Լ� Pred�� �Լ���ü�� ��ȯ�Ͽ�
	//cout << "30�̻� 40���ϰ� �ƴ� ���� ����: " << count_if(vec1.begin(), vec1.end(), (ptr_fun(Pred))) << endl;

	//C++17 ����
	cout << "30�̻� 40���ϰ� �ƴ� ���� ����: " << count_if(vec1.begin(), vec1.end(), not_fn(Pred)) << endl;
}