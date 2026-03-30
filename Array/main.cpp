#include "Array.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void arrayFilling(Array& arr, int size);

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

	file << "N;Ответ;Время расчета (сек.)\n";

	int N[7] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};

	for (int i = 0; i < 7; i++)
	{
		clock_t start = clock();
		file << N[i] << ";" << JosephFlavelsTask(N[i], 2);
		clock_t end = clock();
		file << ";" << double(end - start) / CLOCKS_PER_SEC << "\n";
		cout << i + 1 << " запись сделана\n";
	}
	
	file.close();
	
	cout << "Данные успешно записаны в файл" << endl;

	return 0;
}

void arrayFilling(Array& arr, int size)
{
	for (int i = 0; i < size; i++)
		arr.insert(i + 1);
}

int JosephFlavelsTask(int size, int k)
{
	Array arr;
	arrayFilling(arr, size);

	int i = 0;
	while (arr.getSize() > 1)
	{
		i = (i + k - 1) % arr.getSize();
		arr.remove(i);
	}

	return arr[0];
}