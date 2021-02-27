// iterator�� const_iterator�� ����

// [��� ���]
// vec1[iterator �б� ����] : 10 20 30 40 50
// vec1[const iterator �б� ����] : 10 20 30 40 50

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

	cout << "vec1[iterator �б� ����] : ";
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "vec1[const iterator �б� ����] : ";
	for (vector<int>::const_iterator citer = vec1.begin(); citer != vec1.end(); citer++)
		cout << *citer << " ";
	cout << endl;

	// ���� ����
	vector<int>::iterator iter = vec1.begin();
	*iter = 20;
	
	// const_iterator�� ���� �Ұ���
	vector<int>::const_iterator citer = vec1.begin();
	//*citer = 20;

	return 0;
}



