#include <iostream>
using namespace std;

class Adder
{
    int total;
public:
    explicit Adder(int n = 0) : total(n) { }
    int operator() (int n)  // 암묵적으로 인라인 함수로 적용됨
    {
        return total += n;
    }
};
int main()
{
    Adder add(0); // total의 초깃값 0

    cout << add(10) << endl;    //  add.total: 10
    cout << add(20) << endl;    //  add.total: 30
    cout << add(30) << endl;    //  add.total: 60

    return 0;
}