// nth_element() 알고리즘 예제
// 순차열의 원소 중 n개의 원소를 선별(기본 사전순, 조건자 사용가능)하고자 한다면 nth_element() 알고리즘 사용
// nth_element(b,m,e) 알고리즘은 구간 [b,e)의 원소 중 m-b개 만큼의 원소를 선별(사전순)하여 [b,m)의 순차열에 놓이게함.
// nth_element(b,m,e,f)로 조건자를 활용할 수도 있다.

// [출력 결과]
// v[상위 20개] : 41 106 141 35 169 253 37 153 82 35 118 145 190 84 101 6 264 40 281 288
// v[하위 80개] : 292 299 308 316 322 323 333 334 350 358 370 376 382 391 393 421 436 439 446 447 464 467 478 491 500 529 537 538 538 541 724 962 705 827 995 942 827 604 902 961 741 711 547 842 723 664 673 942 859 912 868 805 890 729 757 662 644 811 667 648 629 623 703 954 756 840 966 869 931 778 944 771 626 726 895 718 894 716 929 548
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

	nth_element(vec1.begin(), middle, vec1.end());

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



