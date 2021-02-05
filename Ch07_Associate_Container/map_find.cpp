// map에서 find 함수들
// map에서도 find(), lower_bound(), upper_bound(), equal_range() 함수를 제공한다.


#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> Map;

    // []연산자를 통해서 값 삽입
    Map[5] = 800;
    Map[3] = 800;
    Map[8] = 800;
    Map[4] = 800;
    Map[1] = 800;
    Map[7] = 800;
    Map[9] = 800;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    // find() 함수
    auto iter = Map.find(5);
    if (iter != Map.end())
        cout << "key 5에 매핑된 value: " << iter->second << endl;

    // lower_bound(), upper_bound() 함수
    auto lower_iter = Map.lower_bound(4);
    auto upper_iter = Map.upper_bound(4);

    cout << "구간 [lower_iter, upper_iter)의 순차열: ";
    for (iter = lower_iter; iter != upper_iter; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    // equal_range() 함수
    auto iter_pair = Map.equal_range(7);
    cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
    for (iter = iter_pair.first; iter != iter_pair.second; iter++)
    {
        cout << "(" << iter->first << "," << iter->second << ") ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// (1, 800) (3, 800) (4, 800) (5, 800) (7, 800) (8, 800) (9, 800)
// key 5에 매핑된 value : 800
// 구간[lower_iter, upper_iter)의 순차열 : (4, 800)
// 구간[iter_pair.first, iter_pair.second)의 순차열 : (7, 800)