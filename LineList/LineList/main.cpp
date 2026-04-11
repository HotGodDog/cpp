#include "LineList.h"

int main()
{
	setlocale(LC_ALL, "RU");

	LineList<int> list;

	cout << "Начало: " << list << endl;

	list.insertFirst(10);

	LineListElem<int>* ptr = list.getStart();

	list.insertAfter(ptr, 15);
	list.insertAfter(ptr->getNext(), 12);
	list.insertFirst(7);

	cout << "Шаг 1: " << list << endl;

	LineListElem<int>* last = list.getLast();
	list.insertAfter(last, 40);
	cout << "После вставки 40 в конец: " << list << endl;

	return 0;
}