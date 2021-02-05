// map에서 [] 연산자 예제
// map에서는 []연산자를 사용해서 쉽게 원소를 추가하거나 value 값을 갱신할 수 있다.
// key에 해당하는 원소가 map에 없다면 원소를 추가하는 연산을 수행.
// key에 해당하는 원소가 있다면 key에 해당하는 원소의 L-value를 반환.

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

    // []연산자를 통해서 값 수정
    Map[1] = 11;
    Map[3] = 11;
    Map[9] = 11;

    for (auto m : Map)
    {
        cout << "(" << m.first << "," << m.second << ") ";
    }
    cout << endl;

    return 0;
}
// [출력 결과]
// (1, 800) (3, 800) (4, 800) (5, 800) (7, 800) (8, 800) (9, 800)
// (1, 11) (3, 11) (4, 800) (5, 800) (7, 800) (8, 800) (9, 11)