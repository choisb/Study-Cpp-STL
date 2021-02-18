// partial_sort() 알고리즘 예제
// 순차열의 상위 구간만을 정렬하거나 힙정렬의 특징이 필요하다면 partial_sort() 알고리즘을 사용
// partial_sort(b,m,e) 알고리즘은 구간 [b,e)의 원소를 [b,m)의 순차열에 원소를 정렬
// 만약 m을 e와 동일하게 하면 순차열의 모든 원소를 정렬할 수 있다.
//
// 조건자 버전 partial_sort(b,m,e,f) 알고리즘은 f를 정렬 규칙으로 사용한 정렬을 수행한다.

// [출력 결과]
// v[상위 20개] : 6 35 35 37 40 41 82 84 101 106 118 141 145 153 169 190 253 264 281 288
// v[하위 80개] : 995 962 961 942 902 827 827 724 718 895 716 726 771 705 869 912 667 604 538 894 703 811 500 491 673 664 478 711 467 868 547 644 662 757 464 859 723 741 529 778 447 436 421 842 391 382 358 942 334 648 446 805 890 729 370 350 333 322 393 548 629 623 316 954 756 840 966 376 931 308 944 439 626 323 537 538 299 292 929 541

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


	cout << "v[상위 20개] : ";
	for (auto iter = vec1.begin(); iter != middle; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "v[하위 80개] : ";
	for (auto iter = middle; iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	return 0;
}



