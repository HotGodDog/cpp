#include "Array.h"
#include <iostream>

using namespace std;

void arrayFilling(Array& arr, int size);
int JosephFlavelsTask(int size, int k);

int main()
{
	setlocale(LC_ALL, "RU");

	/*Array arr(4);
	cout << arr << endl;
	for (int i = 0; i < 4; i++)
		arr.insert(i + 1);
	cout << arr << endl;
	for (int i = 0; i < 8; i += 2)
		arr.insert(10 + i, i);
	cout << arr << endl;
	for (int i = 1; i < 8; i += 2)
		arr[i] = 20 + i;
	cout << arr << endl;
	for (int i = 6; i >= 0; i -= 3)
		arr.remove(i);
	cout << arr << endl;*/
	
	/*Array xxl;
	ArrayFilling(xxl, 4);
	cout << xxl << endl;*/

	cout << JosephFlavelsTask(100, 2) << endl;

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