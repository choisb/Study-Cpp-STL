#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    // �⺻ �����ڷ� ���� vector�����̳�(�ӽð�ü: size, capacity�� 0�̴�.)�� v�� swap�Ѵ�. 
    vector<int>().swap(v);
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    return 0;
}