#include <iostream>
#include <algorithm>  // for_each() �˰���(����)�� ����ϱ� ���� ���
using namespace std;

///// Ŭ���̾�Ʈ /////
struct Functor1
{
    Functor1() { cout << "Functor1() ȣ�� " << endl; }
    void operator() (int n) // ������ �̿��� ���� ���
    {
        cout << n << " ";
    }
};

struct Functor2
{
    Functor2() { cout << "Functor2() ȣ�� " << endl; }
    void operator() (int n) // �� ���Ҹ� �����ؼ� ���
    {
        cout << n * n << " ";
    }
};

struct Functor3
{
    Functor3() { cout << "Functor3() ȣ�� " << endl; }
    void operator() (int n) // ���ڿ��� endl�� �̿��� ���� ���
    {
        cout << "���� : " << n << endl;
    }
};

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };

    for_each(arr, arr + 5, Functor1());
    // �ӽ� �Լ� ��ü(Functor1())�� ����� �Լ��� ����

    cout << endl << endl;
    for_each(arr, arr + 5, Functor2());
    // �ӽ� �Լ� ��ü(Functor2())�� ����� �Լ��� ����

    cout << endl << endl;
    for_each(arr, arr + 5, Functor3());
    // �ӽ� �Լ� ��ü(Functor3())�� ����� �Լ��� ����
}