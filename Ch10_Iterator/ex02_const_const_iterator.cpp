// iterator�� const_iterator�� constȭ
// const Ű���带 ���ؼ� �ݺ��ڰ� �ٸ� ���Ҹ� ����ų�� ������ ���ȭ ��ų �� �ִ�.

// [��� ���]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	// iter
	vector<int>::iterator iter = vec1.begin();
	*iter = 20;
	iter++;

	// citer
	vector<int>::const_iterator citer = vec1.begin();
	//*citer = 20;
	citer++;

	// const_iter
	const vector<int>::iterator const_iter = vec1.begin();
	*const_iter = 30;
	//const_iter++;

	// const_citer
	const vector<int>::const_iterator const_citer = vec1.begin();
	//*const_citer = 30;
	//const_citer++;

	// ������ ����

	int i;
	int j;

	const int *pi1;

	int * const pi2 = &i;

	pi1 = &j;
	//pi2 = &j;

	//*pi1 = 10;
	*pi2 = 10;


	return 0;
}



