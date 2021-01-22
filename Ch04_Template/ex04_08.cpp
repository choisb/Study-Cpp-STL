#include <iostream>
#include <string>   // 문자열 string 클래스 헤더
using namespace std;

template<typename T = int, int capT = 100>  // T = 100 / capT = 100 으로 디폴트값 설정
class Array
{
    T *buf;
    int size; // 원소의 개수
    int capacity; // 저장 가능한 메모리 크기
public:
    explicit Array(int cap = capT) : buf(0), size(0), capacity(cap)
    {
        buf = new T[capacity];
    }
    ~Array() { delete[] buf; }

    void Add(T data)
    {
        buf[size++] = data;
    }

    T operator[] (int idx) const
    {
        return buf[idx];
    }

    int GetSize() const
    {
        return size;
    }
    // 나머지 인터페이스 생략...
};
int main()
{
    Array<> iarr; // 디폴트 매개변수 값 T = int, capT = 100 사용.

    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);

    for (int i = 0; i < iarr.GetSize(); i++)
        cout << iarr[i] << endl;
    cout << endl;

    Array<double> darr; // 디폴트 매개변수 capT = 100 사용.

    darr.Add(10.12);
    darr.Add(20.12);
    darr.Add(30.12);

    for (int i = 0; i < darr.GetSize(); i++)
        cout << darr[i] << endl;
    cout << endl;

    Array<string, 10> sarr; // 디폴트 매개변수 값 사용하지 않음.

    sarr.Add("abc");
    sarr.Add("ABC");
    sarr.Add("Hello");

    for (int i = 0; i < sarr.GetSize(); i++)
        cout << sarr[i] << endl;
    cout << endl;

    return 0;
}