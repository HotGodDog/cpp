#include "LineList.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void listFilling(LineList<int>& list, int size);

int JosephFlavelsTask(int size, int k);

int main()
{
	setlocale(LC_ALL, "RU");

	ofstream file("data.csv");

	if (!file.is_open())
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

	file << "N,Ответ,Время расчета (сек.)\n";

	int N[7] = { 1000, 5000, 10000, 50000, 100000, 500000, 1000000 };

	for (int i = 0; i < 7; i++)
	{
		clock_t start = clock();
		file << N[i] << "," << JosephFlavelsTask(N[i], 2);
		clock_t end = clock();
		file << "," << double(end - start) / CLOCKS_PER_SEC << "\n";
		cout << i + 1 << " запись сделана\n";
	}

	file.close();

	cout << "Данные успешно записаны в файл" << endl;

	return 0;
}

void listFilling(LineList<int>& list, int size)
{
	list.insertFirst(1);

	LineListElem<int>* ptr = list.getLast();

	for (int i = 2; i <= size; i++)
	{
		list.insertAfter(ptr, i);
		ptr = ptr->getNext();
	}
}

int JosephFlavelsTask(int size, int k)
{
	LineList<int> list;

	listFilling(list, size);

	LineListElem<int>* ptr = list.getStart();

	while (ptr != ptr->getNext())
	{
		for (int i = 2; i < k; i++)
			ptr = ptr->getNext();
		
		list.deleteAfter(ptr);
		ptr = ptr->getNext();
	}

	return ptr->getData();
}