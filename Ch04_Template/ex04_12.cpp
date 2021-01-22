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
    string sep; // 출력 구분자 정보

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

    // 정수 출력, 묵시적 함수 템플릿 호출
    For_each(arr, arr + 5, PrintFunctor<int>());    // 디폴트 매개변수 s = " " 사용
    cout << endl;

    // 문자열 출력, 묵시적 함수 템플릿 호출
    For_each(sarr, sarr + 3, PrintFunctor<string>("*\n")); // s = "*\n" : 매 출력마다 * + 줄바꿈. 
    cout << endl << endl;

    return 0;
}