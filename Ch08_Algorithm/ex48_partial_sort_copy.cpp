// partial_sort_copy() �˰��� ����
// �������� ���� �������� �����Ͽ� ������ �������� �����Ϸ��� partial_sort_copy() �˰��� ���
// partial_sort_copy(b,e,b2,e2) �˰����� ���� [b,e)�� ���� �� e2 - b2���� ���� ���Ҹ� �����Ͽ�
// [b2, e2)�� �������� ����.
// ������ ������ partial_sort_copy(b,e,b2,e2,f)�� ����� �� �ִ�.

// [��� ���]
// vec1: 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912 667 299 35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757 37 859 723 741 529 778 316 35 190 842 288 106 40 942 264 648 446 805 890 729 370 350 6 101 393 548 629 623 84 954 756 840 966 376 931 308 944 439 626 323 537 538 118 82 929 541
// vec2(less) : 6 35 35 37 40 41 82 84 101 106 118 141 145 153 169 190 253 264 281 288
// vec2(greater) : 995 966 962 961 954 944 942 942 931 929 912 902 895 894 890 869 868 859 842 840

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	for (int i = 0; i < 100; ++i)
		vec1.push_back(rand() % 1000);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;


	vector<int> vec2(20); //size 20�� vector ����

	partial_sort_copy(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());

	cout << "vec2(less) : ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	partial_sort_copy(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),greater<int>());

	cout << "vec2(greater) : ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}



