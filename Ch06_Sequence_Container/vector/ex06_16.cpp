#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);

    vector<int>::iterator iter;
    vector<int>::iterator iter2;
    for (iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    iter = v.begin() + 2;
    iter2 = v.erase(iter);

    cout << *iter2 << endl;

    for (iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    iter2 = v.erase(v.begin() + 1, v.end());    //[v.begin()+1 , v.end()) 구간 원소 제거
    // cout << iter2 << endl; 에러! iter2 에는 v.end()가 저장되기 떄문
    for (iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    return 0;
}