#pragma once
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 10;

class ArrayException {};

class Array
{
	int* ptr;
	int size, capacity;

	int cyclicIndex(int index) const;

public:
	int& operator [] (int index);
	void insert(int elem, int index);
	void insert(int elem);
	void increaseCopacity(int newCapacity);
	void remove(int index);

	//int get(int index) const;
	//void set(int index, int elem);

	int getSize() const;
	friend ostream& operator << (ostream& out, const Array& arr);

	explicit Array(int startCapacity = DEFAULT_CAPACITY);

	~Array();
	Array(const Array& arr);
	Array& operator = (const Array& arr);
};