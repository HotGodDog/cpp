#pragma once
#include<iostream>

using namespace std;

class LineListException {};

template <class T> class LineListElem
{
	T data;
	LineListElem* next;

public:
	LineListElem(const T& adata, LineListElem* anext);
	const T& getData() const;
	LineListElem* getNext();
	template <class T> friend class LineList;
};


template <class T> class LineList
{
	LineListElem<T>* start;
	LineList(const LineList& list);
	LineList& operator = (const LineList& list);

public:
	LineList();
	~LineList();

	LineListElem<T>* getStart();
	LineListElem<T>* getLast();

	void deleteFirst();
	void deleteAfter(LineListElem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListElem<T>* ptr, const T& data);

	friend ostream& operator << (ostream& out, LineList<T>& list)
	{
		LineListElem<T>* ptr = list.start;

		if (!ptr)
			out << "EMPTY ";

		else do
		{
			out << ptr->getData() << ' ';
			ptr = ptr->getNext();
		} while (ptr != list.start);

		return out;
	}
};


template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
	data = adata;
	next = anext;
}
template <class T> const T& LineListElem<T>::getData() const
{
	return data;
}
template <class T> LineListElem<T>* LineListElem<T>::getNext()
{
	return next;
}


template <class T> LineList<T>::LineList()
{
	start = 0;
}
template <class T> LineList<T>::~LineList()
{
	while (start)
		deleteFirst();
}

template <class T> LineListElem<T>* LineList<T>::getStart()
{
	return start;
}
template <class T> LineListElem<T>* LineList<T>::getLast()
{
	if (!start)
		return start;

	LineListElem<T>* ptr = start;
	while (ptr->next != start)
		ptr = ptr->next;

	return ptr;
}

template <class T> void LineList<T>::deleteFirst()
{
	if (!start)
		throw LineListException();

	if (start->next == start)
	{
		delete start;
		start = 0;
	}
	else
	{
		LineListElem<T>* last = getLast();
		LineListElem<T>* first = start->next;
		last->next = first;
		delete start;
		start = first;
	}
}
template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr)
{
	if (!ptr || ptr->next == ptr)
		throw LineListException();

	if (ptr->next == start)
	{
		LineListElem<T>* last = getLast();
		LineListElem<T>* temp = start->next;
		last->next = temp;
		delete start;
		start = temp;
		ptr->next = start;
	}
	else
	{
		LineListElem<T>* temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
	}
}
template <class T> void LineList<T>::insertFirst(const T& data)
{
	if (!start)
	{
		start = new LineListElem<T>(data, 0);
		start->next = start;
	}
	else
	{
		LineListElem<T>* last = getLast();
		LineListElem<T>* first = new LineListElem<T>(data, start);
		last->next = first;
		start = first;
	}

}
template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data)
{
	if (ptr)
	{
		LineListElem<T>* temp = new LineListElem<T>(data, ptr->next);
		ptr->next = temp;
	}
}

