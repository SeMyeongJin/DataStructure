#pragma once

/*
���� �ڷᱸ���� �̿��Ͽ� �ڷḦ �����մϴ�
������ ���� ���� Ʈ���̸鼭 ���ÿ� �ִ� Ʈ�� Ȥ�� �ּ� Ʈ���Դϴ�.
������������ �����ϰ� ���� ��� �ּ� �������� ������ŭ ��Ʈ ��带 �����մϴ�.
���������� �ݴ�� �ִ� �������� ������ŭ ��Ʈ ��带 �����Ͽ� �����մϴ�.
*/

void heapSort(int value[], int count)
{
	int i = 0;
	ArrayMinHeap* pHeap = NULL;

	pHeap = createArrayMinHeap(count);
	if (pHeap != NULL)
	{
		HeapNode node;
		for (i = 0; i < count; i++)
		{
			node.key = value[i];
			insertMinHeapAH(pHeap, node);
		}
		for (i = 0; i < count; i++)
		{
			HeapNode* pNode = deleteMinHeapAH(pHeap);
			if (pNode != NULL)
			{
				value[i] = pNode->key;
				free(pNode);
			}
		}

		deleteArrayMinHeap(pHeap);
	}
}