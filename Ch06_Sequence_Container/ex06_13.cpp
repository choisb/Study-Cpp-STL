#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);

    vector<int>::iterator iter; // 정방향 반복자
    vector<int>::reverse_iterator riter; //역방향 반복자

    for (iter = v1.begin(); iter != v1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    for (riter = v1.rbegin(); riter != v1.rend(); riter++)
        cout << *riter << " ";
    cout << endl;


    return 0;
}