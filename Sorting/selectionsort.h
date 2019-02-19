#pragma once
/*
정렬되지 않은 전체 자료 중에서 해당 위치에 맞는 자료를 선택하여
위치를 교환하는 정렬 방식입니다.
*/

void selectionSort(int value[], int count)
{
	int i = 0, j = 0;
	int min = 0, temp = 0;

	for (i = 0; i < count - 1; i++)
	{
		min = i;
		for (j = i + 1; j < count; j++)
		{
			if (value[j] < value[min])
				min = j;
		}
		temp = value[i];
		value[i] = value[min];
		value[min] = temp;
	}
}