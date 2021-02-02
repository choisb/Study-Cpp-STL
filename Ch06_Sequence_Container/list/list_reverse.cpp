// listÀÇ reverse() ¿¹Á¦

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> List;

    List.push_back(10);
    List.push_back(20);
    List.push_back(30);
    List.push_back(40);
    List.push_back(50);
    List.push_back(60);

    cout << "List: ";
    for (auto l : List)
        cout << l << " ";
    cout << endl;

    cout << endl;
    List.reverse();
    cout << "revers();" << endl;
    cout << endl;

    cout << "List: ";
    for (auto l : List)
        cout << l << " ";
    cout << endl;


    return 0;

}