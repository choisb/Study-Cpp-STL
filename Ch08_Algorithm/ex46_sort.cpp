// sort() 알고리즘 예제
// 정렬 알고리즘에는 다음 3가지가 존재
// sort(): 퀵정렬을 기반
// stable_sort(): 머지정렬을 기반, 같은 원소의 정렬에서 원소의 상대적인 순서가 유지
// partial_sort(): 힙정렬을 기반, 힙정렬이기 때문에 언제든지 O(NlogN) 복잡도 보장

// [출력 결과]
// vec1: 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827 436 391 604 902 153 292 382 421 716 718 895
// sort(vec1.begin(), vec1.end());
// vec1: 41 145 153 169 281 292 334 358 382 391 421 436 464 467 478 491 500 604 705 716 718 724 827 827 895 902 942 961 962 995
// sort(vec1.begin(), vec1.end(), Greater);
// vec1: 995 962 961 942 902 895 827 827 724 718 716 705 604 500 491 478 467 464 436 421 391 382 358 334 292 281 169 153 145 41
// 
// stable_sort() 예제
// vec2: 447 726 771 538 869 912 667 299 35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757 37 859 723 741 529 778
// stable_sort(vec2.begin(), vec2.end());
// vec2: 447 726 771 538 869 912 667 299 35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757 37 859 723 741 529 778
// stable_sort(vec2.begin(), vec2.end(), Greater);
// vec2: 912 894 869 868 859 811 778 771 757 741 726 723 711 703 673 667 664 662 644 547 538 529 447 333 322 299 253 141 37 35

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Greater(int left, int right)
{
	return left > right;
}
int main()
{
	vector<int> vec1;

	for (int i = 0; i < 30; ++i)
		vec1.push_back(rand() % 1000);


	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "sort(vec1.begin(), vec1.end());" << endl;
	sort(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "sort(vec1.begin(), vec1.end(), Greater);" << endl;
	sort(vec1.begin(), vec1.end(), Greater);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// stable_sort() 예제
	vector<int> vec2;
	cout << endl << "stable_sort() 예제" << endl;
	for (int i = 0; i < 30; ++i)
		vec2.push_back(rand() % 1000);


	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	cout << "stable_sort(vec2.begin(), vec2.end());" << endl;
	stable_sort(vec1.begin(), vec1.end());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	cout << "stable_sort(vec2.begin(), vec2.end(), Greater);" << endl;
	stable_sort(vec2.begin(), vec2.end(), Greater);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;


	return 0;
}



