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

    for (auto v : v1)
        cout << v << endl;
    
    cout << v1[0] << ", " << v1.front() << endl;
    cout << v1[5] << ", " << v1.back() << endl;

    v1.front() = 100;
    v1.back() = 200;

    cout << v1[0] << ", " << v1.front() << endl;
    cout << v1[5] << ", " << v1.back() << endl;

    return 0;


}