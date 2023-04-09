#include "Sorter.h"
#include <iostream>

void Sorter::bubbleSort(Person* data, int sizeOfData)
{
	Person p0;
	Person p1;

	for (int i = 0; i < sizeOfData; i++)
	{

		for (int n = 0; n < sizeOfData - 1; n++)
		{
			if (data[n].getID() > data[n + 1].getID())
			{
				p0 = data[n];
				p1 = data[n + 1];

				data[n] = p1;
				data[n + 1] = p0;

			}

		}
	}
}

void Sorter::insertSort(Person* data, int sizeOfData)
{
	Person p0;
	Person p1;

	for (int i = 0; i < sizeOfData; i++)
	{
		for (int n = 0; n < sizeOfData; n++)
		{
			if (data[i].getID() < data[n].getID())
			{
				p0 = data[i];
				p1 = data[n];

				data[n] = p0;
				data[i] = p1;
			}
		}
	}
}