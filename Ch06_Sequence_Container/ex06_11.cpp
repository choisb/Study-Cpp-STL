#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator iter;
    vector<int>::const_iterator citer;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;


    for (iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl;
      
    iter -= 3;
    cout << *iter << endl;

    iter += 2;
    cout << *iter << endl;

    iter = v.begin();
    citer = v.begin();

    cout << *iter << endl;
    cout << *citer << endl;

    cout << *++iter << endl;
    cout << *++citer << endl;

    *iter = 100;
    //*citer = 100; //상수 반복자는 가리키는  원소를 변경할 수 없다.

    cout << *iter << endl;
    cout << *citer << endl;


    return 0;
}