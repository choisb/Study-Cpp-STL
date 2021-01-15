#include "Point.h"

struct FuncObject
{
public:
	void operator() (int arg) const
	{
		cout << " ���� : " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << " ���� : " << arg << endl;
}

int main()
{
	//Point p1(2, 3), p2(5, 5);

	//p1 + p2; // => p1.operator+(p2); �� ����
	//p1 * p2; // => p1.operator*(p2); �� ����
	//p1 = p2; // => p1.operator=(p2); �� ����
	//p1 == p2; // => p1.operator==(p2); �� ����
	//p1 += p2; // => p1.operator+=(p2); �� ����

	//++p1; //p1.operator++();�� ����
	//p2++; //p2.operator++(0);�� ����. ��������� operator++() ��� �Լ� ȣ�� �� �ǹ� ����(dummy) ������ ���� 0�� �����Ѵ�.

	//Point result;

	//result = ++p1;
	//p1.Print();
	//result.Print();

	//result = p2++;
	//p2.Print();
	//result.Print();

	//Point p3(2, 3);

	//if (p1 != p2)
	//	cout << " p1 != p2" << endl;
	//if (p1 != p3)
	//	cout << " p1 != p3" << endl;

	//Point p1(2, 3);
	//Point result;

	//result = 2 * p1;
	//result.Print();

	void(*Print2) (int) = Print1;
	FuncObject Print3;

	Print1(10); // '�Լ�'�� ����� ���� ���
	Print2(10); // '�Լ� ������'�� ����� ���� ���
	Print3(10); // '�Լ� ��ü'�� ����� ���� ��� (Print3.operator(10)�� ����)

	return 0;
}