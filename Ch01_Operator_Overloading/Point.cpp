#include "Point.h"

//��ȯ Ÿ��: const Point
const Point Point::operator+(const Point& arg) const // �ڽ��� ����� �������� �ʴ� ��� �Լ��� ��� const ��� �Լ��� ������ ��.
{
	Point pt;
	pt.x = this->x + arg.x;
	pt.y = this->y + arg.y;

	return pt;
}

//��ȯ Ÿ��: const Point&
const Point& Point::operator++ ()	//���� ++ ������
{
	++x;
	++y;
	return *this;
}

//��ȯ Ÿ��: const Point
const Point Point::operator++ (int) // ���� ++ ������
{
	Point pt(x, y);
	++x;
	++y;
	return pt;
}

//��ȯ Ÿ��: const Point&
const Point& Point::operator-- ()	//���� -- ������
{
	--x;
	--y;
	return *this;
}

//��ȯ Ÿ��: const Point
const Point Point::operator-- (int) // ���� -- ������
{
	Point pt(x, y);
	--x;
	--y;
	return pt;
}

bool Point::operator==(const Point& arg) const
{
	return x == arg.x && y == arg.y ? true : false;
}
bool Point::operator!=(const Point& arg) const
{
	// �̹� ���ǵ� "==" �����ڸ� ���
	return !(*this == arg);
}

const Point operator*(const int k, const Point& argR)
{
	Point pt;
	pt.x = k * argR.x;
	pt.y = k * argR.y;

	return pt;
}