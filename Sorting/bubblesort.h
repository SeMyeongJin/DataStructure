#pragma once
/*
정렬되지 않은 전체 자료들을 대상으로 인접한 두 개 자료의
키 값을 비교하여 위치를 교환하는 정렬 방식입니다.
*/


void bubbleSort(int value[], int count)
{
	int i = 0, j = 0;
	int temp = 0;

	for (i = count - 1; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (value[j + 1] < value[j])
			{
				temp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = temp;
			}
		}
	}
}