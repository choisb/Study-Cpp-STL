// erase()�� insert() �������� vector�� list�� ������

// �Ʒ��� �ڵ�� ��� ���� �����ϳ� �������� ���̰� ����
// ���Ϳ����� �����Ͱ� ���Ե� �� ���� ��� �����Ͱ� ��ĭ�� �̵�
// ���Ϳ����� �޸� �ʰ��� �޸� ���Ҵ��� �Ͼ�鼭 �ݺ��ڰ� ��ȿȭ�� �Ǳ⵵ �Ѵ�.
// �ݸ� ����Ʈ�� ��� ������ O(1)�� �ſ� ���� �ӵ��� ó���� �� �ִ�.
// erase������ ������.

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    vector<int> Vec;
    list<int> List;

    Vec.push_back(10);
    Vec.push_back(20);
    Vec.push_back(30);
    Vec.push_back(40);
    Vec.push_back(50);
    Vec.push_back(60);

    List.push_back(10);
    List.push_back(20);
    List.push_back(30);
    List.push_back(40);
    List.push_back(50);
    List.push_back(60);

    auto viter = Vec.begin();
    viter++;

    auto liter = List.begin();
    liter++;

    viter = Vec.insert(viter, 600);     // Vec �� �� ��° ��ҷ� ����
    liter = List.insert(liter, 600);    // List�� �ι�° ��ҷ� ����

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;
 
    viter = Vec.insert(viter, 700);     // Vec �� �� ��° ��ҷ� ����
    liter = List.insert(liter, 700);    // List�� �ι�° ��ҷ� ����

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;
 
    viter = Vec.insert(viter, 800);     // Vec �� �� ��° ��ҷ� ����
    liter = List.insert(liter, 800);    // List�� �ι�° ��ҷ� ����

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;

    viter = Vec.insert(viter, 900);     // Vec �� �� ��° ��ҷ� ����
    liter = List.insert(liter, 900);    // List�� �ι�° ��ҷ� ����

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;

    for (auto v : Vec)
        cout << v << " ";
    cout << endl;

    for (auto l : List)
        cout << l << " ";
    cout << endl;


    return 0;

}