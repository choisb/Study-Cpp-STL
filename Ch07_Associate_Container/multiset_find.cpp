//multiset의 탐색관련 함수들
// find(), count(), lower_bound(), upper_bound(), equal_range()를 제공한다.
// find() 해당 원소의 반복자 반환, 중복 원소가 있다면 첫번째 원소의 반복자 반환
// count() 해당 원소의 갯수 반환
// lower_bound() 해당 원소의 시작 반복자 반환
// upper_bound() 해당 원소의 마지막의 다음 반복자 반환
// equal_range() 해당 원소의 구간을 pair 객체로 반환. lower_bound()와 upper_bound()가 들어있다.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> Multiset;


    Multiset.insert(50);
    Multiset.insert(30);
    Multiset.insert(80);
    Multiset.insert(80);    // 중복
    Multiset.insert(30);    // 중복
    Multiset.insert(70);
    Multiset.insert(10);

    for (auto ms : Multiset)
    {
        cout << ms << " ";
    }
    cout << endl;

    cout << "30의 원소의 개수: " << Multiset.count(30) << endl;

    auto iter = Multiset.find(30); // 30 첫번째 원소의 반복자
    cout << "iter: " << *iter << endl;

    auto lower_iter = Multiset.lower_bound(30);     // 30 순차열의 시작 반복자
    auto upper_iter = Multiset.upper_bound(30);     // 30 순차열의 끝 반복자

    cout << "lower_iter: " << *lower_iter << endl;
    cout << "upper_iter: " << *upper_iter << endl;

    cout << "구간 [lower_iter, upper_iter)의 순차열: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    auto iter_pair = Multiset.equal_range(80);
    cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
// [출력 결과]
// 10 30 30 50 70 80 80
// 30의 원소의 개수 : 2
// iter : 30
// lower_iter : 30
// upper_iter : 50
// 구간[lower_iter, upper_iter)의 순차열 : 30 30
// 구간[iter_pair.first, iter_pair.second)의 순차열 : 80 80