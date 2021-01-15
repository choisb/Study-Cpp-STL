#include "PointPtr.h"
#include "Array.h"
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

	//void(*Print2) (int) = Print1;
	//FuncObject Print3;

	//Print1(10); // '�Լ�'�� ����� ���� ���
	//Print2(10); // '�Լ� ������'�� ����� ���� ���
	//Print3(10); // '�Լ� ��ü'�� ����� ���� ��� (Print3.operator(10)�� ����)


	//Array ar(10);
	//ar.Add(10);
	//ar.Add(20);
	//ar.Add(30);

	//for (int i = 0; i < ar.Size(); i++)
	//	cout << ar[i] << endl; //ar.operator[](int) ȣ��

	//const Array& ar2 = ar;
	//ar[0] = 40;	//ar.operator[](int) ȣ��
	//cout << ar2[0] << endl; //ar.operator[](int) const ȣ��
	////ar2[0] = 100; //����! ��� ��ü(��)�� ��ȯ�ϱ� ������ ������ �� ����.


	Point* ptr = new Point(2, 3);
	PointPtr p1 = ptr; //PointPtr p1(ptr); �� ���� ǥ���ε�?

	// Point* ptr = new Point(4, 5);
	// PointPtr p2 = ptr;
	// �� �� ���� �Ʒ��� ���� ǥ���� ���� �ִ�.    
	PointPtr p2 = new Point(4, 5);


	p1->Print(); //p1.operator->() -> Print() ȣ��
	p2->Print(); //p2.operator->() -> Print() ȣ��

	//p2�� �Ҹ��ڿ��� Point ���� ��ü�� �ڵ����� �޸𸮿��� ����
	//p1�� �Ҹ��ڿ��� Point ���� ��ü�� �ڵ����� �޸𸮿��� ����

	return 0;
}