#include <iostream>
#include <vector>
using namespace std;

class Actor{
public:
    Actor(int _n)
        : num(_n)
    {
        cout << num << "��ü ����" << endl;
    }
    const int GetNum() { return num; }
    ~Actor() 
    {
        cout << num << "��ü ����" << endl;
    }
private:
    const int num;
};

int main()
{

    vector<Actor*> actors;
    vector<Actor*> deadActors;

    actors.emplace_back(new Actor(1));
    actors.emplace_back(new Actor(2));
    actors.emplace_back(new Actor(3));
    actors.emplace_back(new Actor(4));

    for (auto actor : actors)
    {
        cout << actor->GetNum() << "�� ��ü: " << actor << endl;
    }

    deadActors.emplace_back(actors[2]);
    deadActors.emplace_back(actors[1]);

    for (auto actor : deadActors)
    {
        delete actor;
    }

    for (auto actor : actors)
    {
        cout << actor->GetNum() << "�� ��ü: " << actor << endl;
    }
    cout << endl;
    cout << "size: " << actors.size() << " capacity: " << actors.capacity() << endl;
    return 0;
}