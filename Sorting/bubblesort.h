#pragma once
/*
���ĵ��� ���� ��ü �ڷ���� ������� ������ �� �� �ڷ���
Ű ���� ���Ͽ� ��ġ�� ��ȯ�ϴ� ���� ����Դϴ�.
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