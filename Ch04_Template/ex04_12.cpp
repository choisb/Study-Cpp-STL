#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while (begin != end)
    {
        pf(*begin++);
    }
}

template<typename T>
struct PrintFunctor
{
    string sep; // ��� ������ ����

    explicit PrintFunctor(const string& s = " ") : sep(s) {}
    void operator() (T data) const
    {
        cout << data << sep;
    }
};

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    string sarr[3] = { "abc", "ABC", "Hello" };

    // ���� ���, ������ �Լ� ���ø� ȣ��
    For_each(arr, arr + 5, PrintFunctor<int>());    // ����Ʈ �Ű����� s = " " ���
    cout << endl;

    // ���ڿ� ���, ������ �Լ� ���ø� ȣ��
    For_each(sarr, sarr + 3, PrintFunctor<string>("*\n")); // s = "*\n" : �� ��¸��� * + �ٹٲ�. 
    cout << endl << endl;

    return 0;
}