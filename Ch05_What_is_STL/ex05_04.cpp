#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);

    sort(v.begin(), v.end());   // ���� ���� (vector�� ���� ���� �ݺ���)
    sort(lt.begin(), lt.end()); // ����! (list�� ����� �ݺ���, ���� ���� �Ұ�)

    return 0;
}