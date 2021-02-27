// iterator와 const_iterator의 const화
// const 키워드를 통해서 반복자가 다른 원소를 가르킬수 없도록 상수화 시킬 수 있다.

// [출력 결과]

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

	// 유사한 개념

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



