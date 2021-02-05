// set의 key_comp() & value_comp()
// key_comp()함수는 해당 set 컨테이너의 조건자를 반환한다.
// set은 원소가 곧 key이자 value이므로 key_comp()와 value_comp()가 동일한 것을 확인 할 수 있다.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int, less<int>> Set_less; // set<int> 와 같음
    set<int, greater<int>> Set_greater;

    Set_less.insert(50);
    Set_less.insert(10);
    Set_less.insert(30);
    Set_less.insert(20);
    Set_less.insert(40);

    Set_greater.insert(50);
    Set_greater.insert(10);
    Set_greater.insert(30);
    Set_greater.insert(20);
    Set_greater.insert(40);

    //set<int, less<int>>::key_compare l_cmp = Set_less.key_comp(); 
    auto l_cmp = Set_less.key_comp();
    cout << l_cmp(10, 20) << endl;  // 10 < 20 연산

    //set<int, greater<int>>::key_compare g_cmp = Set_greater.key_comp(); 
    auto g_cmp = Set_greater.key_comp();
    cout << g_cmp(10, 20) << endl;  // 10 > 20 연산

    cout << "key_compare type: " << typeid(Set_less.key_comp()).name() << endl;
    cout << "key_compare type: " << typeid(Set_greater.key_comp()).name() << endl;
    cout << "value_compare type: " << typeid(Set_less.value_comp()).name() << endl;
    cout << "value_compare type: " << typeid(Set_greater.value_comp()).name() << endl;

    return 0;
}
// [출력 결과]
// 1
// 0
// key_compare type : struct std::less<int>
// key_compare type : struct std::greater<int>
// value_compare type : struct std::less<int>
// value_compare type : struct std::greater<int>