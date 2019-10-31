#pragma once
/*
�� ������ �߽� ��(�ǹ�)�� �������� �� �ڷ��� Ű ���� ���Ͽ�
��ġ�� ��ȯ�ϴ� ���� ����Դϴ�. �ǹ� �������� ��ġ ��ȯ�� ������
�ǹ��� �������� 2���� �κ� �������� �����ϴ�.
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