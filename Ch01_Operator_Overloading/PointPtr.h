#pragma once
#include "Point.h"

class PointPtr
{
	Point *ptr;
public:
	PointPtr(Point *p) : ptr(p) 
	{
		cout << "PointPtr(Point *p): ptr(p) > " << ptr << endl;
	}
	~PointPtr()
	{
		cout << "~PointPtr(): delete ptr; > " << ptr << endl;
		delete ptr;
	}
	Point* operator->() const
	{
		cout << "operator->(): return ptr; > " << ptr << endl;
		return ptr;
	}
	Point& operator*() const // 반환 형식은 L-Value
	{
		cout << "operator*(): return *ptr; >" << ptr << endl;
		return *ptr;
	}
};
