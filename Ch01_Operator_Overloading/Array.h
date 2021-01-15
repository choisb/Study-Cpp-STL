#pragma once
#include <iostream>
using namespace std;

class Array
{
	int *arr;
	int size;
	int capacity;

public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}
	~Array()
	{
		delete[] arr;
	}

	void Add(int data)
	{
		if (size < capacity)
			arr[size++] = data;
	}

	int Size() const
	{
		return size;
	}

	int operator[] (int idx) const // ����� ��ȯ
	{
		return arr[idx];
	}

	int& operator[] (int idx) // L-Value ��ȯ
	{
		return arr[idx];
	}
};
