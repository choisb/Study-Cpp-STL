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
void Print(T n)
{
    cout << n << " ";
}

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    string sarr[3] = { "abc", "ABC", "Hello" };

    // 정수 출력, 묵시적 함수 템플릿 호출
    For_each(arr, arr + 5, Print<int>);
    cout << endl;

    // 문자열 출력, 묵시적 함수 템플릿 호출
    For_each(sarr, sarr + 3, Print<string>); 
    cout << endl << endl;

    // 정수 출력, 명시적 함수 템플릿 호출
    For_each<int* , void(*)(int)>(arr, arr + 5, Print<int>); 
    cout << endl;

    // 문자열 출력, 명시적 함수 템플릿 호출
    For_each<string*, void(*)(string)>(sarr, sarr + 3, Print<string>); 
    cout << endl;

    return 0;
}