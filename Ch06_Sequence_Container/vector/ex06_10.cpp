#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10, 1);    // 초깃값 1의 5개 원소를 갖는 컨테이너 생성

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;


    v.assign(5, 2); // 5개의 원소값을 2로 할당

    for (auto vec : v)
        cout << vec << " ";
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;


    return 0;
}