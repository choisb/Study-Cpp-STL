// multimap의 find() 관련 예제
// multimap은 find(), count(), lower_bound(), upper_bound(), equal_range()를 제공한다.

#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> Multimap;

    Multimap.insert(pair<int, int>(5, 100));
    Multimap.insert(pair<int, int>(1, 200));
    Multimap.insert(pair<int, int>(2, 300));
    Multimap.insert(pair<int, int>(4, 400));
    Multimap.insert(pair<int, int>(6, 500));
    Multimap.insert(pair<int, int>(3, 600));

    // 중복 데이터 입력
    Multimap.insert(pair<int, int>(1, 20));
    Multimap.insert(pair<int, int>(1, 30));
    Multimap.insert(pair<int, int>(2, 40));

    for (auto m : Multimap)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // count() : 해당 원소의 개수 반환
    cout << "key가 1인 원소의 개수" << Multimap.count(1) << endl;

    // find() : 해당 원소의 첫 번째 반복자 반환
    auto iter = Multimap.find(1);
    if (iter != Multimap.end())
        cout << "첫 번째 key 1에 매핑된 value: " << iter->second << endl;

    //lower_bound(), upper_bound() : 해당 원소의 첫 번째 반복자와 마지막 원소 다음의 반복자를 각각 반환
    auto lower_iter = Multimap.lower_bound(1);
    auto upper_iter = Multimap.upper_bound(1);

    cout << "구간 [lower_iter, upper_iter)의 순차열: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    // equal_range() 함수
    auto iter_pair = Multimap.equal_range(1);
    cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// (1, 200) (1, 20) (1, 30) (2, 300) (2, 40) (3, 600) (4, 400) (5, 100) (6, 500)
// key가 1인 원소의 개수3
// 첫 번째 key 1에 매핑된 value : 200
// 구간[lower_iter, upper_iter)의 순차열 : (1, 200) (1, 20) (1, 30)
// 구간[iter_pair.first, iter_pair.second)의 순차열 : (1, 200) (1, 20) (1, 30)