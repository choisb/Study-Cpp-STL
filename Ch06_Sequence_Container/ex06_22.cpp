// erase()와 insert() 과정에서 vector와 list의 차이점

// 아래의 코드는 결과 값은 동일하나 내부적인 차이가 존재
// 벡터에서는 데이터가 삽입될 때 마다 모든 데이터가 한칸씩 이동
// 벡터에서는 메모리 초과시 메모리 재할당이 일어나면서 반복자가 무효화가 되기도 한다.
// 반면 리스트는 노드 삽입을 O(1)의 매우 빠른 속도로 처리할 수 있다.
// erase에서도 동일함.

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

    viter = Vec.insert(viter, 600);     // Vec 의 두 번째 요소로 삽입
    liter = List.insert(liter, 600);    // List의 두번째 요소로 삽입

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;
 
    viter = Vec.insert(viter, 700);     // Vec 의 두 번째 요소로 삽입
    liter = List.insert(liter, 700);    // List의 두번째 요소로 삽입

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;
 
    viter = Vec.insert(viter, 800);     // Vec 의 두 번째 요소로 삽입
    liter = List.insert(liter, 800);    // List의 두번째 요소로 삽입

    cout << "viter: " << *viter << " | Vector Size: " << Vec.size() << " | Vector Capacity: " << Vec.capacity() << endl;
    cout << "liter: " << *liter << " | List Size: " << List.size() << endl;

    viter = Vec.insert(viter, 900);     // Vec 의 두 번째 요소로 삽입
    liter = List.insert(liter, 900);    // List의 두번째 요소로 삽입

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