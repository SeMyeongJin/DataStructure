#pragma once
/*
퀵 정렬은 중심 값(피벗)을 기준으로 두 자료의 키 값을 비교하여
위치를 교환하는 정렬 방식입니다. 피벗 기준으로 위치 교환이 끝나면
피벗을 기준으로 2개의 부분 집합으로 나눕니다.
*/


int partitionQuickSort(int value[], int start, int end);

void quickSort(int value[], int start, int end)
{
	int pivot = 0;
	if (start < end)

	{
		pivot = partitionQuickSort(value, start, end);
		quickSort(value, start, pivot - 1);
		quickSort(value, pivot + 1, end);
	}
}

int partitionQuickSort(int value[], int start, int end)
{
	int pivot = 0;
	int temp = 0, left = 0, right = 0;

	left = start;
	right = end;
	pivot = end;
	while (left < right)
	{
		while (value[left] < value[pivot] && (left < right))
			left++;
		while (value[right] >= value[pivot] && (left < right))
			right--;

		if (left < right)
		{
			temp = value[left];
			value[left] = value[right];
			value[right] = temp;
		}
	}

	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	return right;
}