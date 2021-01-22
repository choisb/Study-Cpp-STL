#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
    MyPair(const T1& ft, const T2& sd) :first(ft), second(sd) {}
};
int main()
{
    // �츮�� ������ pair Ŭ����
    MyPair<int, int> p1(10, 20);
    cout << p1.first << ',' << p1.second << endl;
    MyPair<int, string> p2(1, "one");
    cout << p2.first << ',' << p2.second << endl;
    cout << endl;

    //stl�� �����Ǿ� �ִ� pair Ŭ����
    pair<int, int> p3(10, 20);
    cout << p3.first << ',' << p3.second << endl;
    pair<int, string> p4(1, "one");
    cout << p4.first << ',' << p4.second << endl;

    return 0;
}