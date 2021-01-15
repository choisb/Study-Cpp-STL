#pragma once
#include <iostream>
using namespace std;

class Point
{
	friend const Point operator*(const int argL, const Point& argR);

	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // ����Ʈ �Ű�����, �ʱ�ȭ ���
	void Print() const { cout << x << ',' << y << endl; }

	//��ȯ Ÿ��: const Point
	const Point operator+(const Point& arg) const; // �ڽ��� ����� �������� �ʴ� ��� �Լ��� ��� const ��� �Լ��� ������ ��.


	//���� ������ �����ε�
	//��ȯ Ÿ��: const Point&
	const Point& operator++ ();	//���� ++ ������

	//��ȯ Ÿ��: const Point
	const Point operator++ (int); // ���� ++ ������

	//��ȯ Ÿ��: const Point&
	const Point& operator-- ();	//���� -- ������

	//��ȯ Ÿ��: const Point
	const Point operator-- (int); // ���� -- ������


	//���� ������ �����ε�
	bool operator==(const Point& arg) const;
	bool operator!=(const Point& arg) const;
};

//���� �Լ��� �̿��� ������ �����ε�
const Point operator*(const int argL, const Point& argR);