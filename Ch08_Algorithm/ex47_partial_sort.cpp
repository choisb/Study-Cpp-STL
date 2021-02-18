// partial_sort() �˰��� ����
// �������� ���� �������� �����ϰų� �������� Ư¡�� �ʿ��ϴٸ� partial_sort() �˰����� ���
// partial_sort(b,m,e) �˰����� ���� [b,e)�� ���Ҹ� [b,m)�� �������� ���Ҹ� ����
// ���� m�� e�� �����ϰ� �ϸ� �������� ��� ���Ҹ� ������ �� �ִ�.
//
// ������ ���� partial_sort(b,m,e,f) �˰����� f�� ���� ��Ģ���� ����� ������ �����Ѵ�.

// [��� ���]
// v[���� 20��] : 6 35 35 37 40 41 82 84 101 106 118 141 145 153 169 190 253 264 281 288
// v[���� 80��] : 995 962 961 942 902 827 827 724 718 895 716 726 771 705 869 912 667 604 538 894 703 811 500 491 673 664 478 711 467 868 547 644 662 757 464 859 723 741 529 778 447 436 421 842 391 382 358 942 334 648 446 805 890 729 370 350 333 322 393 548 629 623 316 954 756 840 966 376 931 308 944 439 626 323 537 538 299 292 929 541

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	for (int i = 0; i < 100; ++i)
		vec1.push_back(rand() % 1000);

	auto middle = vec1.begin() + 20;
	partial_sort(vec1.begin(), middle, vec1.end());


	cout << "v[���� 20��] : ";
	for (auto iter = vec1.begin(); iter != middle; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "v[���� 80��] : ";
	for (auto iter = middle; iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	return 0;
}



